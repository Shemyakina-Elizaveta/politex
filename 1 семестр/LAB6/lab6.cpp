#include "lib.h"

/*
* TODO:
* 1. Если библиотека пуста, то при вызове функции, которая не может корректно работать
*    с пустой библиотекой писать об этом.
* 2. При вводе жанра сделать доступным выбор из уже введенных (по номеру).
* 3. Вывести промежуток допустимого года при ошибке (или в приглашении ко вводу).
* 4. Проверить фильтрацию по жанру (были добавлены лишние книги). - проверить
* 5. Проверить переполенение буфера (загрузили книги, попытались удалить, добавили книгу 1, добавили книгу 2, удалить книгу, выйти).
*/   

int main( void )
{
  library lib;

  while (true)
  {
    int op;

    printf(
      "\n\nChoose option:\n"
      "1. Print library\n"
      "2. Add a new book\n"
      "3. Sort books\n"
      "4. Delete a book by name\n"
      "5. Change the information about book\n"
      "6. Save library to file\n"
      "7. Load library from file\n"
      "8. Print books with special filter (1)\n"
      "0. Exit\n"
      "Your choice: ");

    if (scanf("%d", &op) == 0)
    {
      scanf("%*s");
      printf("Invalid option was chosen\n");
      continue;
    }

    switch (op)
    {
    case 1:
      print_library(&lib);
      break;
    case 2:
      add_to_library(&lib);
      break;
    case 3:
      sort_library(&lib);
      break;
    case 4:
      delete_from_library(&lib);
      break;
    case 5:
      change_from_library(&lib);
      break;
    case 6:
      save_library(&lib);
      break;
    case 7:
      load_library(&lib);
      break;
    case 8:
      print_with_filter_from_library(&lib);
      break;
    case 0:
      delete_library(&lib);
      exit(0);
      break;
    default:
      break;
    }
  }
  return 0;
}
