#include "HumanB.hpp"

HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL)
{

}

HumanB::~HumanB()
{

}

void HumanB::attack(void)
{
    if (_weapon)
        std::cout << SMBLUE << _name << " attacks with their " << _weapon->getType() << RESET << std::endl;
    else
        std::cout << SMYELLOW << _name << " has no weapon yet 🤷" << RESET << std::endl;
    return;
}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}
