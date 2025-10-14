#include "Harl.hpp"

Harl::Harl()
{
    return;
}

Harl::~Harl()
{
    return;
}

void Harl::complain( std::string level )
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    functPtr functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << RED << "Error: level \"" << level << "\" is unknown. Try with: \"DEBUG\",  \"INFO\",  \"WARNING\" or  \"ERROR\"" << RESET << std::endl;
    return;
}

void Harl::debug(void)
{
    std::cout << SMCYAN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
    return;
}

void Harl::info(void)
{
    std::cout << SMBLUE << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
    return;
}

void Harl::warning(void)
{
    std::cout << SMYELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << RESET << std::endl;
    return;
}

void Harl::error(void)
{
    std::cout << SMRED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
    return;
}
