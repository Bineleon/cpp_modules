#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
    // std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const & src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::Fixed(int const constInt)
{
    _value = (int)(constInt * (1 << Fixed::_fractionalBits));
    return;
}

Fixed::Fixed(float const constFloat)
{
    _value = roundf(constFloat * (1 << Fixed::_fractionalBits));
    return;
}

int Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits( int const raw )
{
    _value = raw;
    return;
}

Fixed & Fixed::operator=(const Fixed & rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
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

bool Fixed::operator>(const Fixed& rhs) const
{
    return _value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return _value < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed & rhs) const
{
    return (*this > rhs || *this == rhs);
}

bool Fixed::operator<=(const Fixed & rhs) const
{
    return (*this < rhs || *this == rhs);
}

bool Fixed::operator==(const Fixed & rhs) const
{
    if (_value == rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed & rhs) const
{
    return !(*this == rhs);
}

Fixed Fixed::operator+(const Fixed & rhs) const
{
    Fixed res;
    res.setRawBits(_value + rhs.getRawBits());
    return res;
}

Fixed Fixed::operator-(const Fixed & rhs) const
{
    Fixed res;
    res.setRawBits(_value - rhs.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed & rhs) const
{
    Fixed res;
    res.setRawBits((_value * rhs.getRawBits()) >> _fractionalBits);
    return res;
}

Fixed Fixed::operator/(const Fixed & rhs) const
{
    Fixed res;
    res.setRawBits((_value << _fractionalBits) / rhs.getRawBits());
    return res;
}

Fixed & Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++*this;
    return (tmp);
}

Fixed & Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp = *this;
    --*this;
    return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::min(Fixed const & a, Fixed const & b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(Fixed const & a, Fixed const & b)
{
    return (a > b) ? a : b;
}
