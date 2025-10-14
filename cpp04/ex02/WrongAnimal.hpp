#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAAnimal
{
    public:
        WrongAAnimal(void);
        WrongAAnimal(std::string type);
        WrongAAnimal(const WrongAAnimal& src);
        WrongAAnimal& operator=(const WrongAAnimal& rhs);
        ~WrongAAnimal(void);
		void makeSound(void) const;
        std::string getType( void ) const;

    protected:
		std::string _type;

};

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
