#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <cstring>

double add( double a, double b );
double sub( double a, double b );
double mul( double a, double b );
double div( double a, double b );

//Прототипы используемых в данном задании функций:

void sort( char *pcFirst, int nNumber, int size, void (*Swap)(void *, void *), int (*Compare)(void *, void *) );

void swap_int(void *p1, void *p2);
int cmp_int( void *p1, void *p2 );

void swap_double( void *p1, void *p2 );
int cmp_double( void *p1, void *p2 );

void swap_str( void *p1, void *p2 );
int cmp_str( void *p1, void *p2 );

void print_max( double *ar, int size );
void print_min( double *ar, int size );
void sort_asc( double *ar, int size );
void sort_desc( double *ar, int size );

double kvadr( double x );
double integrate ( double (*func)( double ), double start, double end, int sec_cnt );


#define MAX_LENGTH 15

enum Book_Type
{
  classical = 1,
  scientific = 2,
};

struct Book
{
  char Author[MAX_LENGTH + 1];
  char Title[MAX_LENGTH + 1];
  int Year;
  double Cost;
  Book_Type Type;
  /*
  Book( void )
  {
    memset(Author, 0, MAX_LENGTH);
    memset(Title, 0, MAX_LENGTH);
    Year = 0;
    Cost = 0;
    Type = classical;
  }

  Book( char *new_author, char *new_title, int new_year, double new_cost, Book_Type new_type )
  {
    strncpy(Author, new_author, std::min(MAX_LENGTH, (int)strlen(new_author)));
    strncpy(Title, new_title, std::min(MAX_LENGTH, (int)strlen(new_title)));
    Year = new_year;
    Cost = new_cost;
    Type = new_type;
  }
  */
};

void print_book( Book *b );
void scan_book( Book *b );
