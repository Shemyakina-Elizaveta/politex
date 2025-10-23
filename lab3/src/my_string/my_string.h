#ifndef __my_string_h__
#define __my_string_h__

#include <iostream>
#include <stdlib.h>
#include <string.h>

class MyString
{
  char *data = nullptr;
  int length = 0;
  int capacity = 0;

public:

  MyString( void ) {}

  ~MyString( void )
  {
    if (data == nullptr)
      return;

    delete[] data;
  }


  MyString( const char *str );
  MyString( const MyString &MStr );

  MyString( MyString &&other ) noexcept;
  MyString & operator=( MyString &&other ) noexcept;

  MyString & operator=( const char *str );
  MyString & operator=( const MyString &MStr );

  MyString & operator+=( const MyString &MStr );
  MyString & operator+=( const char *str );

  MyString operator+( const MyString &MStr ) const;
  MyString operator+( const char *str ) const;

  bool operator==( const MyString &MStr ) const;
  bool operator!=( const MyString &MStr ) const;
  bool operator<( const MyString &MStr ) const;
  bool operator<=( const MyString &MStr ) const;

  bool operator==( const char *str ) const;
  bool operator!=( const char *str ) const;
  bool operator<( const char *str ) const;
  bool operator<=( const char *str ) const;

  friend bool operator==( const char *str, const MyString &MStr );
  friend bool operator!=( const char *str, const MyString &MStr );
  friend bool operator<( const char *str, const MyString &MStr );
  friend bool operator<=( const char *str, const MyString &MStr );

  char & operator[]( unsigned int i ) const;

  friend std::ostream & operator<<( std::ostream &os, const MyString &MStr );
  friend std::istream & operator>>( std::istream &is, MyString &MStr );

  char * get_pointer( void );
  void set( int i, char c );
  void set_new_string( const char *str );
  void print( void );
  int get_length( void );
  void read_line( void );

  friend MyString operator+( const char *str, const MyString &MStr );
};


// MyString operator+( const char *str, const MyString &MStr );

// bool operator==( const char *str, const MyString &MStr );
// bool operator!=( const char *str, const MyString &MStr );
// bool operator<( const char *str, const MyString &MStr );
// bool operator<=( const char *str, const MyString &MStr );


#endif /* __my_string_h__ */