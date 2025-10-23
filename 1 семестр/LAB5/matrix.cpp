#include "matrix.h"


void m_free( Matrix *A )
{
  if (A == nullptr || A->data == nullptr)
    return;

  for (int i = 0; i < A->M; i++)
    delete[] A->data[i];
  delete[] A->data;
  A->data = nullptr;
}

void m_zero( Matrix *A, int M, int N )
{
  if (A == nullptr)
    return;

  if (A->data != nullptr)
    m_free(A);

  A->M = M;
  A->N = N;

  A->data = new double *[A->M];
  for (int i = 0; i < A->M; i++)
  {
    A->data[i] = new double[A->N];

    for (int j = 0; j < A->N; j++)
      A->data[i][j] = 0;
  }
}

void m_id( Matrix *A, int N )
{
  if (A == nullptr)
    return;

  if (A->data != nullptr)
    m_free(A);

  A->M = A->N = N;

  A->data = new double *[N];
  for (int i = 0; i < A->M; i++)
  {
    A->data[i] = new double[A->N];

    for (int j = 0; j < A->N; j++)
    {
      A->data[i][j] = 0;
      if (i == j)
        A->data[i][j] = 1;
    }
  }
}

void m_copy( const Matrix *src, Matrix *dst )
{
  if (src == nullptr || src->data == nullptr || dst == nullptr)
    return;

  if (dst->data != nullptr)
    m_free(dst);

  dst->M = src->M;
  dst->N = src->N;

  m_zero(dst, dst->M, dst->N);

  for (int i = 0; i < dst->M; i++)
    for (int j = 0; j < dst->N; j++)
      dst->data[i][j] = src->data[i][j];
}

int m_width( const Matrix *A )
{
  if (A == nullptr)
    return 0;
  return A->N;
}

int m_height( const Matrix *A )
{
  if (A == nullptr)
    return 0;
  return A->M;
}

double m_get( const Matrix *A, int i, int j )
{
  if (A == nullptr || A->data == nullptr || i < 0 || i >= A->M || j < 0 || j >= A->N)
    return 0;
  return A->data[i][j];
}

void m_set( Matrix *A, int i, int j, double value )
{
  if (A == nullptr || A->data == nullptr || i < 0 || i >= A->M || j < 0 || j >= A->N)
    return;
  A->data[i][j] = value;
}
/*
     * - int m_add(Matrix *A, const Matrix *B) - если A и B одинакового
     *   размера, то прибавляет к A значения B и возвращает 0; иначе возвращает
     *   1.
     * - void m_neg(Matrix *A) - заменяет все элементы матрицы A на
     *   противоположные.
     * - int m_mult(const Matrix *A, const Matrix *B, Matrix *dst) - умножает
     *   матрицу A на матрицу B и сохраняет результат в dst. Если размеры
     *   матрицы не позволяют умножить матрицы, функция возвращает 1, иначе 0.
*/

int m_add( Matrix *A, const Matrix *B )
{
  if (A == nullptr || A->data == nullptr || B == nullptr || B->data == nullptr)
    return 1;

  if (A->M != B->M || A->N != B->N)
    return 1;

  for (int i = 0; i < A->M; i++)
    for (int j = 0; j < A->N; j++)
      A->data[i][j] += B->data[i][j];
  return 0;
}

void m_neg( Matrix *A )
{
  if (A == nullptr || A->data == nullptr)
    return;

  for (int i = 0; i < A->M; i++)
    for (int j = 0; j < A->N; j++)
      A->data[i][j] = -A->data[i][j];
}

int m_mult( const Matrix *A, const Matrix *B, Matrix *dst )
{
  if (A->N != B->M)
    return 1;

  m_free(dst);
  m_zero(dst, A->M, B->N);

  for (int i = 0; i < A->M; i++)
    for (int j = 0; j < B->N; j++)
      for (int k = 0; k < A->N; k++)
        dst->data[i][j] += A->data[i][k] * B->data[k][j];
  return 0;
}
