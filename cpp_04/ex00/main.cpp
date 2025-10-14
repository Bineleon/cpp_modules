#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

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
	{
		printHeader("Test : Basic");

		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "j type: " << j->getType() << std::endl;
		std::cout << "i type: " << i->getType() << std::endl;

		j->makeSound();
		i->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		printHeader("Test : Copy and assignment");

		Dog dog1;
		Dog dog2(dog1);
		Dog dog3;
		dog3 = dog1;

		Cat cat1;
		Cat cat2(cat1);
		Cat cat3;
		cat3 = cat1;
	}
	{
		printHeader("Test : Const assignment");

		const Animal empty;
		Animal assign;

		assign = empty;
		std::cout << "Assign type: " << assign.getType() << std::endl;
	}
	{
		printHeader("Test : WrongAnimal");

		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		WrongCat wrongCat1;

		std::cout << "WrongAnimal : " << wrongCat->getType() << std::endl;
		wrongCat->makeSound();
		std::cout << "WrongAnimal : " << wrongMeta->getType() << std::endl;
		wrongMeta->makeSound();
		std::cout << "WrongCat sound : " << std::endl;
		wrongCat1.makeSound();

		delete wrongMeta;
		delete wrongCat;
	}

	return 0;
}
