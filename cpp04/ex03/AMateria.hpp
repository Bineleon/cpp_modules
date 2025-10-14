#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "Character.hpp"

class ICharacter;
class AMateria
{
    public:
        AMateria(void);
		AMateria(std::string const & type);
        AMateria(const AMateria& src);
        AMateria& operator=(const AMateria& rhs);
        virtual ~AMateria(void);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

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
