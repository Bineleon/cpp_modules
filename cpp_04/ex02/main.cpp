#include <iomanip>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

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
	// {
	// 	printHeader("Test : Animal instance (should fail)");
	// 	const AAnimal* i = new AAnimal();
	
	// 	delete i;
	// }
	{
		printHeader("Test : Construction / Destruction");
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
	
		delete j;
		delete i;
	}
    {
		printHeader("Test : Half cat, half Dog AAnimal array");

        int size = 10;
        const AAnimal* animals[size];

        for (int i = 0; i < size; i++)
        {
            if (i < size / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        for (int i = 0; i < size; i++)
            animals[i]->makeSound();

        for (int i = size - 1; i >= 0; i--)
        {
            std::cout << "Destroying animal : " << animals[i]->getType() << std::endl;
            delete animals[i];
        }
    }
	{
		printHeader("Test : Deep copy Cat");

		Cat cat1;
		cat1.getBrain()->setIdea(0, "Play with cork");
		std::cout << "Cat1 idea[0] : " << cat1.getBrain()->getIdea(0) << std::endl;
		Cat cat2(cat1);
		std::cout << "Cat2 idea[0] : " << cat2.getBrain()->getIdea(0) << std::endl;

		cat1.getBrain()->setIdea(0, "I don't like water");
		std::cout << "Cat1 idea[0] : " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat2 idea[0] : " << cat2.getBrain()->getIdea(0) << std::endl;

	}
	{
		printHeader("Test : Deep copy Dog");
		
		Dog dog1;
		dog1.getBrain()->setIdea(0, "Play with ball");
		std::cout << "Dog1 idea[0] : " << dog1.getBrain()->getIdea(0) << std::endl;
		Dog dog2(dog1);
		std::cout << "Dog2 idea[0] : " << dog2.getBrain()->getIdea(0) << std::endl;

		dog1.getBrain()->setIdea(0, "I like playing with balls");
		std::cout << "Dog1 idea[0] : " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Dog2 idea[0] : " << dog2.getBrain()->getIdea(0) << std::endl;
	}
    return 0;
}
