#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <fstream>

class Bureaucrat;

class AForm
{
	public:
	class GradeTooHighException: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class IsSignedException: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
    class IsNotSignedException: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
    class RobotomyFailedException: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
		AForm(void);
		AForm(const AForm& src);
		AForm(std::string name, int const signGrade, int const exeGrade);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm(void);
		std::string const getName(void) const;
		bool getSigned(void) const;
		int	getSignGrade(void) const;
		int	getExeGrade(void) const;
		void beSigned(Bureaucrat const & b);
        void execute(Bureaucrat const & executor) const;
        virtual void action(void) const = 0;

	private:
		std::string const _name;
		bool _signed;
		int const _signGrade;
		int const _exeGrade;

};

std::ostream & operator<<(std:: ostream & o, AForm const & rhs);


# define RESET "\033[0m"
# define SMRED "\033[0;31m"
# define SMGREEN "\033[0;32m"
# define SMYELLOW "\033[0;33m"
# define SMBLUE "\033[0;34m"
# define SMMAGENTA "\033[0;35m"
# define SMCYAN "\033[0;36m"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"

#endif
