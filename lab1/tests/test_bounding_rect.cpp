#include <iostream>
#include <cassert>

#include "../src/rect/rect.h"

int main( void )
{
  Rect r1(0, 3, 8, 2);
  Rect r2(1, 4, 9, 3);

  Rect bounding = bounding_rect(r1, r2);
  assert(bounding.get_left() == 0);   
  assert(bounding.get_right() == 4);  
  assert(bounding.get_top() == 9);   
  assert(bounding.get_bottom() == 2);

  Rect r3(3, 0, 8, 2);  
  Rect bounding2 = bounding_rect(r1, r3);
  assert(bounding2.get_left() == 0);  
  assert(bounding2.get_right() == 3); 

  Rect r4(0, 3, 2, 8); 
  Rect bounding3 = bounding_rect(r1, r4);
  assert(bounding3.get_top() == 8);   
  assert(bounding3.get_bottom() == 2); 

  std::cout << "\n\n\nbounding rect test passed\n\n\n";
  return 0;
}