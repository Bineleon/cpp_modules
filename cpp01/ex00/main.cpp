#include "Zombie.hpp"

int main (void)
{
	{
		std::cout << SMGREEN << "\nTest 1 : Stack Zombie before heap Zombie\n" << RESET << std::endl;
		randomChump("stackZombie");
		Zombie* newZ = newZombie("heapZombie");

		delete newZ;
	}
	{
		std::cout << SMGREEN << "\nTest 2 : Heap Zombie before stack Zombie\n" << RESET << std::endl;
		Zombie* newZ = newZombie("heapZombie");
		randomChump("stackZombie");

		delete newZ;
	}

	return (0);
}