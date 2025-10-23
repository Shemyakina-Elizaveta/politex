#include "text_wrapper.h"


void TextWrapper::skip_alpha( void )
{
  while (*ls != '\0' && !isspace(*ls))
    ls++;
}

void TextWrapper::skip_space( void )
{
  while (*ls != '\0' && isspace(*ls))
    ls++;
}

void TextWrapper::print_dop_probels( void )
{
  if (totall == 0)
    return;
  for (int i = totall; i < line_width; i++)
    std::cout << ' ';
  std::cout << " |\n";
}

int TextWrapper::print_word( void ) // return word length
{
  int length = 0;

  while (fs != ls && length < line_width)
  {
    std::cout << *fs;
    fs++, length++;
  }
  
  return length;
}

void TextWrapper::print_border( void )
{
  std::cout << ' ';
  for (int i = 0; i < line_width + 2; i++)
    std::cout << '_';
  std::cout << '\n';
}

void TextWrapper::print_wrapped( void )
{
  print_border();

  fs = str.get_pointer();
  ls = fs;
  totall = 0;

  while (*fs != '\0')
  {
    if (totall == 0)
      std::cout << "| ";

    skip_alpha();

    int curl = (int)(ls - fs);

    if (totall + curl > line_width)
    {
      print_dop_probels();
      if (totall != 0)
        std::cout << "| ";

      int len = print_word();

      if (len == line_width)
      {
        std::cout << " |\n";
        totall = 0;
      }
      else
      {
        std::cout << ' ';
        totall = len + 1;
        skip_space();
        fs = ls;
      }
    }
    else if (totall + curl <= line_width)
    {
      print_word();
      skip_space();
      fs = ls;
      
      if (totall + curl < line_width)
      {
        std::cout << ' ';
        totall += 1;
      }
      
      totall += curl;

      if (totall == line_width)
      {
        std::cout << " |\n";
        totall = 0;
      }
    }
  }
  
  print_dop_probels();
  print_border();

  std::cout <<
      "     \\\n"
      "      \\\n"
      "        /\\_/\\  (\n"
      "       ( ^.^ ) _)\n"
      "         \\\"/  (\n"
      "       ( | | )\n"
      "      (__d b__)\n";

}
