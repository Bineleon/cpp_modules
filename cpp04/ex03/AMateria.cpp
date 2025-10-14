#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void): _type("Materia")
{
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	// std::cout << "AMateria constructor called with type : " << type << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

AMateria::~AMateria(void)
{
	// std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << SMBLUE << "AMateria : \"* does something to " << target.getName() << " *\"" << RESET << std::endl;
}
