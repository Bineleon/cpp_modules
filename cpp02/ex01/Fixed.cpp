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

Fixed::Fixed(int const constInt)
{
	std::cout << "Int constructor called" << std::endl;
    _value = (int)roundf(constInt * (1 << _fractionalBits));
    return;
}

Fixed::Fixed(float const constFloat)
{
	std::cout << "Float constructor called" << std::endl;
    _value = (float)roundf(constFloat * (1 << _fractionalBits));
    return;
}

int Fixed::getRawBits() const
{
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

float Fixed::toFloat( void ) const
{
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
    return (int)_value / (1 << _fractionalBits);
}

std::ostream & operator<<(std:: ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}
