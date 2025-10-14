#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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
		printHeader("Test: Valid Form");
        std::srand(time(0));
		Intern someRandomIntern;
        Bureaucrat b1("Bobby", 5);
        try
        {
            AForm* scf;
            AForm* rrf;
            AForm* ppf;
            scf = someRandomIntern.makeForm("shrubbery creation", "nice");
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

            b1.signForm(*scf);
            b1.executeForm(*scf);

            b1.signForm(*rrf);
            b1.executeForm(*rrf);

            b1.signForm(*ppf);
            b1.executeForm(*ppf);

            delete scf;
            delete rrf;
            delete ppf;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
	}
    {
		printHeader("Test: Invalid Form");
		Intern someRandomIntern;
        Bureaucrat b1("Bobby", 12);
        try
        {
            AForm* invalid;
			std::cout << YELLOW << "Trying to create Form \"blabla\" ..." << RESET << std::endl;
            invalid = someRandomIntern.makeForm("blabla", "bibi");

            b1.signForm(*invalid);
            b1.executeForm(*invalid);

            delete invalid;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
	}
	return 0;
}
