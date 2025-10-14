#include "Zombie.hpp"

Zombie::Zombie(std::string const name) : _name(name)
{
	announce();
}

void Zombie::announce( void )
{
	std::cout << YELLOW << _name << ": " << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << _name << ": " << "DeeeeaaaaaadzzzZ..." << RESET << std::endl;
}

Zombie* newZombie( std::string name )
{
	Zombie*	heapZ = new Zombie(name);
	return heapZ;
}

void randomChump( std::string name )
{
	Zombie stackZ = Zombie(name);
}