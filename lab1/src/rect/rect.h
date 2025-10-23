#ifndef __rect_h__
#define __rect_h__

#include <iostream>
#include <stdlib.h>
#include <algorithm>

class Rect
{
  /* 
  int left;
  int top;
  int right;
  int bottom;
  */

  int left;
  int bottom;
  int height;
  int width;

public:
  Rect( void ) :  left(0), width(0), height(0), bottom(0) // left(0), right(0), top(0), bottom(0)
  {
    std::cout << "Default constructor " << this << '\n';
  }
 
  ~Rect( void )
  {
    std::cout << "Destructor " << this << '\n';
  }


  Rect( int new_left, int new_right, int new_top, int new_bottom )
  {

    std::cout << "Create constructor " << this << '\n';

    left = new_left;
    height = new_top - new_bottom;
    width = new_right - new_left;
    // top = new_top;
    // right = new_right;
    bottom = new_bottom;
  }

  Rect( const Rect &copy_rect )
  {
    std::cout << "Copy constructor " << this << '\n';

    left = copy_rect.left;
    // top = copy_rect.top;
    // right = copy_rect.right;
    height = copy_rect.height;
    width = copy_rect.width;
    bottom = copy_rect.bottom;
  }

  int get_left( void )
  {
    return left;
  }

  int get_top( void )
  {
    // return top;
    return bottom + height;
  }

  int get_right( void )
  {
    // return right;
    return left + width;
  }

  int get_bottom( void )
  {
    return bottom;
  }

   void set_all( int new_left, int new_right, int new_top, int new_bottom )
  {
    left = new_left;
    // top = new_top;
    // right = new_right;
    height = new_top - new_bottom;
    width = new_right - new_left;
    bottom = new_bottom;
  }

  void inflate( int amount )
  {
    left -= amount, /* top += amount, right += amount, */ height += amount * 2, width += amount * 2, bottom -= amount;
  }

  void inflate( int dw, int dh )
  {
    // left -= dw, right += dw;
    // top += dh, bottom -= dh;
    left -= dw, width += dw * 2;
    height += dh * 2, bottom -= dh;
  }

  void inflate( int d_left, int d_right, int d_top, int d_bottom )
  {
    left -= d_left;
    // right += d_right;
    // top += d_top;
    width += d_right + d_left;
    height += d_top + d_bottom;
    bottom -= d_bottom;
  }

  void move( int x, int y = 0 )
  {
    left += x, width;// right += x;
    /* top += y, */ bottom += y;
  }

  int get_width( void )
  {
    // return right - left;
    return width;
  }

  int get_height( void )
  {
    // return top - bottom;
    return height;
  }

  int get_square( void )
  {
    return get_width() * get_height();
  }

  void set_width( int new_width )
  {
    // right = left + new_width;
    width = new_width;
  }

  void set_height( int new_height )
  {
    // top = bottom + new_height
    height = new_height;
  }
};



Rect bounding_rect( Rect r1, Rect r2 );
void print_rect( Rect &r );

#endif /* __rect_h__ */

