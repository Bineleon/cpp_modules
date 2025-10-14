#include "Form.hpp"
#include "Bureaucrat.hpp"

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
		printHeader("Test: Form operator<<");
		try
		{
			Form f1("Some form", 20, 10);
			Form f2("Some form", 30, 10);
			Form f3("Some form", 10, 10);

			std::cout << f1 << std::endl;
			std::cout << f2 << std::endl;
			std::cout << f3 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printHeader("Test: Bureaucrat sign multiple forms");
		try
		{
			Bureaucrat b1("Bob", 20);
			Form f1("Some form 20", 20, 10);
			Form f2("Some form 30", 30, 10);
			Form f3("Some form 10", 10, 10);

			b1.signForm(f1);
			b1.signForm(f2);
			b1.signForm(f3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printHeader("Test: Form already signed");
		try
		{
			Bureaucrat b1("Bob", 20);
			Form f1("Some form", 20, 10);

			b1.signForm(f1);
			b1.signForm(f1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printHeader("Test: Form sign grade out of bounds");
		try
		{
			Bureaucrat b1("Bob", 20);
			std::cout << YELLOW << "Trying to instanciate Form with SG : 200 ..." << RESET << std::endl;
			Form f1("Some form", 200, 5);

			std::cout << "Should never be seen" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printHeader("Test: Form exececution grade out of bounds");
		try
		{
			Bureaucrat b1("Bob", 20);
			std::cout << YELLOW << "Trying to instanciate Form with EG : 0 ..." << RESET << std::endl;
			Form f1("Some form", 20, 0);

			std::cout << "Should never be seen" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printHeader("Test: Bureaucrat grade too low to sign");
		try
		{
			Bureaucrat b1("Bob", 30);
			Form f1("Some form", 20, 10);

			b1.signForm(f1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
