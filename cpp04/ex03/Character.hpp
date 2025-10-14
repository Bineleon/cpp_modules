#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		typedef struct s_floor
		{
			AMateria			*ptr;
			struct s_floor	    *next;
		}							t_floor;
		t_floor* _floor;
		std::string _name;
		AMateria* _inventory[4];

	public:
		Character(void);
		Character(const Character& src);
		Character(std::string const &name);
		Character& operator=(const Character& rhs);
		~Character(void);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void initInventory(void);
		void addToFloor(AMateria *m);
		void shiftTabLeft(int idx);
		void deleteInventory(void);
		void cleanFloor(void);
		void copyFloor(t_floor* src);
		void copyInventory(const Character& rhs);
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
