#include "easyfind.hpp"
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

int main(void)
{
	{
		printHeader("Test : list");
	
		std::cout << SMYELLOW << "Creating list with int from 1 to 5..." << RESET << std::endl;
		std::list<int> l;
	
		for (int i = 1; i < 6; ++i)
			l.push_back(i);
	
		std::cout << SMYELLOW << "Trying to find 5 (should work)..." << RESET << std::endl;
		std::list<int>::iterator it;
		try
		{
			it = easyfind(l, 5);
			std::cout << "Value found : " << SMGREEN << *it << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << SMRED << e.what() << RESET << '\n';
		}
		
		std::cout << SMYELLOW << "Trying to find 6 (should not work)..." << RESET << std::endl;
		try
		{
			it = easyfind(l, 6);
		}
		catch(const std::exception& e)
		{
			std::cerr << SMRED << e.what() << RESET << '\n';
		}
	}
	{

		printHeader("Test : vector");
	
		std::cout << SMYELLOW << "Creating vector with int from 1 to 5..." << RESET << std::endl;
		std::vector<int> v;
	
		for (int i = 1; i < 6; ++i)
			v.push_back(i);
	
		std::cout << SMYELLOW << "Trying to find 5 (should work)..." << RESET << std::endl;
		std::vector<int>::iterator it;
		try
		{
			it = easyfind(v, 5);
			std::cout << "Value found : " << SMGREEN << *it << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << SMRED << e.what() << RESET << '\n';
		}
		
		std::cout << SMYELLOW << "Trying to find 6 (should not work)..." << RESET << std::endl;
		try
		{
			it = easyfind(v, 6);
		}
		catch(const std::exception& e)
		{
			std::cerr << SMRED << e.what() << RESET << '\n';
		}
	}

	return 0;
}
