#include <iostream>
#include <cassert>

#include "../src/rect/rect.h"

int main( void )
{
  Rect r1(1, 2, 4, 3);

  r1.inflate(2);

  assert(r1.get_left() == -1);
  assert(r1.get_right() == 4);
  assert(r1.get_top() == 6);
  assert(r1.get_bottom() == 1);


  r1.inflate(1, 1);

  assert(r1.get_left() == -2);
  assert(r1.get_right() == 5);
  assert(r1.get_top() == 7);
  assert(r1.get_bottom() == 0);

  r1.inflate(1, 2, 3, 4);

  assert(r1.get_left() == -3);
  assert(r1.get_right() == 7);
  assert(r1.get_top() == 10);
  assert(r1.get_bottom() == -4);

  r1.move(2);

  assert(r1.get_left() == -1);
  assert(r1.get_right() == 9);
  assert(r1.get_top() == 10);
  assert(r1.get_bottom() == -4);

  std::cout << "\n\n\noperations test passed\n\n\n";

  return 0;
}