#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->_ideas[i] = src._ideas[i];
}

Brain& Brain::operator=(const Brain& rhs)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    for (int i = 0; i < 100; ++i)
            this->_ideas[i] = rhs._ideas[i];
    return *this;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const
{
    return _ideas[i];
}

void Brain::setIdea(int i, std::string idea)
{
    _ideas[i] = idea;
}
