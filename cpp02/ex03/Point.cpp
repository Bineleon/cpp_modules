#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
    return;
}

Point::Point(float const x, float const y): _x(x), _y(y)
{
    return;
}

Point::Point(Point const & src)
{
    *this = src;
    return;
}

Point::~Point()
{

}

Fixed const & Point::getX(void) const
{
    // std::cout << "getX member function called" << std::endl;
    return _x;
}

Fixed const & Point::getY(void) const
{
    // std::cout << "getX member function called" << std::endl;
    return _y;
}

Point & Point::operator=(const Point & rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    _x = rhs.getX();
    _y  = rhs.getY();
    return *this;
}
