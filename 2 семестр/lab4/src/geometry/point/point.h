#ifndef __point_h__
#define __point_h__


#include <iostream>


class Point
{
private:
  double x, y;

public:

  Point( void );
  Point( double n );
  Point( double nx, double ny );
  Point( const Point &npoint );

  ~Point( void );

  bool operator==( const Point &np ) const;

  void operator=( const Point &npoint );

  double get_x( void ) const;
  double get_y( void ) const;

  void set( double nx, double ny );

  void print( std::ostream &os ) const;
};

#endif /* __point_h__ */
