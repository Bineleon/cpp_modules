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
		printHeader("Test: Operator<<");
		try
		{
			Bureaucrat b;
			std::cout << b << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printHeader("Test: Grade too high");
		try
		{
			Bureaucrat b1("Bob", 0);
			std::cout << "Should never be seen" << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printHeader("Test: Increment");
		try
		{
			Bureaucrat b1("BobHigh", 2);
			b1.incrementGrade();
			b1.incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printHeader("Test: Decrement");
		try
		{
			Bureaucrat b1("BobLow", 149);
			b1.decrementGrade();
			b1.decrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printHeader("Test: Default, Copy and assignment");
		try
		{
            Bureaucrat b;
			Bureaucrat b1("Bob", 1);
			Bureaucrat b2("Bobby", 150);

			Bureaucrat b3(b1);
			Bureaucrat b4 = b2;
            std::cout << SMYELLOW << "Bureaucrat b:		" << b << RESET << std::endl;
			std::cout << SMYELLOW << "Bureaucrat b1:		" << b1 << RESET << std::endl;
			std::cout << SMYELLOW << "Bureaucrat b2:		" << b2 << RESET << std::endl;
			std::cout << SMYELLOW << "Bureaucrat b3(b1): 	" << b3 << RESET << std::endl;
			std::cout << SMYELLOW << "Bureaucrat b4 = b2:	" << b4 << RESET << std::endl;

		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}
