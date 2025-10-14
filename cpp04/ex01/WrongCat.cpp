#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Miew Miewwww!" << std::endl;
}
