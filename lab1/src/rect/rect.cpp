#include "rect.h"

Rect bounding_rect( Rect r1, Rect r2 )
{
  return Rect(
    std::min(r1.get_left(), r2.get_left()),
    std::max(r1.get_right(), r2.get_right()),
    std::max(r1.get_top(), r2.get_top()),
    std::min(r1.get_bottom(),r2.get_bottom())
  );
}

void print_rect( Rect &r )
{
  std::cout <<
    "Left: " << r.get_left() << '\n' <<
    "Right: " << r.get_right() << '\n' <<
    "Top: " << r.get_top() << '\n' <<
    "Bottom: " << r.get_bottom() << "\n\n";
}
