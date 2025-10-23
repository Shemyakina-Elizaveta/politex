#ifndef __book_h_
#define __book_h_

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>
#include <ctime>

struct book
{
  char *name = NULL;
  char *author = NULL;
  int year;
  char *genre = NULL;
  char *annotation = NULL;
};

void enter_option( int &op, int gr1, int gr2 );
void read_string( char *&str );

void print_book( book *b );
book * create_book( char **&genres, int &genres_cnt );
void delete_book( book *b );
int compare_books( book *b1, book *b2, int op, int type );
int check_book( book *b, char *str, int op );
void change_book( book *&b, char **&genres, int genres_cnt );


#endif /* __book_h_ */