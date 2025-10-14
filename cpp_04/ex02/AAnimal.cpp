#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type("AAnimal")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
    std::cout << "AAnimal constructor called with type : " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = src;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal type : " << _type <<  " destructor called" << std::endl;
}

std::string AAnimal::getType( void ) const
{
    return (_type);
}

void AAnimal::makeSound(void) const
{
    std::cout << "Plop plop i'm an animal!" << std::endl;
}
