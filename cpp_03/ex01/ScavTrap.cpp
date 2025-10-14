#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("NoName")
{
    std::cout << SMGREEN << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << SMGREEN << "ScavTrap " << name << " constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
    std::cout << SMGREEN << "ScavTrap copy constructor called" << RESET << std::endl;
    *this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    std::cout << SMGREEN << "ScavTrap copy assignment operator called" << RESET << std::endl;
    _name  = rhs._name;
    _hitPoints = rhs._hitPoints;
    _energyPoints = rhs._energyPoints;
    _attackDamage = rhs._attackDamage;
    return *this;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << RED << "ScavTrap " << _name << " destructor called" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!_hitPoints)
    {
        std::cout << SMRED << "ScavTrap " << _name << "'s attack failed because it's DEAD 💀" << RESET << std::endl;
        return;
    }
    if (!_energyPoints)
    {
        std::cout  << SMYELLOW << "ScavTrap " << _name << "'s attack failed: no energy points left 🥱" << RESET << std::endl;
        return;
    }
    std::cout << SMCYAN << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage <<  " points of damage!" << RESET << std::endl;
	_energyPoints--;
    displayPoints();
}

void ScavTrap::guardGate()
{
	if (!_hitPoints)
    {
        std::cout << SMRED << "ScavTrap " << _name << " cannot guard any gate because it's DEAD 💀" << RESET << std::endl;
        displayPoints();
        return;
    }
	if (!_energyPoints)
    {
        std::cout  << SMYELLOW << "ScavTrap " << _name << " cannot guard any gate because it has no energy points left 🥱" << RESET << std::endl;
        displayPoints();
        return;
    }
	std::cout << SMCYAN << "ScavTrap " << _name << " is now in Gate keeper mode" << RESET << std::endl;
    _energyPoints--;
    displayPoints();
}
