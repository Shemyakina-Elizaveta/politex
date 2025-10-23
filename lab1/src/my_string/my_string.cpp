#include "my_string.h"

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
