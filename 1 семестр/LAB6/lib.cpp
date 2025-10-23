#include "lib.h"

void print_library( library *lib )
{
  if (lib == NULL)
    return;

  if (lib->size == 0)
    printf("Library is empty\n");
  else
  {
    for (int i = 0; i < lib->size; i++)
      print_book(lib->books[i]);
  }
}

void delete_library( library *lib )
{
  if (lib == NULL)
    return;

  for (int i = 0; i < lib->size; i++)
    delete_book(lib->books[i]);

  free(lib->books);

  for (int i = 0; i < lib->genres_cnt; i++)
    free(lib->genres[i]);
  free(lib->genres);
  lib->books = NULL;
  lib->genres = NULL;
  lib->size = 0;
  lib->capacity = 0;
  lib->genres_cnt = 0;
}

void add_to_library( library *lib )
{
  if (lib == NULL)
    return;

  if (lib->size + 1 >= lib->capacity)
  {
    book **new_books;

    lib->capacity = lib->capacity * 2 + 1;

    if ((new_books = (book **)malloc(sizeof(book *) * lib->capacity)) == NULL)
      return;

    for (int i = 0; i < lib->size; i++)
      new_books[i] = lib->books[i];

    free(lib->books);
    lib->books = new_books;
  }

  lib->books[lib->size++] = create_book(lib->genres, lib->genres_cnt);
}

void sort_library( library *lib )
{
  int op = 0, type = 0;

  if (lib == NULL || lib->size < 2)
  {
    printf("Not enought books to be sorted\n");
    return;
  }

  printf(
    "\nChoose the field to sort by:\n"
    "1. Book's name\n"
    "2. Book's author\n"
    "3. Book's year\n"
    "4. Book's genre\n"
    "5. Book's annotation\n"
    "Your choice: "
  );

  enter_option(op, 1, 5);

  printf(
    "\nChoose the sort type:\n"
    "1. In descending order\n"
    "2. In ascending order\n"
    "Your choice: "
  );

  enter_option(type, 1, 2);

  if (type == 1)
    type = -1;
  else
    type = 1;

  for (int i = 0; i < lib->size; i++)
  {
    int flag = 1;

    for (int j = 0; j < lib->size - i - 1; j++)
      if (compare_books(lib->books[j], lib->books[j + 1], op, type) == 1)
      {
        book *tmp = lib->books[j];

        lib->books[j] = lib->books[j + 1];
        lib->books[j + 1] = tmp;
        flag = 0;
      }

    if (flag)
      break;
  }
}

void find_in_library( library *lib )
{
  if (lib == NULL)
    return;

  if (lib->size == 0)
  {
    printf("Library is empty\n");
    return;
  }

  int op;

  printf(
    "\nChoose the field to find by:\n"
    "1. Book's name\n"
    "2. Book's author\n"
    "3. Book's genre\n"
    "Your choice: "
  );

  char *str = NULL;

  enter_option(op, 1, 3);

  printf("Enter the searching string: ");
  read_string(str);

  int cnt = 0;

  printf("\nFinded books: \n");

  for (int i = 0; i < lib->size; i++)
    if (check_book(lib->books[i], str, op) == 1)
    {
      cnt++;
      printf("%d.", cnt);
      print_book(lib->books[i]);
    }

  if (cnt == 0)
    printf("Books with this field are not recorded\n");

  free(str);
}

void delete_from_library( library *lib )
{
  if (lib == NULL)
    return;

  if (lib->size == 0)
  {
    printf("Library is empty\n");
    return;
  } 

  char *str = NULL;

  printf("Enter the book's name: ");
  read_string(str);

  int flag = 0;
  book *b = NULL;

  for (int i = 0; i < lib->size; i++)
    if (check_book(lib->books[i], str, 1) == 1)
    {
      flag = 1, b = lib->books[i];
      break;
    }

  if (flag)
  {
    book **new_books;

    if ((new_books = (book **)malloc(sizeof(book *) * (lib->size - 1))) == NULL)
    {
      free(str);
      return;
    }

    for (int i = 0, j = 0; i < lib->size; i++)
      if (lib->books[i] != b)
        new_books[j++] = lib->books[i];

    delete_book(b);
    free(lib->books);
    lib->books = new_books;
    lib->capacity = lib->size - 1;
    lib->size = lib->size - 1;
    printf("Book was deleted\n");
  }
  else
    printf("Book with this name is not recorded\n");

  free(str);
}

