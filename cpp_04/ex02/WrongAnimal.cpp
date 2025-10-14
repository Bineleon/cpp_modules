#include "WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal(void): _type("WrongAAnimal")
{
    std::cout << "WrongAAnimal default constructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal(std::string type): _type(type)
{
    std::cout << "WrongAAnimal constructor called with type : " << type << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal& src)
{
    std::cout << "WrongAAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAAnimal& WrongAAnimal::operator=(const WrongAAnimal& rhs)
{
    std::cout << "WrongAAnimal copy assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

WrongAAnimal::~WrongAAnimal(void)
{
    std::cout << "WrongAAnimal destructor called" << std::endl;
}

std::string WrongAAnimal::getType( void ) const
{
    return (_type);
}

void WrongAAnimal::makeSound(void) const
{
    std::cout << "Plop plop i'm an Wronganimal!" << std::endl;
}
