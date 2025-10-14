#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits( int const raw )
{
    _value = raw;
    return;
}

Fixed & Fixed::operator=(const Fixed & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = rhs.getRawBits();

    return *this;
}