void change_from_library( library *lib )
{
  if (lib == NULL)
    return;

  if (lib->size == 0)
  {
    printf("Library is empty\n");
    return;
  }

  char *str = NULL;

  printf("Enter the book's name: ");
  read_string(str);

  int flag = 0;
  book *b = NULL;

  for (int i = 0; i < lib->size; i++)
    if (check_book(lib->books[i], str, 1) == 1)
    {
      flag = 1, b = lib->books[i];
      break;
    }

  if (flag)
    change_book(b, lib->genres, lib->genres_cnt);
  else
    printf("Book with this name is not recorded\n");

  free(str);
}

int read_string_from_file( FILE *F, char *&str )
{
  int size = 0, capacity = 1;
  char ch;

  if (F == NULL)
    return -1;

  if (str != NULL)
    free(str);

  if ((str = (char *)malloc(sizeof(char) * capacity)) == NULL)
    return -1;

  ch = fgetc(F);
  while (ch != EOF && isspace(ch))
    ch = fgetc(F);

  while (ch != EOF && ch != '\n')
  {
    if (ch == '\r')
    {
      ch = fgetc(F);
      continue;
    }

    if (size + 1 >= capacity)
    {
      char *new_str;

      capacity = capacity * 2 + 1;
      if ((new_str = (char *)malloc(capacity * sizeof(char))) == NULL)
        return -1;

      strncpy(new_str, str, size);
      free(str);
      str = new_str;
    }

    str[size++] = ch;
    ch = fgetc(F);
  }

  size--;
  while (size >= 0 && str[size] == ' ')
    size--;
  str[size + 1] = '\0';

  if (ch == EOF)
    return 0;

  return 1;
}

void write_string_to_file( FILE *F, char *str )
{
  if (F == NULL || str == NULL)
    return;

  fputs(str, F);
  fputs("\n", F);
}

int find_genre_in_library( char *cur_genre, char **&genres, int &genres_cnt )
{
  int res = -1;

  if ((genres == NULL && genres_cnt != 0) || cur_genre == NULL)
    return -1;

  for (int i = 0; i < genres_cnt; i++)
    if (strcmp(cur_genre, genres[i]) == 0)
    {
      res = i;
      break;
    }

  if (res == -1)
  {
    char **new_genres = NULL;

    if ((new_genres = (char **)malloc(sizeof(char *) * (genres_cnt + 1))) == NULL)
      return -1;

    for (int i = 0; i < genres_cnt; i++)
      new_genres[i] = genres[i];

    // if ((new_genres[genres_cnt] = (char *)malloc(sizeof(char) * (strlen(cur_genre) + 1))) == NULL)
    // {
    //   free(new_genres);
    //   return -1;
    // }

    // strcpy(new_genres[genres_cnt], cur_genre);
    new_genres[genres_cnt] = cur_genre;
    
    free(genres);

    genres = new_genres;

    res = genres_cnt;
    genres_cnt++;
  }
  else
    free(cur_genre);
  
  return res;
}

