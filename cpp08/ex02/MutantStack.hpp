#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>

template <typename T, typename C = std::deque<T> >
class MutantStack: public std::stack<T, C>
{
    public:
        MutantStack(void){}
        MutantStack(const MutantStack& src): std::stack<T>(src) {}
        explicit MutantStack(const C& container): std::stack<T, C>(container) {}
        MutantStack& operator=(const MutantStack& rhs)
        {
            std::stack<T>::operator=(rhs);
            return *this;
        }
        ~MutantStack(void){}

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }
        const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const_reverse_iterator rend() const { return this->c.rend(); }
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
