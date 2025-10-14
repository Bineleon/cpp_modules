#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iomanip>

void printHeader(const std::string& str)
{
	int size = 50;
	int totalPad = size - str.size();
	(totalPad < 0) ? totalPad = 0 : totalPad;
	int lPad = totalPad / 2;
	int rPad = totalPad - lPad;

	std::cout << std::endl << SMGREEN;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setfill(' ') << std::setw(lPad + str.size()) << str << std::setw(rPad) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << RESET << std::endl;
}

int main(void)
{
    printHeader("Test : ClapTrap ScavTrap and FragTrap constructions");
    ClapTrap clap1("Clap");
    ScavTrap scav1("Scav");
    FragTrap frag1("Frag");

    printHeader("Test : Attacks ans repare");
    clap1.attack("ennemy");
    scav1.attack("other ennemy");
    frag1.attack("another ennemy");
    clap1.beRepaired(5);
    scav1.beRepaired(10);
    frag1.beRepaired(20);

    printHeader("Test : Damages");
    clap1.takeDamage(3);
    scav1.takeDamage(20);
    frag1.takeDamage(30);

    printHeader("Test : Special functions");
    scav1.guardGate();
    frag1.highFivesGuys();

    printHeader("Test : Copy and affectation");
    FragTrap frag2(frag1);
    FragTrap frag3;
    frag3 = frag1;

    printHeader("Test : No hit points");
    FragTrap frag4("DeadFrag");
    frag4.takeDamage(200);
    frag4.attack("Someone");
    frag4.highFivesGuys();
    frag4.beRepaired(10);
    frag4.highFivesGuys();

    printHeader("Test : No energy points");
    FragTrap frag5("NoEnergyFrag");
    for (int i = 0; i < 101; ++i)
        frag5.attack("Someone");
    frag5.highFivesGuys();

    printHeader("Test : Destructors");
    return 0;
}
