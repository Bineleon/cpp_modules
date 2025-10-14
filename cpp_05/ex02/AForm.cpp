#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _signed(false), _signGrade(1), _exeGrade(1)
{
    // std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int const signGrade, int const exeGrade): _name(name), _signed(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
	// std::cout << "AForm constructor called with min SG: " << signGrade << ", and min EG: " << exeGrade << std::endl;
	if (signGrade > 150 || exeGrade > 150)
			throw GradeTooLowException();
	else if (signGrade < 1 || exeGrade < 1)
			throw GradeTooHighException();
}

AForm::AForm(const AForm& src): _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _exeGrade(src._exeGrade)
{
    // std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
    // std::cout << "AForm copy assignment operator called" << std::endl;
    _signed = rhs._signed;
    return *this;
}

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl;
}

std::string const AForm::getName(void) const
{
	return _name;
}

bool AForm::getSigned(void) const
{
	return _signed;
}

int AForm::getSignGrade(void) const
{
	return _signGrade;
}

int AForm::getExeGrade(void) const
{
	return _exeGrade;
}

void AForm::beSigned(Bureaucrat const & b)
{
    if (_signed)
        throw IsSignedException();
	else if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw IsNotSignedException();
    else if (executor.getGrade() > _exeGrade)
        throw GradeTooLowException();
    action();
}

std::ostream & operator<<(std:: ostream & o, AForm const & rhs)
{
	std::string status;

	if (rhs.getSigned())
		status = "signed";
	else
		status = "not signed";

    o << SMYELLOW << "AForm \"" << rhs.getName() <<  "\" is : " << status << ", requiered grade to sign: " << rhs.getSignGrade() << ", requiered grade to execute: " << rhs.getExeGrade() << "." << RESET;
    return o;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("\033[0;31mGrade too high !\033[0m");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("\033[0;31mGrade too low !\033[0m");
}

const char* AForm::IsSignedException::what() const throw()
{
    return ("\033[0;31mthe form is already signed !\033[0m");
}

const char* AForm::IsNotSignedException::what() const throw()
{
    return ("\033[0;31mthe form is not signed yet !\033[0m");
}

const char* AForm::RobotomyFailedException::what() const throw()
{
    return ("\033[0;31mRobotomy failed\033[0m");
}
