#include "ClapTrap.hpp"
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
	printHeader("Test : ClapTrap construction");
	ClapTrap clap1("Clap");

	printHeader("Test : Attacks ans repare");
	clap1.attack("ennemy");
	clap1.beRepaired(5);

	printHeader("Test : Damages");
	clap1.takeDamage(3);

	printHeader("Test : Copy and affectation");
	ClapTrap clap2;
	clap2 = clap1;
	ClapTrap clap3(clap2);

	printHeader("Test : No hit points");
	ClapTrap clap4("DeadClap");
	clap4.takeDamage(200);
	clap4.attack("Someone");
	clap4.beRepaired(10);

	printHeader("Test : No energy points");
	ClapTrap clap5("NoEnergyClap");
	for (int i = 0; i < 11; ++i)
		clap5.attack("Someone");
	printHeader("Test : Destructors");
	return 0;
}

