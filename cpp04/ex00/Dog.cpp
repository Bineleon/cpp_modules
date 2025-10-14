#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& src): Animal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Bark bark!" << std::endl;
}
