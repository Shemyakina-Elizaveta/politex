#ifndef __matrix_h__
#define __matrix_h__

#include <iostream>
#include <stdlib.h>

class Matrix
{
  int W, H;
  double **data;

public:
  Matrix( void ) : W(0), H(0), data(nullptr) {};

  ~Matrix( void )
  {
    if (data == nullptr)
      return;

    for (int i = 0; i < H; i++)
      delete[] data[i];

    delete[] data;
  }

  Matrix( int n )
  {
    W = n, H = n;

    data = new double *[H];

    for (int i = 0; i < H; i++)
    {
      data[i] = new double[W];

      for (int j = 0; j < W; j++)
        data[i][j] = (i == j);
    }
  }

  Matrix( int NH, int NW, double fill_value = 0 )
  {
    H = NH;
    W = NW;

    data = new double *[H];

    for (int i = 0; i < H; i++)
    {
      data[i] = new double[W];

      for (int j = 0; j < W; j++)
        data[i][j] = fill_value;
    }
  }

  Matrix( const Matrix &M )
  {
    if (M.data == nullptr || M.W == 0 || M.H == 0)
      throw;

    for (int i = 0; i < H; i++)
      delete[] data[i];
    delete[] data;

    W = M.W;
    H = M.H;

    data = new double *[H];

    for (int i = 0; i < H; i++)
    {
      data[i] = new double[W];

      for (int j = 0; j < W; j++)
        data[i][j] = M.data[i][j];
    }
  }

  Matrix & operator=( const Matrix &M )
  {
    if (M.data == nullptr || M.W == 0 || M.H == 0)
      throw;

    for (int i = 0; i < H; i++)
      delete[] data[i];
    delete[] data;

    W = M.W;
    H = M.H;

    data = new double *[H];

    for (int i = 0; i < H; i++)
    {
      data[i] = new double[W];

      for (int j = 0; j < W; j++)
        data[i][j] = M.data[i][j];
    }

    return *this;
  }

  double get( int i, int j )
  {
    if (i < 0 || j < 0 || i > H || j > W)
      throw;

    return data[i][j];
  }

  void set( int i, int j, int new_value )
  {
    if (i < 0 || j < 0 || i > H || j > W)
      throw;

    data[i][j] = new_value;
  }

  int get_height( void )
  {
    return H;
  }

  int get_width( void )
  {
    return W;
  }

  void negate( void )
  {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)
        data[i][j] = -data[i][j];
  }

  void add_in_place( Matrix &other )
  {
    if (other.data == nullptr || other.H != H || other.W != W)
      throw;

    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)
        data[i][j] += other.data[i][j];
  }

  Matrix multiply( Matrix &other )
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
};

#endif /* __matrix_h__ */