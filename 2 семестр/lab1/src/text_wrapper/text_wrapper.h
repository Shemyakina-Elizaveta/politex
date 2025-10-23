#ifndef __text_wrapper_h__
#define __text_wrapper_h__

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "../my_string/my_string.h"

class TextWrapper
{
  int line_width;
  MyString str;
  char *fs, *ls;
  int totall;

public:
  TextWrapper( void )
  {
    line_width = 0;
    fs = nullptr, ls = nullptr;
    totall = 0;
  }

  ~TextWrapper( void )
  {
  }

  TextWrapper( MyString &MStr, int lw )
  {
    line_width = lw;
    str = MStr;
    fs = nullptr, ls = nullptr;
    totall = 0;
  }

  void skip_alpha( void );
  void skip_space( void );
  void print_dop_probels( void );
  int print_word( void );
  void print_border( void );
  void print_wrapped( void );
};


#endif /* __text_wrapper_h__ */