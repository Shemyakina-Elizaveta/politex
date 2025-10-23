#ifndef __bool_array_h__
#define __bool_array_h__

#include <iostream>

class BoolArray
{
private:
  unsigned char *data;
  size_t bits_count;
  size_t bytes_count;

  static size_t calculate_bytes( size_t bits );

  class BitReference
  {
  private:
    unsigned char &byte;
    unsigned char mask;

  public:
    BitReference( unsigned char &byte, size_t pos );
    operator bool( void ) const;
    BitReference & operator=( bool value );
    BitReference & operator=( const BitReference &other );
  };

public:
  BoolArray( size_t size, bool value = false );
  BoolArray( const BoolArray &other );
  ~BoolArray( void );

  BoolArray & operator=( const BoolArray &other );
  size_t size( void ) const;
  BitReference operator[]( size_t pos );
  bool operator[]( size_t pos ) const;
  void resize( size_t new_size, bool value = false );
};

#endif // __bool_array_h__