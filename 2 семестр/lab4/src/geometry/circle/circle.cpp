#define _USE_MATH_DEFINES
#include <cmath>

#include "circle.h"


Circle::Circle( void ) : center(), radius(0) {}

Circle::Circle( double nradius ) : center(), radius(nradius) {}

Circle::Circle( double n, double nradius ) : center(n), radius(nradius) {}

Circle::Circle( double nx, double ny, double nradius ) : center(nx, ny), radius(nradius) {}

Circle::Circle( Point nc, double nradius ) : center(nc), radius(nradius) {}

Circle::Circle( const Circle &ncircle ) : center(ncircle.center), radius(ncircle.radius) {}

Circle::~Circle( void ) {}


bool Circle::operator==( const Circle &nc ) const
{
  return (center == nc.center && radius == nc.radius);
}

void Circle::operator=( const Circle &ncircle )
{
  center = ncircle.center;
  radius = ncircle.radius;
}

void Circle::set_pos( double nx, double ny )
{
  center.set(nx, ny);
}

void Circle::set_pos( const Point &npos )
{
  center = npos;
}

void Circle::set_radius( double nradius )
{
  radius = nradius;
}

Point Circle::get_pos( void ) const
{
  return center;
}

double Circle::get_radius( void ) const
{
  return radius;
}

double Circle::get_area( void ) const
{
  return M_PI * radius * radius;
}


void Circle::print( std::ostream &os ) const
{
  os << "Circle: center = ";
  center.print(os);
  os << ", radius = " << radius << ", area = " << get_area();
}

