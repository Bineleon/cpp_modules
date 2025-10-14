#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy Request", 72, 45), _target("No target")
{
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target): AForm("Robotomy Request", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm constructor called with target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm("Robotomy Request", 72, 45), _target(src._target)
{
	// std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "RobotomyRequestForm copy assignment operator not allowed" << std::endl;
	(void) rhs;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// void RobotomyRequestForm::execute(Bureaucrat const & executor) const
// {
// 	if (!getSigned())
// 		throw IsNotSignedException();
// 	else if (executor.getGrade() > getExeGrade())
// 		throw GradeTooLowException();
// 	action();
// }

void RobotomyRequestForm::action(void) const
{
	if (std::rand() % 2 == 0)
		throw RobotomyFailedException();
	else
		std::cout << SMYELLOW << "Driilllllllllll Zzz Brrrrr : " << _target << " has been robotomized successfully !" << RESET << std::endl;
}
