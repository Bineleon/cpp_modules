#include "Zombie.hpp"

Zombie::Zombie()
{
	// announce();
	return;
}

void Zombie::announce( void )
{
	std::cout << YELLOW << _name << ": " << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << _name << ": " << "DeeeeaaaaaadzzzZ..." << RESET << std::endl;
}

std::string Zombie::getName(void) const
{
	return _name;
}

void Zombie::setName(std::string name)
{
	_name = name;
}