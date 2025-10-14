#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
    std::cout << "Animal constructor called with type : " << type << std::endl;
}

Animal::Animal(const Animal& src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal& Animal::operator=(const Animal& rhs)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

Animal::~Animal(void)
{
    std::cout << "Animal type : " << _type <<  " destructor called" << std::endl;
}

std::string Animal::getType( void ) const
{
    return (_type);
}

void Animal::makeSound(void) const
{
    std::cout << "Plop plop i'm an animal!" << std::endl;
}
