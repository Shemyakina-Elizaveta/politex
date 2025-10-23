#ifndef __matrix_h__
#define __matrix_h__

#include <iostream>
#include <stdlib.h>

class Matrix
{
  int W = 0, H = 0;
  double **data = nullptr;

public:
  Matrix( void ) : W(0), H(0), data(nullptr) {};
  ~Matrix( void );
  Matrix( int n );
  Matrix( int NH, int NW, double fill_value = 0 );
  Matrix( const Matrix &M );

  Matrix( Matrix &&other ) noexcept;
  Matrix & operator=( Matrix &&other ) noexcept;

  Matrix & operator=( const Matrix &M );
  Matrix & operator+=( const Matrix &M );
  Matrix & operator-=( const Matrix &M );
  Matrix & operator*=( const double num );
  Matrix & operator/=( const double num );

  Matrix operator+( const Matrix &M ) const;
  Matrix operator-( const Matrix &M ) const;
  Matrix operator*( const Matrix &M ) const;
  Matrix operator*( const double num ) const;
  Matrix operator/( const double num ) const;


  // double ** get( void ) const;
  double get( int i, int j ) const;
  void set( int i, int j, int new_value );
  int get_height( void ) const;
  int get_width( void ) const;
  void negate( void );
  void add_in_place( Matrix &other );
  Matrix multiply( Matrix &other );

  friend Matrix operator*( const double num, const Matrix &M );
  friend Matrix operator-( const Matrix &M );
};


// Matrix operator*( const double num, const Matrix &M );
// Matrix operator-( const Matrix &M );

#endif /* __matrix_h__ */