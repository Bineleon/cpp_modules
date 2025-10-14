#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed(void);
        Fixed(Fixed const & src);
        Fixed(int const constInt);
        Fixed(float const constFloat);
        ~Fixed();
        Fixed & operator=(const Fixed & rhs);
        bool operator>(const Fixed& rhs) const;
        bool operator<(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;
        Fixed operator+(const Fixed & rhs) const;
        Fixed operator-(const Fixed & rhs) const;
        Fixed  operator*(const Fixed & rhs) const;
        Fixed operator/(const Fixed & rhs) const;
        Fixed & operator++();
        Fixed operator++(int);
        Fixed & operator--();
        Fixed operator--(int);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& min(Fixed const & a, Fixed const & b);
        static const Fixed& max(Fixed const & a, Fixed const & b);

    private:
        int _value;
        static const int _fractionalBits = 8;

};

std::ostream & operator<<(std:: ostream & o, Fixed const & rhs);

# define RESET "\033[0m"
# define SMRED "\033[0;31m"
# define SMGREEN "\033[0;32m"
# define SMYELLOW "\033[0;33m"
# define SMBLUE "\033[0;34m"
# define SMMAGENTA "\033[0;35m"
# define SMCYAN "\033[0;36m"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"

#endif
