#include "book.h"

void enter_option( int &op, int gr1, int gr2 )
{
  while (true)
  {
    if (scanf("%d", &op) == 0)
    {
      printf("Invalid data was entered\n");
      scanf("%*s");
    }
    if (op >= gr1 && op <= gr2)
      break;
    printf("Invalid option was chosen\n");
    printf("Your choice: ");
  }
}

void read_string( char *&str )
{
  char ch;
  int size = 0;
  int capacity = 1;

  if (str != NULL)
  {
    free(str);
    str = NULL;
  }

  scanf("%c", &ch);

  while (isspace(ch))
    scanf("%c", &ch);

  if ((str = (char *)malloc(capacity * sizeof(char))) == NULL)
  {
    printf("Error: programm cannot allocate memory\n");
    return;
  }

  while (ch != '\n')
  {
    if (size + 1 >= capacity)
    {
      char *new_str = NULL;

      capacity = capacity * 2 + 1;

      if ((new_str = (char *)malloc(capacity * sizeof(char))) == NULL)
      {
        printf("Error: programm cannot allocate memory\n");
        return;
      }
      strncpy(new_str, str, size);
      free(str);
      str = new_str;
    }

    str[size++] = ch;
    scanf("%c", &ch);
  }

  size--;
  while (str[size] == ' ')
    size--;
  str[size + 1] = '\0';
}

void enter_year( int &res_year )
{
  std::time_t t = std::time(nullptr);
  std::tm *tinfo = std::localtime(&t);
  int year = tinfo->tm_year + 1900;

  while (true)
  {
    printf("Enter book's year (from 863 to current year): ");
    if (scanf("%d", &res_year) != 1)
    {
      printf("Invalid data was entered\n");
      scanf("%*s");
    }
    else
    {
      if (res_year >= 863 && res_year <= year)
        break;
      printf("Invalid year was entered\n");
    }
  }
}

void enter_genre( char **&genres, int &genres_cnt, char *&book_genre )
{
  if (genres != NULL && genres_cnt != 0)
  {
    for (int i = 0; i < genres_cnt; i++)
      printf("%d. %s\n", i + 1, genres[i]);
  }
  printf("%d. New genre\n", genres_cnt + 1);

  int op;
  printf("Your choice: ");
  enter_option(op, 1, genres_cnt + 1);

  if (op == genres_cnt + 1)
  {
    printf("Enter new genre: ");

    char **new_genres = NULL;

    if ((new_genres = (char **)malloc(sizeof(char *) * (genres_cnt + 1))) == NULL)
      return;

    for (int i = 0; i < genres_cnt; i++)
      new_genres[i] = genres[i];

    new_genres[genres_cnt] = NULL;
    read_string(new_genres[genres_cnt++]);
    free(genres);
    genres = new_genres;
  }

  book_genre = genres[op - 1];
}

void print_book( book *b )
{
  if (b == NULL)
    return;

  printf("\nBook: \n");
  printf("  Name: %s\n", b->name);
  printf("  Author: %s\n", b->author);
  printf("  Year: %d\n", b->year);
  printf("  Genre: %s\n", b->genre);
  printf("  Annotation: %s\n", b->annotation);
}

void delete_book( book *b )
{
  if (b == NULL)
    return;

  free(b->name);
  free(b->author);
  // free(b->genre);
  free(b->annotation);

  free(b);
}

book * create_book( char **&genres, int &genres_cnt )
{
  book *b;

  if ((b = (book *)malloc(sizeof(book))) == NULL)
    return NULL;

  b->name = NULL;
  b->author = NULL;
  b->year = 0;
  b->genre = NULL;
  b->annotation = NULL;

  printf("Add a new book:\n");
  
  printf("Enter book's name: ");
  read_string(b->name);
  printf("Enter book's author: ");
  read_string(b->author);
  enter_year(b->year);

  printf("Choose book's genre:\n");
  enter_genre(genres, genres_cnt, b->genre);
  printf("Enter book's annotation: ");
  read_string(b->annotation);

  return b;
}

int compare_books( book *b1, book *b2, int op, int type )
{
  if (b1 == NULL || b2 == NULL)
    return -1;

  if (op == 1)
    return strcmp(b1->name, b2->name) * type;
  else if (op == 2)
    return strcmp(b1->author, b2->author) * type;
  else if (op == 3)
  {
    if (type == -1)
      return (b1->year < b2->year);
    else
      return (b1->year > b2->year);
  }
  else if (op == 4)
    return strcmp(b1->genre, b2->genre) * type;
  else if (op == 5)
    return strcmp(b1->annotation, b2->annotation) * type;

  return -1;
}

int check_book( book *b, char *str, int op )
{
  if (b == NULL)
    return -1;

  if (op == 1)
    return strcmp(b->name, str) + 1;
  else if (op == 2)
    return strcmp(b->author, str) + 1;
  else if (op == 3)
    return strcmp(b->genre, str) + 1;

  return -1;
}

void change_book( book *&b, char **&genres, int genres_cnt )
{
  char ch;

  if (b == NULL)
    return;

  print_book(b);

  printf("Do you want to change book's name? (y/n): ");
  scanf("%c", &ch);

  if (ch == 'y' || ch == 'Y')
  {
    printf("New book's name: ");
    read_string(b->name);
  }

  printf("Do you want to change book's author? (y/n): ");
  scanf("%c", &ch);
  while (isspace(ch))
    scanf("%c", &ch);

  if (ch == 'y' || ch == 'Y')
  {
    printf("New book's author: ");
    read_string(b->author);
  }

  printf("Do you want to change book's year? (y/n): ");
  scanf("%c", &ch);
  while (isspace(ch))
    scanf("%c", &ch);

  if (ch == 'y' || ch == 'Y')
    enter_year(b->year);

  printf("Do you want to change book's genre? (y/n): ");
  scanf("%c", &ch);
  while (isspace(ch))
    scanf("%c", &ch);

  if (ch == 'y' || ch == 'Y')
    enter_genre(genres, genres_cnt, b->genre);

  printf("Do you want to change book's annotation? (y/n): ");
  scanf("%c", &ch);
  while (isspace(ch))
    scanf("%c", &ch);

  if (ch == 'y' || ch == 'Y')
  {
    printf("New book's annotation: ");
    read_string(b->annotation);
  }
}
