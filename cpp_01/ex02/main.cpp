#include <iostream>

int main (void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string* strPTR = &string;
	std::string& strREF = string;

	std::cout << "String memory address : " << &string << std::endl;
	std::cout << "StrPTR memory address : " << strPTR << std::endl;
	std::cout << "StrREF memory address : " << &strREF << std::endl;

	std::cout << "String value : " << string << std::endl;
	std::cout << "StrPTR value : " << *strPTR << std::endl;
	std::cout << "StrREF value : " << strREF << std::endl;
}
