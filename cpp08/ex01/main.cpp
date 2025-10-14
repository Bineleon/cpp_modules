#include "Span.hpp"
#include <iomanip>

void printHeader(const std::string& str)
{
	int size = 50;
	int totalPad = size - str.size();
	(totalPad < 0) ? totalPad = 0 : totalPad;
	int lPad = totalPad / 2;
	int rPad = totalPad - lPad;

	std::cout << std::endl << SMGREEN;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setfill(' ') << std::setw(lPad + str.size()) << str << std::setw(rPad) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << RESET << std::endl;
}

int main()
{
    {
        printHeader("Test: Basic");
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        printHeader("Test: Big range");
        Span sp = Span(20000);
        std::list<int> v;
        std::srand(time(NULL));

        try
        {
            for (int i = 0; i < 20000; ++i)
                v.push_back(std::rand() % 100000);
            sp.addRange(v.begin(), v.end());
            std::cout << "Shortest span : " << SMGREEN << sp.shortestSpan() << RESET << std::endl;
            std::cout << "Longest span : " << SMGREEN << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << SMRED << e.what() << RESET << '\n';
        }
    }
        {
        printHeader("Test: Big range with negative value");
        Span sp = Span(50000);
        std::list<int> v;
        try
        {
            for (int i = -10000; i < 20000; ++i)
                v.push_back(i);
            sp.addRange(v.begin(), v.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << SMRED << e.what() << RESET << '\n';
        }
    }
    {
        printHeader("Test: Container full");
        Span sp = Span(15000);
        std::vector<int> v;
        std::srand(time(NULL));
        try
        {
            for (int i = 0; i < 20000; ++i)
                v.push_back(std::rand() % 20000);
            sp.addRange(v.begin(), v.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << SMRED << e.what() << RESET << '\n';
        }
    }
    return 0;
}
