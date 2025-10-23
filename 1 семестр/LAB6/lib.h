#ifndef __lib_h__
#define __lib_h__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "book.h"

struct library
{
  book **books = NULL;
  int size = 0;
  int capacity = 0;

  char **genres = NULL;
  int genres_cnt = 0;
};

void print_library( library *lib );
void delete_library( library *lib );
void add_to_library( library *lib );
void sort_library( library *lib );
void find_in_library( library *lib );
void delete_from_library( library *lib );
void change_from_library( library *lib );
void load_library( library *lib );
void save_library( library *lib );
void print_with_filter_from_library( library *lib );


#endif /* __lib_h__ */