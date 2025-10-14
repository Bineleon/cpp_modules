#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("NoName")
{
    std::cout << SMGREEN << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << SMGREEN << "FragTrap " << name << " constructor called" << RESET << std::endl;
    _hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& src)
{
    std::cout << SMGREEN << "FragTrap copy constructor called" << RESET << std::endl;
    *this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    std::cout << SMGREEN << "FragTrap copy assignment operator called" << RESET << std::endl;
    _name  = rhs._name;
    _hitPoints = rhs._hitPoints;
    _energyPoints = rhs._energyPoints;
    _attackDamage = rhs._attackDamage;
    return *this;
}

FragTrap::~FragTrap(void)
{
    std::cout << RED << "FragTrap " << _name << " destructor called" << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (!_hitPoints)
    {
        std::cout << SMRED << "FragTrap " << _name << " cannot request an high five because it's DEAD 💀" << RESET << std::endl;
        displayPoints();
        return;
    }
	if (!_energyPoints)
    {
        std::cout  << SMYELLOW << "FragTrap " << _name << " cannot request an high five because it has no energy points left 🥱" << RESET << std::endl;
        displayPoints();
        return;
    }
	std::cout << SMCYAN << "FragTrap " << _name << " is requesting an awosome HIGH FIVE ! 🖐️" << RESET << std::endl;
    _energyPoints--;
    displayPoints();
}
