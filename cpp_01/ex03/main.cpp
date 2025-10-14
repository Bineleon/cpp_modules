#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
		std::cout << SMGREEN << "\nTest HumanA\n" << RESET << std::endl;

        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
		std::cout << SMGREEN << "\nTest HumanB\n" << RESET << std::endl;

        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    {
		std::cout << SMGREEN << "\nTest HumanB without weapon\n" << RESET << std::endl;

        HumanB jim("Armless Jim");
        jim.attack();
    }
    return 0;
}
