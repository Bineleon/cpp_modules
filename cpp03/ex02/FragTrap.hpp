#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(const FragTrap& src);
		FragTrap(std::string name);
        FragTrap& operator=(const FragTrap& rhs);
        ~FragTrap(void);
		void highFivesGuys(void);

    private:

};

#endif
