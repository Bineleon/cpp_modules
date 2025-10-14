#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class NotFoundException: public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return "Value not found";
	}
};

#endif