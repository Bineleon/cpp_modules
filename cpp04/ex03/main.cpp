#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iomanip>

void printHeader(const std::string& str)
{
	int size = 56;
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
	{
		printHeader("Test : Basic");

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		printHeader("Test : MateriaSource inventory capacity");

		IMateriaSource* src = new MateriaSource();
		for (int i = 0; i < 6; i++)
		{
			if (i == 0 || i % 2 == 0)
				src->learnMateria(new Ice());
			else
				src->learnMateria(new Cure());
		}
		std::cout << SMYELLOW << "Checking inventory :" << RESET << std::endl;
		for (int i = 0; i < 6; i++)
		{		
			AMateria *m = dynamic_cast<MateriaSource*>(src)->getInventory(i);
			if (m)
				std::cout << SMYELLOW << "At index : " << i << ", Materia : " << m->getType() << RESET << std::endl;
			else
				std::cout << SMRED << "Inventory full capacity reached : Nothing there" << RESET << std::endl;
		}

		printHeader("Test : Character inventory capacity + using materia");

		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		for (int i = 0; i < 6; i++)
		{
			AMateria *m2;
			if (i == 0)
				m2 = src->createMateria("blob");
			else if (i % 2 == 0)
				m2 = src->createMateria("ice");
			else
				m2 = src->createMateria("cure");
			if (m2)
				me->equip(m2);
		}
		std::cout << SMYELLOW << "me use 0 on Bob" << RESET << std::endl;
		me->use(0, *bob);
		std::cout << SMYELLOW << "me use 1 on Bob" << RESET << std::endl;
		me->use(1, *bob);
		std::cout << SMYELLOW << "me use 6 on Bob" << RESET << std::endl;
		me->use(6, *bob);

		printHeader("Test : Character unequiping");

		std::cout << SMYELLOW << "me unequip 0..." << RESET << std::endl;
		me->unequip(0);
		std::cout << SMYELLOW << "Using 0...(should work)" << RESET << std::endl;
		me->use(0, *bob);
		std::cout << SMYELLOW << "Using 3...(should not work)" << RESET << std::endl;
		me->use(3, *bob);
		std::cout << SMYELLOW << "me unequip 6...(should not work)" << RESET << std::endl;
		me->unequip(6);

		printHeader("Test : Copy and assignations");
		std::cout << SMYELLOW << "Creating ICharacter* clone from Character* me..." << RESET << std::endl;
		ICharacter* clone = new Character(*static_cast<Character*>(me));
		std::cout << SMYELLOW << "Using clone materia : " << RESET << std::endl;
		clone->use(0, *bob);
		clone->use(1, *bob);
		
		printHeader("Test : Equipment");

		ICharacter* bibi = new Character("bibi");
		AMateria* m3;

		std::cout << SMYELLOW << "Creating wrong materia..." << RESET << std::endl;
		m3 = src->createMateria("Cure");
		m3 = src->createMateria("Ice");
		std::cout << SMYELLOW << "Equip with unexisting materia..." << RESET << std::endl;
		bibi->equip(m3);
		std::cout << SMYELLOW << "Unequip unexisting materia..." << RESET << std::endl;
		bibi->unequip(0);
		std::cout << SMYELLOW << "Equiping with same materia*..." << RESET << std::endl;
		m3 = src->createMateria("cure");
		bibi->equip(m3);
		bibi->equip(m3);
		std::cout << SMYELLOW << "Using existing materia..." << RESET << std::endl;

		bibi->use(0, *bob);
		std::cout << SMYELLOW << "Using unexisting materia..." << RESET << std::endl;
		bibi->use(1, *bob);
		bibi->use(4, *bob);
		std::cout << SMYELLOW << "Creating and equiping materias with reassigned materia*..." << RESET << std::endl;
		m3 = src->createMateria("cure");
		bibi->equip(m3);
		m3 = src->createMateria("ice");
		bibi->equip(m3);
		m3 = src->createMateria("ice");
		bibi->equip(m3);
		m3 = src->createMateria("ice");
		bibi->equip(m3);
		bibi->equip(0);

		delete clone;
		delete bibi;
		delete bob;
		delete me;
		delete src;
	}
	
	return 0;
}
