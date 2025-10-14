#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template < typename T, typename U >
void iter(T *array, size_t const & lenArray, U (*func))
{
    for (size_t i = 0; i < lenArray; i++)
    {
        func(array[i]);
    }
}

template < typename T >
void printElement(T const & element)
{
    std::cout << element << std::endl;
}

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
