#include "Harl.hpp"
#include <iomanip>

void printHeader(std::string level, std::string color)
{
	std::string icon;

	if (level == "DEBUG")
		icon = "🐛";
	else if (level == "INFO")
		icon = "ℹ️ ";
	else if (level == "WARNING")
		icon = "⚠️ ";
	else if (level == "ERROR")
		icon = "❌";
	else
		icon = "❓";

	std::string line = icon + " TEST: " + level + " " + icon + " ";
	int size = 50;
	int padding = ((size - line.size() + (icon.length() * 2)) / 2 ) - 1;

	std::cout << std::endl << color;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setfill(' ') << std::setw(padding + line.size()) << line << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << RESET << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << RED << "Error: please follow this format : ./harlFilter <level>" << RESET << std::endl;
        return 1;
    }
    Harl harl;

    printHeader(av[1], SMGREEN);
    harl.complain(av[1]);

    return 0;
}
