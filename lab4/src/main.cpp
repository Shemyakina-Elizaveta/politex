#include <iostream>

#include "list/list.h"

int main( void )
{

  List list;
    
  list.push_back(Circle(Point(1, 2), 3));
  list.push_back(Circle(Point(4, 5), 2));
  list.push_front(Circle(Point(0, 0), 1));
  list.push_back(Circle(Point(4, 5), 2));
  
  std::cout << "Initial list:" << std::endl;
  std::cout << list << std::endl;
  
  list.sort_by_area();
  std::cout << "After sorting by area:" << std::endl;
  std::cout << list << std::endl;
  
  char filename[80];
  std::cout << "Enter output file name: ";
  std::cin >> filename;
  list.save_to_file(filename);
  
  List newList;
  newList.load_from_file(filename);
  std::cout << "List loaded from file:" << std::endl;
  std::cout << newList << std::endl;
  
  return 0;
}