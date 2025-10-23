#include "bool_array.h"


BoolArray::BitReference::BitReference( unsigned char &byte, size_t pos ) : byte(byte), mask(1 << (pos % 8)) {}


size_t BoolArray::calculate_bytes( size_t bits )
{
  return (bits + 7) / 8;
}


BoolArray::BitReference::operator bool( void ) const
{
  return (byte & mask) != 0;
}


BoolArray::BitReference & BoolArray::BitReference::operator=( bool value )
{
  if (value)
    byte |= mask;
  else
    byte &= ~mask;

  return *this;
}

BoolArray::BitReference & BoolArray::BitReference::operator=( const BitReference &other )
{
  *this = static_cast<bool>(other);
  return *this;
}


BoolArray::BoolArray( size_t size, bool value ) : bits_count(size), bytes_count(calculate_bytes(size))
{
  data = new unsigned char[bytes_count];
  unsigned char pattern = value ? 0xFF : 0x00;
  for (size_t i = 0; i < bytes_count; ++i)
    data[i] = pattern;
}


BoolArray::BoolArray( const BoolArray &other ) : bits_count(other.bits_count), bytes_count(other.bytes_count)
{
  data = new unsigned char[bytes_count];
  for (size_t i = 0; i < bytes_count; ++i)
    data[i] = other.data[i];
}


BoolArray::~BoolArray( void )
{
  if (data != nullptr)
    delete[] data;
}


BoolArray & BoolArray::operator=( const BoolArray &other )
{
  if (this != &other)
  {
    delete[] data;
    bits_count = other.bits_count;
    bytes_count = other.bytes_count;
    data = new unsigned char[bytes_count];
    for (size_t i = 0; i < bytes_count; ++i)
      data[i] = other.data[i];
  }

  return *this;
}


size_t BoolArray::size() const
{
  return bits_count;
}


BoolArray::BitReference BoolArray::operator[]( size_t pos )
{
  if (pos >= bits_count)
    throw;
  return BitReference(data[pos / 8], pos);
}


bool BoolArray::operator[]( size_t pos ) const
{
  if (pos >= bits_count)
    throw;
  return (data[pos / 8] & (1 << (pos % 8)));
}


void BoolArray::resize( size_t new_size, bool value )
{
  size_t new_bytes = calculate_bytes(new_size);
  unsigned char *new_data = new unsigned char[new_bytes];

  size_t min_bytes = (bytes_count < new_bytes) ? bytes_count : new_bytes;
  size_t min_bits = (bits_count < new_size) ? bits_count : new_size;

  for (size_t i = 0; i < min_bytes; ++i)
    new_data[i] = data[i];

  unsigned char pattern = value ? 0xFF : 0x00;
  for (size_t i = min_bytes; i < new_bytes; ++i)
    new_data[i] = pattern;


  if (new_size > bits_count && bits_count % 8 != 0)
  {
    unsigned char mask = 0xFF << (bits_count % 8);

    if (value)
      new_data[min_bytes - 1] |= mask;
    else
      new_data[min_bytes - 1] &= ~mask;
  }

  delete[] data;
  data = new_data;
  bits_count = new_size;
  bytes_count = new_bytes;
}