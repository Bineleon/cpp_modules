#include "Fixed.hpp"
#include <iomanip>

void printHeader(const std::string& str)
{
	int size = 50;
	int totalPad = size - str.size();
	(totalPad < 0) ? totalPad = 0 : totalPad;
	int lPad = totalPad / 2;
	int rPad = totalPad - lPad;

	std::cout << std::endl << SMGREEN;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setfill(' ') << std::setw(lPad + str.size()) << str << std::setw(rPad) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << RESET << std::endl;
}

int main( void )
{
	{
		printHeader("Test 1 :++, *, max()");
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << " a             : " << a << std::endl;
		std::cout << " ++a           : " << ++a << std::endl;
		std::cout << " a             : " << a << std::endl;
		std::cout << " a++           : " << a++ << std::endl;
		std::cout << " a             : " << a << std::endl;
		std::cout << " b             : " << b << std::endl;

		std::cout << " max( a, b )   : " << Fixed::max( a, b ) << std::endl;
	}
	{
		printHeader("Test 2 : --, /, min()");
		Fixed a;
		Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );

		std::cout << " a             : " << a << std::endl;
		std::cout << " --a           : " << --a << std::endl;
		std::cout << " a             : " << a << std::endl;
		std::cout << " a--           : " << a-- << std::endl;
		std::cout << " a             : " << a << std::endl;
		std::cout << " b             : " << b << std::endl;

		std::cout << " min( a, b )   : " << Fixed::min( a, b ) << std::endl;

		std::cout << " a < b         : " << (a < b) << std::endl;
	}
	{
		printHeader("Test 3 : +, - ");
		Fixed a(1.25f);
		Fixed const b( Fixed( 5.5f ) / Fixed( 2 ) );

		std::cout << " a             : " << a << std::endl;
		std::cout << " b             : " << b << std::endl;
		std::cout << " a + b         : " << a + b << std::endl;
		std::cout << " a - b         : " << a - b << std::endl;
		std::cout << " a--           : " << a-- << std::endl;
		std::cout << " a             : " << a << std::endl;
	}
	{
		printHeader("Test 4 : ==, !=, >=, <=, >, <");
		Fixed a(-1);
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		Fixed c(a);

		std::cout << " a             : " << a << std::endl;
		std::cout << " b             : " << b << std::endl;
		std::cout << " a == b        : " << (a == b) << std::endl;
		std::cout << " a != b        : " << (a != b) << std::endl;
		std::cout << " a >= b        : " << (a >= b) << std::endl;
		std::cout << " a <= b        : " << (a <= b) << std::endl;
		std::cout << " a > b         : " << (a > b) << std::endl;
		std::cout << " a < b         : " << (a < b) << std::endl;
		std::cout << " c             : " << c << std::endl;
		std::cout << " a == c        : " << (a == c) << std::endl;
		std::cout << " a != c        : " << (a != c) << std::endl;
		std::cout << " a >= c        : " << (a >= c) << std::endl;
		std::cout << " a <= c        : " << (a <= c) << std::endl;
		std::cout << " a > c         : " << (a > c) << std::endl;
		std::cout << " a < c         : " << (a < c) << std::endl;
	}
	{
		printHeader("Test 5 : Non-const objects");
		Fixed a(3.5f);
		Fixed b(4.25f);

		std::cout << " a             : " << a << std::endl;
		std::cout << " b             : " << b << std::endl;

		std::cout << " max(a, b)     : " << Fixed::max(a, b) << std::endl;
		std::cout << " min(a, b)     : " << Fixed::min(a, b) << std::endl;

		std::cout << " a * b         : " << a * b << std::endl;
		std::cout << " a / b         : " << a / b << std::endl;

		std::cout << " a >= b        : " << (a >= b) << std::endl;
		std::cout << " a <= b        : " << (a <= b) << std::endl;
	}
	return 0;
}

/*
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
*/
