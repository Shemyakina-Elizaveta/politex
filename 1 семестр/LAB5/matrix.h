#pragma once

#include <iostream>

struct Matrix
{
  int N, M;
  double **data;

  Matrix( void )
  {
    M = 0;
    M = 0;
    data = nullptr;
  }
};

void m_free( Matrix *A );
void m_zero( Matrix *A, int M, int N );
void m_id( Matrix *A, int N );
void m_copy( const Matrix *src, Matrix *dst );
int m_width( const Matrix *A );
int m_height( const Matrix *A );
double m_get( const Matrix *A, int i, int j );
void m_set( Matrix *A, int i, int j, double value );

int m_add( Matrix *A, const Matrix *B );
void m_neg( Matrix *A );
int m_mult( const Matrix *A, const Matrix *B, Matrix *dst );

