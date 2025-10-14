#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	// std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& src): AMateria(src)
{
	// std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure& Cure::operator=(const Cure& rhs)
{
	// std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

Cure::~Cure(void)
{
	// std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << SMGREEN << "* heals " << target.getName() << "’s wounds *" << RESET << std::endl;
}

Cure* Cure::clone() const
{
	return new Cure(*this);
}
