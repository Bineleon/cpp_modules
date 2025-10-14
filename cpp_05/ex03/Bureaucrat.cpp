#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("Random"), _grade(150)
{
    // std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name), _grade(grade)
{
	// std::cout << "Bureaucrat constructor called with name : " << name << " and grade : " << grade << std::endl;
		if (_grade > 150)
			throw GradeTooLowException();
		else if (_grade < 1)
			throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name), _grade(src._grade)
{
    // std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    // std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat \"" << _name << "\" destructor called" << std::endl;
}

std::string const Bureaucrat::getName(void) const
{
	return _name;
}

int	Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::incrementGrade(void)
{
		std::cout << SMYELLOW << "Incrementing " << _name << "\'s grade..." << RESET << std::endl;
		if ((_grade - 1) < 1)
			throw GradeTooHighException();
		else
			_grade--;
}

void Bureaucrat::decrementGrade(void)
{
		std::cout << SMYELLOW << "Decrementing " << _name << "\'s grade..." << RESET << std::endl;
		if ((_grade + 1) > 150)
			throw GradeTooLowException();
		else
			_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << SMYELLOW << _name << " signed " << form.getName() << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << SMRED << _name << " couldn’t sign " << form.getName() << " because " << e.what() << RESET << std::endl;
    }

}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << SMGREEN << _name << " executed " << form.getName() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << SMRED << _name << " could not execute " << form.getName() << " because " << e.what() << RESET << std::endl;
    }

}

std::ostream & operator<<(std:: ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return o;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("\033[0;31mGrade too high ! Must be between [1-150]\033[0m");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("\033[0;31mGrade too low ! Must be between [1-150]\033[0m");
}
