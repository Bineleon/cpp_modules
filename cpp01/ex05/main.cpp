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

int main()
{
    Harl harl;

    printHeader("DEBUG", SMGREEN);
    harl.complain("DEBUG");

    printHeader("INFO", SMGREEN);
    harl.complain("INFO");

    printHeader("WARNING", SMGREEN);
    harl.complain("WARNING");

    printHeader("ERROR", SMGREEN);
    harl.complain("ERROR");

    printHeader("INVALID LEVEL", RED);
    harl.complain("BLABLA");

    return 0;
}

// int main (void)
// {
//     {
//         Harl harl;

//         std::cout << std::endl;
//         std::cout << SMGREEN;
//         std::cout << "                  ╔═══════════════════════════════════════════╗" << std::endl;
// 	    std::cout << "                  ║                   DEBUG                   ║" << std::endl;
//         std::cout << "                  ╚═══════════════════════════════════════════╝" << std::endl;
//         std::cout << RESET;
//         std::cout << std::endl;

//         harl.complain("DEBUG");
//     }
//     {
//         Harl harl;

//         std::cout << std::endl;
//         std::cout << SMGREEN;
//         std::cout << "                  ╔═══════════════════════════════════════════╗" << std::endl;
// 	    std::cout << "                  ║                    INFO                   ║" << std::endl;
//         std::cout << "                  ╚═══════════════════════════════════════════╝" << std::endl;
//         std::cout << RESET;
//         std::cout << std::endl;

//         harl.complain("INFO");
//     }
//     {
//         Harl harl;

//         std::cout << std::endl;
//         std::cout << SMGREEN;
//         std::cout << "                  ╔═══════════════════════════════════════════╗" << std::endl;
// 	    std::cout << "                  ║                  WARNING                  ║" << std::endl;
//         std::cout << "                  ╚═══════════════════════════════════════════╝" << std::endl;
//         std::cout << RESET;
//         std::cout << std::endl;

//         harl.complain("WARNING");
//     }
//     {
//         Harl harl;

//         std::cout << std::endl;
//         std::cout << SMGREEN;
//         std::cout << "                  ╔═══════════════════════════════════════════╗" << std::endl;
// 	    std::cout << "                  ║                   ERROR                   ║" << std::endl;
//         std::cout << "                  ╚═══════════════════════════════════════════╝" << std::endl;
//         std::cout << RESET;
//         std::cout << std::endl;

//         harl.complain("ERROR");
//     }
//     {
//         Harl harl;

//         std::cout << std::endl;
//         std::cout << SMGREEN;
//         std::cout << "                  ╔═══════════════════════════════════════════╗" << std::endl;
// 	    std::cout << "                  ║                UNVALID LEVEL              ║" << std::endl;
//         std::cout << "                  ╚═══════════════════════════════════════════╝" << std::endl;
//         std::cout << RESET;
//         std::cout << std::endl;

//         harl.complain("BLABLA");
//     }
// return (0);
// }
