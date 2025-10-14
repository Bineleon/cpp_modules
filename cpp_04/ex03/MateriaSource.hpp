#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& src);
        MateriaSource& operator=(const MateriaSource& rhs);
        ~MateriaSource(void);
        void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
        void initInventory(void);
        void deleteInventory(void);
		void copyInventory(const MateriaSource& rhs);
        AMateria* getInventory(int i);


    private:
        AMateria* _inventory[4];

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
