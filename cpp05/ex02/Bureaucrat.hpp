#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat
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
	Bureaucrat(void);
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat(void);
	std::string const getName(void) const;
	int	getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm &form);
    void executeForm(AForm const & form);


    private:
	std::string	const _name;
	int	_grade;

};

std::ostream & operator<<(std:: ostream & o, Bureaucrat const & rhs);

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
