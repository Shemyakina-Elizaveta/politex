#include <iostream>
#include <cassert>

#include "../src/rect/rect.h"

int main( void )
{
  Rect r1;
  assert(r1.get_left() == 0);
  assert(r1.get_right() == 0);
  assert(r1.get_top() == 0);
  assert(r1.get_bottom() == 0);
    
  //paramets constructor
  Rect r2(2, 7, 6, 3);
  assert(r2.get_left() == 2);
  assert(r2.get_right() == 7);
  assert(r2.get_top() == 6);
  assert(r2.get_bottom() == 3);

  //copy constructor
  Rect r3 = r2;
  assert(r3.get_left() == r2.get_left());
  assert(r3.get_right() == r2.get_right());
  assert(r3.get_top() == r2.get_top());
  assert(r3.get_bottom() == r2.get_bottom());

  //set_all method
  r1.set_all(1, 2, 4, 3);
  assert(r1.get_left() == 1);
  assert(r1.get_right() == 2);
  assert(r1.get_top() == 4);
  assert(r1.get_bottom() == 3);

  std::cout << "\n\n\nbasic methods test passed\n\n\n\n";
  return 0;
}