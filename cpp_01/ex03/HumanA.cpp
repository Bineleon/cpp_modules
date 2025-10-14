#include "HumanA.hpp"

HumanA::HumanA(std::string const name, Weapon & weapon) : _name(name), _weapon(weapon)
{
    return;
}

HumanA::~HumanA()
{
    return;
}

void HumanA::attack(void)
{
    std::cout << SMCYAN << _name << " attacks with their " << _weapon.getType() << RESET << std::endl;
    return;
}
