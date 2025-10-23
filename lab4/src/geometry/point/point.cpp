#include "point.h"

Point::Point( void ) : x(0), y(0) {}

Point::Point( double n ) : x(n), y(n) {}

Point::Point( double nx, double ny ) : x(nx), y(ny) {}

Point::Point( const Point &npoint ) : x(npoint.x), y(npoint.y) {}

Point::~Point( void ) {}


bool Point::operator==( const Point &np ) const
{
  return (x == np.x && y == np.y);
}

void Point::operator=( const Point &npoint )
{
  x = npoint.x;
  y = npoint.y;
}

double Point::get_x( void ) const
{
  return x;
}

double Point::get_y( void ) const
{
  return y;
}

void Point::set( double nx, double ny )
{
  x = nx, y = ny;
}

void Point::print( std::ostream &os ) const
{
  os << "(" << x << ", " << y << ")";
}

