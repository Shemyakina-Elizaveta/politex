#include "other.h"

double add( double a, double b )
{
  return a + b;
}

double sub( double a, double b )
{
  return a - b;
}

double mul( double a, double b )
{
  return a * b;
}

double div( double a, double b )
{
  if (b == 0)
    return INFINITY;
  return a / b;
}


void sort( char* pcFirst, int nNumber, int size, void (*Swap)( void *, void * ), int (*Compare)( void *,  void * ) )
{
  for (int i = 1; i < nNumber; i++)
    for(int j = nNumber - 1; j >= i; j--)
    {
      char* pCurrent = pcFirst + j * size;
      char* pPrevious = pcFirst + (j - 1) * size;

      if ((*Compare)( pPrevious, pCurrent ) > 0)
        (*Swap)( pPrevious, pCurrent );
    }
}

void swap_int( void *p1, void *p2 )
{
  int *i1, *i2, tmp;

  i1 = static_cast<int *>(p1);
  i2 = static_cast<int *>(p2);

  tmp = *i1;
  *i1 = *i2;
  *i2 = tmp;
}

int cmp_int( void *p1, void *p2 )
{
  int nResult = 0;
  int *i1 = static_cast<int *>(p1), *i2 = static_cast<int *>(p2);

  if (*i1 > *i2)
    nResult = 1;
  else if (*i1 < *i2)
    nResult = -1;
  else
    nResult = 0;

  return nResult;
}

void swap_double( void *p1, void *p2 )
{
  double *i1, *i2, tmp;

  i1 = static_cast<double *>(p1);
  i2 = static_cast<double *>(p2);

  tmp = *i1;
  *i1 = *i2;
  *i2 = tmp;
}

int cmp_double( void *p1, void *p2 )
{
  int nResult = 0;
  double *i1 = static_cast<double *>(p1), *i2 = static_cast<double *>(p2);

  if (*i1 > *i2)
    nResult = 1;
  else if (*i1 < *i2)
    nResult = -1;
  else
    nResult = 0;

  return nResult;
}

void swap_str( void *p1, void *p2 )
{
  char **c1 = static_cast<char **>(p1), **c2 = static_cast<char **>(p2);
  char *tmp;

  tmp = *c1;
  *c1 = *c2;
  *c2 = tmp;
}

int cmp_str( void *p1, void *p2 )
{
  char **i1 = static_cast<char **>(p1), **i2 = static_cast<char **>(p2);

  return strcmp(*i1, *i2);
}

void print_max( double *ar, int size )
{
  if (size == 0)
    return;
  double ma = ar[0];

  for (int i = 1; i < size; i++)
    ma = std::max(ma, ar[i]);

  std::cout << "Maximum element in array: " << ma << '\n';
}

void print_min( double *ar, int size )
{
  if (size == 0)
    return;
  double mi = ar[0];

  for (int i = 1; i < size; i++)
    mi = std::min(mi, ar[i]);

  std::cout << "Minimum element in array: " << mi << '\n';
}

void sort_asc( double *ar, int size )
{
  if (size == 0)
    return;

  for (int i = 0; i < size; i++)
  {
    double mi = ar[i];
    int mi_ind = i;

    for (int j = i + 1; j < size; j++)
      if (ar[j] < mi)
        mi = ar[j], mi_ind = j;

    double tmp = ar[i];
    ar[i] = ar[mi_ind];
    ar[mi_ind] = tmp;
  }

  for (int i = 0; i < size; i++)
    std::cout << ar[i] << ' ';
  std::cout << '\n';
}

void sort_desc( double *ar, int size )
{
  if (size == 0)
    return;

  for (int i = 0; i < size; i++)
  {
    double ma = ar[i];
    int ma_ind = i;

    for (int j = i + 1; j < size; j++)
      if (ar[j] > ma)
        ma = ar[j], ma_ind = j;

    double tmp = ar[i];
    ar[i] = ar[ma_ind];
    ar[ma_ind] = tmp;
  }

  for (int i = 0; i < size; i++)
    std::cout << ar[i] << ' ';
  std::cout << '\n';
}

double kvadr( double x )
{
  return x * x;
}

double integrate ( double (*func)( double ), double start, double end, int sec_cnt )
{
  double h = (end - start) / sec_cnt;
  double res = 0;

  for (double i = start; i <= end; i += h)
    res += func(i + h / 2);

  return res * h;
}

void print_book( Book *b )
{
  if (b == nullptr)
  {
    std::cout << "Invalid pointer on Book\n";
    return;
  }

  printf("Book: \n");
  printf("Author: %s\n", b->Author);
  printf("Title: %s\n", b->Title);
  printf("Year: %d\n", b->Year);
  printf("Cost: %f\n", b->Cost);

  switch (b->Type)
  {
  case classical:
    printf("Type: classical\n");
    break;
  case scientific:
    printf("Type: scientific\n");
    break;
  default:
    printf("Type: Invalid type\n");
    break;
  }
}

void scan_book( Book *b )
{
  if (b == nullptr)
    return;

  printf("Enter book author: \n");
  memset(b->Author, 0, MAX_LENGTH);
  scanf("%s", b->Author);

  printf("Enter book title: \n");
  memset(b->Title, 0, MAX_LENGTH);
  scanf("%s", b->Title);

  while (true)
  {
    printf("Enter book year: \n");

    if (scanf("%d", &b->Year) == 0)
      scanf("%*s");
    else if (b->Year >= 863 && b->Year <= 2025)
      break;

    printf("Invalid year was entered\n");
  }

  while (true)
  {
    printf("Enter book cost: \n");

    if (scanf("%lf", &b->Cost) == 0)
      scanf("%*s");
    else if (b->Cost > 0)
      break;

    printf("Invalid cost was entered\n");
  }

  while (true)
  {
    printf("Choose book category (enter a nnumber): \n");
    printf("1. classical\n");
    printf("2. scientific\n");

    if (scanf("%d", &b->Type) == 0)
      scanf("%*s");
    else if (b->Type >= 1 && b->Type <= 2)
      break;

    printf("Invalid type was entered\n");
  }
}
