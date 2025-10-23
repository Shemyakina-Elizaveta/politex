#ifndef __circle_h__
#define __circle_h__


#include <iostream>

#include "../point/point.h"


class Circle
{
private:
  Point center;
  double radius;

public:

  Circle( void );
  Circle( double nradius );
  Circle( double n, double nradius = 1 );
  Circle( double nx, double ny, double nradius = 1 );
  Circle( Point nc, double nradius = 1 );
  Circle( const Circle &ncircle );

  ~Circle( void );

  bool operator==( const Circle &nc ) const;

  void operator=( const Circle &ncircle );

  void set_pos( double nx, double ny );
  void set_pos( const Point &npos );
  void set_radius( double nradius );

  Point get_pos( void ) const;
  double get_radius( void ) const;

  double get_area( void ) const;

  void print( std::ostream &os ) const;
};

#endif /* __circle_h__ */
