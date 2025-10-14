#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		printHeader("Test: Shrubbery Creation Form execution");
		AForm *shrub = new ShrubberyCreationForm("home");
		Bureaucrat b1("Bob", 50);
		Bureaucrat b2("Bobby", 120);

		b2.signForm(*shrub);
		b1.executeForm(*shrub);

		delete shrub;
	}
	{
		printHeader("Test: Robotomy Request Form execution");
		std::srand(time(0));
		AForm *robotomy = new RobotomyRequestForm("Bender");
		Bureaucrat b1("Bob", 45);
		Bureaucrat b2("Bobby", 72);

		b2.signForm(*robotomy);
		std::cout<< SMYELLOW << "Executing \"Robotomy Request\" form 10 times..." << std::endl;
		for (int i = 0; i < 10; i++)
		{
			b1.executeForm(*robotomy);
		}
		delete robotomy;
	}
	{
		printHeader("Test: Presidential Pardon Form execution");
		AForm *pardon = new PresidentialPardonForm("Bibi");
		Bureaucrat b1("Bob", 5);
		Bureaucrat b2("Bobby", 25);

		b2.signForm(*pardon);
		b1.executeForm(*pardon);

		delete pardon;
	}
	{
		printHeader("Test: Bureaucrat grade to low to execute");
		AForm *pardon = new PresidentialPardonForm("Bibi");
		Bureaucrat b1("Bob", 45);
		Bureaucrat b2("Bobby", 35);

		b2.signForm(*pardon);
		b1.executeForm(*pardon);

		delete pardon;
	}
    {
		printHeader("Test: Copy AForm");
		RobotomyRequestForm f1("Bender");
        RobotomyRequestForm f2(f1);
        Bureaucrat b1("Bob", 45);
		Bureaucrat b2("Bobby", 35);

        std::cout << "For f1 : " << f1 << std::endl;
		b2.signForm(f1);
		b1.executeForm(f1);

        std::cout << "For f2 : " << f2 << std::endl;
        b2.signForm(f2);
		b1.executeForm(f2);

	}
	return 0;
}
