#include "Dog.hpp"

Dog::Dog(void): AAnimal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog& src): AAnimal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*src._brain);
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    _type = rhs._type;
    delete _brain;
    _brain = new Brain(*rhs._brain);
    return *this;
}

Dog::~Dog(void)
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Bark bark!" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return _brain;
}