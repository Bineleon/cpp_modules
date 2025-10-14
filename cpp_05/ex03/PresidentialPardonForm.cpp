#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential Pardon", 25, 5), _target("No target")
{
	// std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target): AForm("Presidential Pardon", 25, 5), _target(target)
{
	// std::cout << "PresidentialPardonForm constructor called with target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm("Presidential Pardon", 25, 5), _target(src._target)
{
	// std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "PresidentialPardonForm copy assignment operator not allowed" << std::endl;
	(void) rhs;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::action(void) const
{
    std::cout << SMYELLOW << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
