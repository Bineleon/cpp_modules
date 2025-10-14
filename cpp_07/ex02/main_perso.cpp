#include "Array.hpp"
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
	printHeader("Test : Out of bond");
	try
	{
		std::cout << SMYELLOW << "Creating Array a1 of 10 int..." << RESET << std::endl;
		Array<int> a1(10);
		for (unsigned int i = 0; i < a1.size(); i++)
			a1[i] = i;
		std::cout << SMYELLOW << "Accessing array size..." << RESET << std::endl;
		std::cout << "Array a1 has " << SMGREEN << a1.size() << RESET << " elements" << std::endl;
		std::cout << SMYELLOW << "Accessing out of bond index..." << RESET << std::endl;
			std::cout << "a1[20] = " << SMGREEN << a1[20] << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << SMRED << "Exception: " << e.what() << RESET << std::endl;
	}

	printHeader("Test : empty array");
	try
	{
		std::cout << SMYELLOW << "Creating empty array..." << RESET << std::endl;
		Array<int> a1;
		std::cout << SMYELLOW << "Accessing array size..." << RESET << std::endl;
		std::cout << "Array a1 has " << SMGREEN << a1.size() << RESET << " elements" << std::endl;
		std::cout << SMYELLOW << "Accessing out of bond index..." << RESET << std::endl;
		std::cout << "a1[0] = " << SMGREEN << a1[0] << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << SMRED << "Exception: " << e.what() << RESET << std::endl;
	}

	printHeader("Test : string array");
	try
	{
		std::cout << SMYELLOW << "Creating Array a1 of 5 std::string..." << RESET << std::endl;
		Array<std::string> a1(4);
		std::cout << SMYELLOW << "Assigning array elements..." << RESET << std::endl;
		a1[0] = "a";
		a1[1] = "b";
		a1[2] = "c";
		a1[3] = "d";
		std::cout << SMYELLOW << "Accessing array size..." << RESET << std::endl;
		std::cout << "Array a1 has " << SMGREEN << a1.size() << RESET << " elements" << std::endl;
		std::cout << SMYELLOW << "Accessing each element..." << RESET << std::endl;
		for (unsigned int i = 0; i < a1.size(); i++)
			std::cout << "a1[" << i << "] = " << SMGREEN << a1[i] << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << SMRED << "Exception: " << e.what() << RESET << std::endl;
	}

	printHeader("Test : Assignment constructor");
	try
	{
		std::cout << SMYELLOW << "Creating Array a1 of 5 std::string..." << RESET << std::endl;
		Array<std::string> a1(4);
		a1[0] = "a";
		a1[1] = "b";
		a1[2] = "c";
		a1[3] = "d";
		std::cout << SMYELLOW << "Accessing each element of a1..." << RESET << std::endl;
		for (unsigned int i = 0; i < a1.size(); i++)
			std::cout << "a1[" << i << "] = " << SMGREEN << a1[i] << RESET << std::endl;
		std::cout << SMYELLOW << "Creating Array a2 from a1..." << RESET << std::endl;
		Array<std::string> a2(a1);
		std::cout << SMYELLOW << "Accessing array size..." << RESET << std::endl;
		std::cout << "Array a1 has " << SMGREEN << a1.size() << RESET << " elements" << std::endl;
		std::cout << SMYELLOW << "Accessing each element of a2..." << RESET << std::endl;
		for (unsigned int i = 0; i < a2.size(); i++)
			std::cout << "a2[" << i << "] = " << SMGREEN << a2[i] << RESET << std::endl;
		std::cout << SMYELLOW << "Modifying elements of a2..." << RESET << std::endl;
		for (unsigned int i = 0; i < a2.size(); i++)
			a2[i] = "bla";
		std::cout << SMYELLOW << "Accessing each element of a2 (post modification)..." << RESET << std::endl;
		for (unsigned int i = 0; i < a2.size(); i++)
			std::cout << "a2[" << i << "] = " << SMGREEN << a2[i] << RESET << std::endl;
		std::cout << SMYELLOW << "Accessing each element of a1 (should not have change)..." << RESET << std::endl;
		for (unsigned int i = 0; i < a1.size(); i++)
			std::cout << "a1[" << i << "] = " << SMGREEN << a1[i] << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << SMRED << "Exception: " << e.what() << RESET << std::endl;
	}

	printHeader("Test : Copy constructor");
	try
	{
		std::cout << SMYELLOW << "Creating Array a1 of 5 std::string..." << RESET << std::endl;
		Array<char> a1(4);
		a1[0] = 'a';
		a1[1] = 'b';
		a1[2] = 'c';
		a1[3] = 'd';
		std::cout << SMYELLOW << "Accessing each element of a1..." << RESET << std::endl;
		for (unsigned int i = 0; i < a1.size(); i++)
			std::cout << "a1[" << i << "] = " << SMGREEN << a1[i] << RESET << std::endl;
		std::cout << SMYELLOW << "Creating Array a2 with a1..." << RESET << std::endl;
		Array<char> a2 = a1;
		std::cout << SMYELLOW << "Accessing array size..." << RESET << std::endl;
		std::cout << "Array a1 has " << SMGREEN << a1.size() << RESET << " elements" << std::endl;
		std::cout << SMYELLOW << "Accessing each element of a2..." << RESET << std::endl;
		for (unsigned int i = 0; i < a2.size(); i++)
			std::cout << "a2[" << i << "] = " << SMGREEN << a2[i] << RESET << std::endl;
		std::cout << SMYELLOW << "Modifying elements of a2..." << RESET << std::endl;
		for (unsigned int i = 0; i < a2.size(); i++)
			a2[i] = 'f';
		std::cout << SMYELLOW << "Accessing each element of a2 (post modification)..." << RESET << std::endl;
		for (unsigned int i = 0; i < a2.size(); i++)
			std::cout << "a2[" << i << "] = " << SMGREEN << a2[i] << RESET << std::endl;
		std::cout << SMYELLOW << "Accessing each element of a1 (should not have change)..." << RESET << std::endl;
		for (unsigned int i = 0; i < a1.size(); i++)
			std::cout << "a1[" << i << "] = " << SMGREEN << a1[i] << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << SMRED << "Exception: " << e.what() << RESET << std::endl;
	}
	
	return 0;
}
