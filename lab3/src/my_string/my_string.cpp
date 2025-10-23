#include "my_string.h"


MyString::MyString( const char *str )
{
  if (str == nullptr)
    return;

  if (data != nullptr)
    delete[] data;
  data = nullptr;

  length = (int)strlen(str);
  capacity = length + 1;

  data = new char[capacity] {};

  for (int i = 0; i < length; i++)
    data[i] = str[i];

  data[length] = '\0';
}

MyString::MyString( const MyString &MStr )
{
  if (data != nullptr)
    delete[] data;
  data = nullptr;

  length = MStr.length;
  capacity = MStr.capacity;

  data = new char[capacity] {};

  for (int i = 0; i < length; i++)
    data[i] = MStr.data[i];

  data[length] = '\0';
}


MyString::MyString( MyString &&other ) noexcept : data(other.data), length(other.length)
{
  other.data = nullptr;
  other.length = 0;
}

MyString & MyString::operator=( MyString &&other ) noexcept
{
  if (this != &other)
  {
    if (data != nullptr)
      delete[] data;
    data = other.data;
    length = other.length;
    
    other.data = nullptr;
    other.length = 0;
  }
  return *this;
}


MyString & MyString::operator=( const char *str )
{
  if (str == nullptr)
    return *this;

  if (data != nullptr)
    delete[] data;

  length = (int)strlen(str);
  capacity = length + 1;

  data = new char[capacity] {};

  for (int i = 0; i < length; i++)
    data[i] = str[i];

  data[length] = '\0';

  return *this;
}

MyString & MyString::operator=( const MyString &MStr )
{
  if (this != &MStr)
  {
    if (data != nullptr && strcmp(data, MStr.data) == 0)
      return *this;

    if (data != nullptr)
      delete[] data;

    length = MStr.length;
    capacity = MStr.capacity;

    data = new char[capacity] {};

    for (int i = 0; i < length; i++)
      data[i] = MStr.data[i];

    data[length] = '\0';
  }

  return *this;
}


MyString & MyString::operator+=( const MyString &MStr )
{
  if (MStr.length == 0)
    return *this;

  if (length + MStr.length < capacity)
  {
    for (int i = 0; i < MStr.length; i++)
      data[i + length] = MStr.data[i];

    length += MStr.length;

    data[length] = '\0';
  }
  else
  {
    char *new_data = new char[length + MStr.length + 1];

    for (int i = 0; i < length; i++)
      new_data[i] = data[i];

    for (int i = 0; i < MStr.length; i++)
      new_data[i + length] = MStr.data[i];

    delete[] data;

    data = new_data;

    length = length + MStr.length;
    capacity = length + 1;

    data[length] = '\0';
  }

  return *this;
}

MyString & MyString::operator+=( const char *str )
{
  if (str == 0)
    return *this;

  int slength = (int)strlen(str);

  if (length + slength < capacity)
  {
    for (int i = 0; i < slength; i++)
      data[i + length] = str[i];

    length += slength;

    data[length] = '\0';
  }
  else
  {
    char *new_data = new char[length + slength + 1];

    for (int i = 0; i < length; i++)
      new_data[i] = data[i];

    for (int i = 0; i < slength; i++)
      new_data[i + length] = str[i];

    delete[] data;

    data = new_data;

    length = length + slength;
    capacity = length + 1;

    data[length] = '\0';
  }

  return *this;
}

MyString MyString::operator+( const MyString &MStr ) const
{
  MyString R(*this);

  R += MStr;

  return R;
}

MyString MyString::operator+( const char *str ) const
{
  MyString R(*this);

  R += str;

  return R;
}

MyString operator+( const char *str, const MyString &MStr )
{
  MyString R(str);

  R += MStr;

  return R;
}

bool MyString::operator==( const MyString &MStr ) const
{
  return strcmp(data, MStr.data) == 0;
}

bool MyString::operator!=( const MyString &MStr ) const
{
  return strcmp(data, MStr.data) != 0;
}

bool MyString::operator<( const MyString &MStr ) const
{
  return strcmp(data, MStr.data) < 0;
}

bool MyString::operator<=( const MyString &MStr ) const
{
  return strcmp(data, MStr.data) <= 0;
}

bool MyString::operator==( const char *str ) const
{
  return strcmp(data, str) == 0;
}

bool MyString::operator!=( const char *str ) const
{
  return strcmp(data, str) != 0;
}

bool MyString::operator<( const char *str ) const
{
  return strcmp(data, str) < 0;
}

bool MyString::operator<=( const char *str ) const
{
  return strcmp(data, str) <= 0;
}

bool operator==( const char *str, const MyString &MStr )
{
  return strcmp(str, MStr.data) == 0;
}

bool operator!=( const char *str, const MyString &MStr )
{
  return strcmp(str, MStr.data) != 0;
}

bool operator<( const char *str, const MyString &MStr )
{
  return strcmp(str, MStr.data) < 0;
}

bool operator<=( const char *str, const MyString &MStr )
{
  return strcmp(str, MStr.data) <= 0;
}

char & MyString::operator[]( unsigned int i ) const
{
  if (i > length)
    throw;

  return data[i];
}

std::ostream & operator<<( std::ostream &os, const MyString &MStr )
{
  if (MStr.data != nullptr)
    os << MStr.data;

  return os;
}

std::istream & operator>>( std::istream &is, MyString &MStr )
{
  char ch;

  if (MStr.data != nullptr)
    delete[] MStr.data;
  
  MStr.capacity = 1;
  MStr.length = 0;
  MStr.data = new char[MStr.capacity] {};

  while ((ch = is.get()) != '\n')
  {
    if (MStr.length + 1 >= MStr.capacity)
    {
      MStr.capacity = MStr.capacity * 2 + 1;

      char *new_str = new char[MStr.capacity];

      for (int i = 0; i < MStr.length; i++)
        new_str[i] = MStr.data[i];
      delete[] MStr.data;
      MStr.data = new_str;
    }

    MStr.data[MStr.length++] = ch;
  }

  MStr.data[MStr.length] = '\0';

  return is;
}

MyString addTxtExtension(const MyString &path) { return path + ".txt"; }

char * MyString::get_pointer( void )
{
  return data;
}

void MyString::set( int i, char c )
{
  if (i < 0 || i > length || data == nullptr)
    throw;

  data[i] = c;
}

void MyString::set_new_string( const char *str )
{
  if (data != nullptr)
    delete[] data;

  length = (int)strlen(str);
  capacity = length + 1;

  data = new char[capacity] {};

  for (int i = 0; i < length; i++)
    data[i] = str[i];

  data[length] = '\0';
}

void MyString::print( void )
{
  if (data == nullptr)
    return;

  for (int i = 0; i < length; i++)
    std::cout << data[i];

  std::cout << '\n';
}

int MyString::get_length( void )
{
  return length;
}


void MyString::read_line( void )
{
  std::cout << "Enter new string: ";

  char ch;

  if (data != nullptr)
    delete[] data;

  capacity = 1;
  length = 0;
  data = new char[capacity] {};

  while ((ch = getchar()) != '\n')
  {
    if (length + 1 >= capacity)
    {
      capacity = capacity * 2 + 1;

      char *new_str = new char[capacity];

      for (int i = 0; i < length; i++)
        new_str[i] = data[i];
      delete[] data;
      data = new_str;
    }

    data[length++] = ch;
  }

  data[length] = '\0';
}
