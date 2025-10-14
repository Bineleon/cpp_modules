#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _signed(false), _signGrade(1), _exeGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int const signGrade, int const exeGrade): _name(name), _signed(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
	std::cout << "Form constructor called with min SG: " << signGrade << ", and min EG: " << exeGrade << std::endl;
	if (signGrade > 150 || exeGrade > 150)
			throw GradeTooLowException();
	else if (signGrade < 1 || exeGrade < 1)
			throw GradeTooHighException();
}

Form::Form(const Form& src): _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _exeGrade(src._exeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	_signed = rhs._signed;
	return *this;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

std::string const Form::getName(void) const
{
	return _name;
}

bool Form::getSigned(void) const
{
	return _signed;
}

int Form::getSignGrade(void) const
{
	return _signGrade;
}

int Form::getExeGrade(void) const
{
	return _exeGrade;
}

void Form::beSigned(Bureaucrat const & b)
{
	if (_signed)
		throw IsSignedException();
	else if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

std::ostream & operator<<(std:: ostream & o, Form const & rhs)
{
	std::string status;

	if (rhs.getSigned())
		status = "signed";
	else
		status = "not signed";

	o << SMYELLOW << "Form \"" << rhs.getName() <<  "\" is : " << status << ", requiered grade to sign: " << rhs.getSignGrade() << ", requiered grade to execute: " << rhs.getExeGrade() << "." << RESET;
	return o;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("\033[0;31mGrade too high !\033[0m");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("\033[0;31mGrade too low !\033[0m");
}

const char* Form::IsSignedException::what() const throw()
{
	return ("\033[0;31mthe form is already signed !\033[0m");
}
