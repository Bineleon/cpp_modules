#include "Harl.hpp"

Harl::Harl()
{
    return;
}

Harl::~Harl()
{
    return;
}

int levelToInt(const std::string& level)
{
	if (level == "DEBUG")
        return 0;
	if (level == "INFO")
        return 1;
	if (level == "WARNING")
        return 2;
	if (level == "ERROR")
        return 3;
	return -1;
}

void Harl::complain( std::string level )
{
    int lev = levelToInt(level);

    switch (lev)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default:
            std::cout << SMYELLOW << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
    }
    return;
}

void Harl::debug(void)
{
    std::cout << SMCYAN << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
    std::cout << "I really do!" << RESET << std::endl;
    std::cout << std::endl;
    return;
}

void Harl::info(void)
{
    std::cout << SMBLUE << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
    std::cout << std::endl;
    return;
}

void Harl::warning(void)
{
    std::cout << SMYELLOW << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years, whereas you started working here just last month." << RESET << std::endl;
    std::cout << std::endl;
    return;
}

void Harl::error(void)
{
    std::cout << SMRED << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
    std::cout << std::endl;
    return;
}