void load_library( library *lib )
{
  FILE *F;
  char *str = NULL;

  if (lib == NULL)
    return;

  printf("Enter file name: ");
  read_string(str);

  if ((F = fopen(str, "r")) == NULL)
  {
    printf("Invalid file\n");
    return;
  }

  free(str);

  while (true)
  {
    if (lib->size + 1 >= lib->capacity)
    {
      book **new_books;

      lib->capacity = lib->capacity * 2 + 1;

      if ((new_books = (book **)malloc(lib->capacity * sizeof(book *))) == NULL)
      {
        printf("Programm cannot allocate memory\n");
        fclose(F);
        return;
      }

      for (int i = 0; i < lib->size; i++)
        new_books[i] = lib->books[i];

      free(lib->books);
      lib->books = new_books;
    }

    char *f1 = NULL, *f2 = NULL, *f4 = NULL, *f5 = NULL;
    int f3, fs_cnt = 0;

    if (read_string_from_file(F, f1) == 0 && strlen(f1) > 0)
    {
      printf("Invalid file format\n");
      free(f1);
      break;
    }
    else if (strlen(f1) == 0)
    {
      free(f1);
      break;
    }

    if (read_string_from_file(F, f2) == 0)
    {
      printf("Invalid file format\n");
      free(f1);
      free(f2);
      break;
    }

    if (fscanf(F, "%d", &f3) == 0)
    {
      printf("Invalid file format\n");
      free(f1);
      free(f2);
      break;
    }

    if (read_string_from_file(F, f4) == 0)
    {
      printf("Invalid file format\n");
      free(f1);
      free(f2);
      free(f4);
      break;
    }

    if (read_string_from_file(F, f5) == 0 && f5 == NULL)
    {
      printf("Invalid file format\n");
      free(f1);
      free(f2);
      free(f4);
      break;
    }

    if ((lib->books[lib->size] = (book *)malloc(sizeof(book))) == NULL)
    {
      printf("Programm cannot allocate memory\n");
      free(f1);
      free(f2);
      free(f4);
      free(f5);
      break;
    }
    lib->books[lib->size]->name = f1;
    lib->books[lib->size]->author = f2;
    lib->books[lib->size]->year = f3;
    
    int ind = find_genre_in_library(f4, lib->genres, lib->genres_cnt);
    lib->books[lib->size]->genre = lib->genres[ind];
    lib->books[lib->size]->annotation = f5;
    lib->size++;
  }

  printf("Books were loaded\n");
  fclose(F);
}

void save_library( library *lib )
{
  FILE *F;
  char *str = NULL;

  if (lib == NULL)
    return;

  if (lib->size == 0)
  {
    printf("Library is empty\n");
    return;
  }


  printf("Enter file name to save library: ");
  read_string(str);

  if ((F = fopen(str, "w")) == NULL)
  {
    free(str);
    printf("File with this name doesn't exist\n");
    return;
  }
  free(str);

  for (int i = 0; i < lib->size; i++)
  {
    write_string_to_file(F, lib->books[i]->name);
    write_string_to_file(F, lib->books[i]->author);
    fprintf(F, "%d\n", lib->books[i]->year);
    write_string_to_file(F, lib->books[i]->genre);
    write_string_to_file(F, lib->books[i]->annotation);
  }

  printf("%d books were saved\n", lib->size);
  fclose(F);
}

void print_with_filter_from_library( library *lib )
{
  if (lib == NULL)
    return;

  if (lib->size == 0)
  {
    printf("Library is empty\n");
    return;
  }


  int op;

  printf(
    "\nChoose the field to find by:\n"
    "1. Book's author and genre\n"
    "2. Book's author\n"
    "3. Book's genre\n"
    "Your choice: "
  );

  enter_option(op, 1, 3);

  int size = 0;
  char *str1 = NULL, *str2 = NULL;

  if (op == 2 || op == 3)
  {
    printf("Enter filter: ");
    read_string(str1);

    for (int i = 0; i < lib->size; i++)
    {
      if (check_book(lib->books[i], str1, op) == 1)
        print_book(lib->books[i]), size++;
    }

    free(str1);
  }
  else
  {
    printf("Enter author: ");
    read_string(str1);
    printf("Enter genre: ");
    read_string(str2);

    for (int i = 0; i < lib->size; i++)
    {
      if (check_book(lib->books[i], str1, 2) == 1 && check_book(lib->books[i], str2, 3) == 1)
        print_book(lib->books[i]), size++;
    }

    free(str1);
    free(str2);
  }
}
