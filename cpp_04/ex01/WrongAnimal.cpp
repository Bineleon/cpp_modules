#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
    std::cout << "WrongAnimal constructor called with type : " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
    return (_type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Plop plop i'm an Wronganimal!" << std::endl;
}
