#include "Cat.hpp"

Cat::Cat(void): AAnimal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat& src): AAnimal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain(*src._brain);
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    _type = rhs._type;
    delete _brain;
    _brain = new Brain(*rhs._brain);
    return *this;
}

Cat::~Cat(void)
{
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Miew Miewwww!" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return _brain;
}