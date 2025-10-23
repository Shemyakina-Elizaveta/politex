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

  std::cout << "\n\n\nproperties test passed\n\n\n";

  return 0;
}