#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cassert>
#include <cstdarg>

#define VAR_ARGS(...) var_args(__VA_ARGS__, 0)

int inc_by_value( int val );
int inc_by_pointer( int *val );
int inc_by_reference( int &val );

void swap( int *x, int *y );
void swap( int &x, int &y );

int find_min( const int *A, const int N );
int find_min( const int * const *A, const int N, const int M );

int my_str_cmp( const char *str1, const char *str2 );

int day_of_year( int day, int month, int year, int (* MIY)[12] );
int day_of_month( int day, int year, int &month, int (* MIY)[12] );

void add_unique( int * &ar, int &n, int new_value );
void print_array( const int *ar, const int n );

int sum_int( int N );

int encoded32_size( int raw_size );
int decoded32_size( int encode_size );
int encode32( const char *raw_data, int raw_size, char *dst );
int decode32( const char *encoded_data, int encoded_size, char *dst );

void var_args( int n1, ... );

int *my_min( int *ar, int size );