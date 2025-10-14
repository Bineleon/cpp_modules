#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
	public:
	class FormCreationFailedException: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
		Intern(void);
		Intern(const Intern& src);
		Intern& operator=(const Intern& rhs);
		~Intern(void);
		AForm* makeForm(std::string const name, std::string const target);
	private:
		static AForm* createShrubForm(std::string const & target);
		static AForm* createRobotForm(std::string const & target);
		static AForm* createPresidForm(std::string const & target);

};
typedef AForm* (*functPtr)(const std::string&);


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
