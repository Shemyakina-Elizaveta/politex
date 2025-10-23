#include "matrix.h"

Matrix::~Matrix( void )
{
  if (data == nullptr)
    return;

  for (int i = 0; i < H; i++)
    delete[] data[i];

  delete[] data;
}

Matrix::Matrix( int n )
{
  W = n, H = n;

  if (H == 0)
    return;

  data = new double *[H];

  for (int i = 0; i < H; i++)
  {
    data[i] = new double[W];

    for (int j = 0; j < W; j++)
      data[i][j] = (i == j);
  }
}

Matrix::Matrix( int NH, int NW, double fill_value )
{
  H = NH;
  W = NW;

  if (H == 0 || W == 0)
    return;

  data = new double *[H];

  for (int i = 0; i < H; i++)
  {
    data[i] = new double[W];

    for (int j = 0; j < W; j++)
      data[i][j] = fill_value;
  }
}

Matrix::Matrix( const Matrix &M )
{
  for (int i = 0; i < H; i++)
    delete[] data[i];
  delete[] data;

  data = nullptr;

  W = M.W;
  H = M.H;

  if (W == 0 || H == 0)
    return;

  data = new double *[H];

  for (int i = 0; i < H; i++)
  {
    data[i] = new double[W];

    for (int j = 0; j < W; j++)
      data[i][j] = M.data[i][j];
  }
}

Matrix::Matrix( Matrix &&other ) noexcept : H(other.H), W(other.W), data(other.data)
{
  other.data = nullptr;
  other.W = 0;
  other.H = 0;
}

Matrix & Matrix::operator=( Matrix &&other ) noexcept
{
  if (this != &other)
  {
    for (int i = 0; i < H; i++)
      delete[] data[i];

    delete[] data;

    data = other.data;
    W = other.W;
    H = other.H;

    other.data = nullptr;
    other.W = 0;
    other.H = 0;
  }
  return *this;
}


Matrix & Matrix::operator=( const Matrix &M )
{
  if (this != &M)
  {
    if (data == M.data)
      return *this;

    for (int i = 0; i < H; i++)
      delete[] data[i];
    delete[] data;

    data = nullptr;

    W = M.W;
    H = M.H;

    if (H == 0 || W == 0)
      return *this;

    data = new double *[H];

    for (int i = 0; i < H; i++)
    {
      data[i] = new double[W];

      for (int j = 0; j < W; j++)
        data[i][j] = M.data[i][j];
    }
  }

  return *this;
}

Matrix & Matrix::operator+=( const Matrix &M )
{
  if (data == nullptr || M.data == nullptr || M.W == 0 || M.H == 0 || M.W != W || M.H != H)
    throw;

  for (int j = 0; j < H; j++)
    for (int i = 0; i < W; i++)
      data[j][i] += M.data[j][i];

  return *this;
}

Matrix & Matrix::operator-=( const Matrix &M )
{
  if (data == nullptr || M.data == nullptr || M.W == 0 || M.H == 0 || M.W != W || M.H != H)
    throw;

  for (int j = 0; j < H; j++)
    for (int i = 0; i < W; i++)
      data[j][i] -= M.data[j][i];

  return *this;
}

Matrix & Matrix::operator*=( const double num )
{
  if (data == nullptr)
    throw;

  for (int j = 0; j < H; j++)
    for (int i = 0; i < W; i++)
      data[j][i] *= num;

  return *this;
}

Matrix & Matrix::operator/=( const double num )
{
  if (data == nullptr || num == 0)
    throw;

  for (int j = 0; j < H; j++)
    for (int i = 0; i < W; i++)
      data[j][i] /= num;

  return *this;
}

Matrix Matrix::operator+( const Matrix &M ) const
{
  if (data == nullptr || M.data == nullptr || M.W == 0 || M.H == 0 || M.W != W || M.H != H)
    throw;

  Matrix R(H, W);

  for (int j = 0; j < H; j++)
    for (int i = 0; i < W; i++)
      R.data[j][i] = data[j][i] + M.data[j][i];

  return R;
}

Matrix Matrix::operator-( const Matrix &M ) const
{
  if (data == nullptr || M.data == nullptr || M.W == 0 || M.H == 0 || M.W != W || M.H != H)
    throw;

  Matrix R(H, W);

  for (int j = 0; j < H; j++)
    for (int i = 0; i < W; i++)
      R.data[j][i] = data[j][i] - M.data[j][i];

  return R;
}

Matrix Matrix::operator*( const Matrix &M ) const
{
  if (data == nullptr || M.data == nullptr || H != M.W)
    throw;

  Matrix R(H, M.W);

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < M.W; j++)
    {
      for (int k = 0; k < M.H; k++)
        R.data[i][j] += data[i][k] * M.data[k][j];
    }
  }

  return R;
}

Matrix Matrix::operator*( const double num ) const
{
  if (data == nullptr)
    return Matrix();

  Matrix R(H, W);

  for (int j = 0; j < H; j++)
    for (int i = 0; i < W; i++)
      R.data[j][i] = data[j][i] * num;

  return R;
}

Matrix Matrix::operator/( const double num ) const
{
  if (num == 0)
    throw;

  if (data == nullptr)
    return Matrix();

  Matrix R(H, W);

  for (int j = 0; j < H; j++)
    for (int i = 0; i < W; i++)
      R.data[j][i] = data[j][i] / num;

  return R;

}

Matrix operator*( const double num, const Matrix &M )
{
  if (M.data == nullptr)
    return Matrix();

  int H = M.H, W = M.W;
  Matrix R(H, W);
  double **data1 = M.data, **data2 = R.data;

  for (int j = 0; j < H; j++)
    for (int i = 0; i < W; i++)
      data2[j][i] = data1[j][i] * num;

  return R;
}

Matrix operator-( const Matrix &M )
{
  if (M.data == nullptr)
    return Matrix();

  int H = M.H, W = M.W;
  Matrix R(H, W);
  double **data1 = M.data, **data2 = R.data;

  for (int j = 0; j < H; j++)
    for (int i = 0; i < W; i++)
      data2[j][i] = -data1[j][i];

  return R;
}

/*
double ** Matrix::get( void ) const
{
  return data;
}
*/
double Matrix::get( int i, int j ) const
{
  if (i < 0 || j < 0 || i > H || j > W)
    throw;

  return data[i][j];
}

void Matrix::set( int i, int j, int new_value )
{
  if (i < 0 || j < 0 || i > H || j > W)
    throw;

  data[i][j] = new_value;
}

int Matrix::get_height( void ) const
{
  return H;
}

int Matrix::get_width( void ) const
{
  return W;
}

void Matrix::negate( void )
{
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      data[i][j] = -data[i][j];
}

void Matrix::add_in_place( Matrix &other )
{
  if (other.data == nullptr || other.H != H || other.W != W)
    throw;

  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      data[i][j] += other.data[i][j];
}

Matrix Matrix::multiply( Matrix &other )
{
  if (other.data == nullptr || W != other.H)
    throw;

  Matrix res(H, other.W, 0);

  for (int i = 0; i < H; i++)
    for (int j = 0; j < other.W; j++)
      for (int k = 0; k < other.H; k++)
        res.data[i][j] += data[i][k] * other.data[k][j];

  return res;
}
