#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
    // std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& src): AMateria(src)
{
    // std::cout << "Ice copy constructor called" << std::endl;
    *this = src;
}

Ice& Ice::operator=(const Ice& rhs)
{
    // std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

Ice::~Ice(void)
{
    // std::cout << "Ice destructor called" << std::endl;
}

void Ice::use(ICharacter& target)
{
    std::cout << SMCYAN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}

Ice* Ice::clone() const
{
    return new Ice(*this);
}
