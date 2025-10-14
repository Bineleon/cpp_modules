#include "Intern.hpp"

Intern::Intern(void)
{
    // std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& src)
{
    // std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
}

Intern& Intern::operator=(const Intern& rhs)
{
    // std::cout << "Intern copy assignment operator called" << std::endl;
    (void) rhs;
    return *this;
}

Intern::~Intern(void)
{
    // std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubForm(std::string const & target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotForm(std::string const & target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidForm(std::string const & target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const name, std::string const target)
{
    const std::string* formNames = AForm::getForms();
    functPtr functions[3] = {&Intern::createShrubForm, &Intern::createRobotForm, &Intern::createPresidForm};

    for (int i = 0; i < 3; i++)
    {
        if (name == formNames[i])
		{
			std::cout << SMYELLOW << "Intern creates form " << name << RESET<< std::endl; 
            return (*functions[i])(target);
		}
    }
    throw FormCreationFailedException();
    return NULL;
}

const char* Intern::FormCreationFailedException::what() const throw()
{
    return ("\033[0;31mForm creation failed beacause form does not exist !\033[0m");
}
