#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template < typename T >
class Array
{
	public:
		class IndexOutOfBoundException: public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("Index out of bound");
			}
		};
		Array(void): _n(0), _array(NULL) {}
		Array(unsigned int n): _n(n)
		{
			_array = new T[n];
		}
		Array(const Array& src)
		{
			_n = src._n;
			_array = new T[src._n];
			for (unsigned int i = 0; i < _n; ++i)
				_array[i] = src._array[i];
		}
		Array& operator=(const Array& rhs)
		{
			if (this != &rhs)
			{
				delete [] _array;
				_n = rhs._n;
				_array = new T[rhs._n];
				for (unsigned int i = 0; i < _n; ++i)
					_array[i] = rhs._array[i];
			}
			return *this;
		}
		~Array(void)
		{
			delete [] _array;
		}
		T & operator[] (unsigned i)
		{
			if (i >= _n)
				throw IndexOutOfBoundException();
			return _array[i];
		}
		const T & operator[] (unsigned i) const
		{
			if (i >= _n)
				throw IndexOutOfBoundException();
			return _array[i];
		}
		unsigned int const & size(void) const
		{
			return _n;
		}

	private:
		unsigned int _n;
		T *_array;
};

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
