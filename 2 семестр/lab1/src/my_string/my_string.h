#ifndef __my_string_h__
#define __my_string_h__

#include <iostream>
#include <stdlib.h>
#include <string.h>

class MyString
{
  char *data = nullptr;
  int length;
  int capacity;

public:

  MyString( void )
  {
    length = 0;
    capacity = 1;
    data = new char[capacity];
    /* aaaaaaaaaaa */
  }

  ~MyString( void )
  {
    if (data == nullptr)
      return;

    delete[] data;
  }

  MyString( const char *str )
  {
    if (str == nullptr)
      throw;

    if (data != nullptr)
      delete[] data;

    length = (int)strlen(str);
    capacity = length + 1;

    data = new char[capacity] {};

    for (int i = 0; i < length; i++)
      data[i] = str[i];

    data[length] = '\0';
  }

  MyString( const MyString &MStr )
  {
    if (MStr.data == nullptr)
      throw;

    if (data != nullptr)
      delete[] data;

    length = MStr.length;
    capacity = MStr.capacity + 1;

    data = new char[capacity] {};

    for (int i = 0; i < length; i++)
      data[i] = MStr.data[i];

    data[length] = '\0';
  }

  MyString & operator=( const MyString &MStr )
  {
    if (MStr.data == nullptr)
      throw;

    if (data != nullptr)
      delete[] data;

    length = MStr.length;
    capacity = MStr.capacity + 1;

    data = new char[capacity] {};

    for (int i = 0; i < length; i++)
      data[i] = MStr.data[i];

    data[length] = '\0';

    return *this;
  }

  char get( int i )
  {
    if (i < 0 || i > length || data == nullptr)
      throw;

    return data[i];
  }

  char * get_pointer( void )
  {
    return data;
  }

  void set( int i, char c )
  {
    if (i < 0 || i > length || data == nullptr)
      throw;

    data[i] = c;
  }

  void set_new_string( const char *str )
  {
    if (str == nullptr)
      throw;

    if (data != nullptr)
      delete[] data;

    length = (int)strlen(str);
    capacity = length + 1;

    data = new char[capacity] {};

    for (int i = 0; i < length; i++)
      data[i] = str[i];

    data[length] = '\0';
  }

  void print( void )
  {
    if (data == nullptr)
      return;

    for (int i = 0; i < length; i++)
      std::cout << data[i];

    std::cout << '\n';
  }

  int get_length( void )
  {
    return length;
  }

  void read_line( void );
};


#endif /* __my_string_h__ */