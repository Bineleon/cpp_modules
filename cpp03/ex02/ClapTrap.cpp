#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("noName"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << SMGREEN << "ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << SMGREEN << "ClapTrap " << name << " constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
    std::cout << SMGREEN << "ClapTrap copy constructor called" << RESET << std::endl;
    *this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << SMGREEN << "ClapTrap copy assignment operator called" << RESET << std::endl;

    _name = rhs._name;
    _hitPoints = rhs._hitPoints;
    _energyPoints = rhs._energyPoints;
    _attackDamage = rhs._attackDamage;

    return *this;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << RED << "ClapTrap " << _name << " destructor called" << RESET << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if (!_hitPoints)
    {
        std::cout << SMRED << "ClapTrap " << _name << "'s attack failed because it's DEAD 💀" << RESET << std::endl;
        return;
    }
    if (!_energyPoints)
    {
        std::cout  << SMYELLOW << "ClapTrap " << _name << "'s attack failed: no energy points left 🥱" << RESET << std::endl;
        return;
    }
    std::cout << SMCYAN << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage <<  " points of damage!" << RESET << std::endl;
    _energyPoints--;
    displayPoints();
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!_hitPoints )
    {
        std::cout << SMYELLOW << "Stop attacking this poor " << _name << " it's already dead !! 💀" << RESET<< std::endl;
        return;
    }
    if (_hitPoints - (int)amount <= 0)
    {
        _hitPoints = 0;
        std::cout << RED << "ClapTrap " << _name << " got hit, lost all it's hit points and died 💀" << RESET << std::endl;
        return;
    }
    _hitPoints -= amount;
    std::cout << SMYELLOW << "ClapTrap " << _name << " got hit and lost " << amount << " hit points" << RESET << std::endl;
    displayPoints();
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!_energyPoints)
    {
        std::cout  << YELLOW << "ClapTrap " << _name << "'s repair failed: no energy points left 🥱" << RESET << std::endl;
        return;
    }
    if (!_hitPoints)
        std::cout << SMGREEN << "ClapTrap " << _name << " repaired itself and ROSE FROM THE DEAD 🧟🧟🧟 ! Gaining : " << amount <<  " hit points!" << RESET << std::endl;
    else
        std::cout << SMGREEN << "ClapTrap " << _name << " repaired itself" << ", gaining " << amount <<  " hit points!" << RESET << std::endl;
    _hitPoints += amount;
    _energyPoints--;
    displayPoints();
}

void ClapTrap::displayPoints(void)
{
    std::cout << SMMAGENTA << "EP : " << _energyPoints << std::endl;
    std::cout << "HP : " << _hitPoints << RESET << std::endl;
}
