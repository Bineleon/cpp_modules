#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "exceptions.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

template < typename T >
typename T::iterator easyfind(T & container, int toFind)
{
	typename T::iterator it;

	it = find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

// template < typename T >
// typename T::const_iterator easyfind(T & container, int toFind)
// {
// 	typename T::const_iterator it;

// 	it = find(container.begin(), container.end(), toFind);
// 	if (it == container.end())
// 		throw NotFoundException();
// 	return it;
// }

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

#endif
