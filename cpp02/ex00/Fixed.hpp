#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(Fixed const & src);
        Fixed & operator=(const Fixed & rhs);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        ~Fixed();

    private:
        int _value;
        static const int __fractionalBits = 8;

};

#endif
