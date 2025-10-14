#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& src): Animal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}


void Cat::makeSound(void) const
{
    std::cout << "Miew Miewwww!" << std::endl;
}
