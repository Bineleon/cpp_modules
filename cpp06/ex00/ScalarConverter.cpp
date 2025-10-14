#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor not allowed for non instantiable class" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	std::cout << "ScalarConverter copy constructor not allowed for non instantiable class" << std::endl;
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	std::cout << "ScalarConverter copy assignment operator not allowed for non instantiable class" << std::endl;
	(void) rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

// find literal types

bool isChar(const std::string& literal)
{
    std::string str;

	if (literal.length() == 1 && !isdigit(literal[0]))
        return true;
    if (literal.length() == 3 && literal[0] == '\'' && literal[literal.length() - 1] == '\'')
        return true;
    return false;
}

char extractChar(const std::string& literal)
{
    char charLiteral;

	if (literal.length() == 1 && !isdigit(literal[0]))
        charLiteral = literal[0];
    if (literal.length() == 3 && literal[0] == '\'' && literal[literal.length() - 1] == '\'')
        charLiteral = literal[1];
    return charLiteral;
}

bool isSign(char c)
{
	if (c == '+' || c == '-')
		return true;
	return false;
}

bool isInt(const std::string& literal)
{
	size_t start = 0;
	long l;

	if (isSign(literal[0]))
		start++;
	if (start == literal.length())
		return false;
	for (size_t i = start; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	l = std::strtol(literal.c_str(), NULL, 10);
	if (l > INT_MAX || l < INT_MIN)
		return false;
	return true;
}

bool checkLiteralBody(size_t start, const std::string& literal, size_t len, bool *pointFound)
{
	for (size_t i = start; i < len; i++)
	{
		if (literal[i] == '.')
		{
			if(!*pointFound)
				*pointFound = true;
			else
				return false;
		}
		if (!isdigit(literal[i]) && (literal[i] != '.'))
			return false;
	}
	return true;
}

bool isFloat(const std::string& literal)
{
	bool pointFound = false;
	size_t start = 0;

	if (literal[literal.length() - 1] != 'f')
		return false;
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	if (!isdigit(literal[0]) && literal[0] != '.' && !isSign(literal[0]))
		return false;
	if (isSign(literal[0]))
		start++;
	if (start == literal.length())
		return false;
	if (!checkLiteralBody(start, literal, literal.length() - 1, &pointFound))
		return false;
	return pointFound;
}

bool isDouble(const std::string& literal)
{
	bool pointFound = false;
	size_t start = 0;

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	if (!isdigit(literal[0]) && literal[0] != '.' && !isSign(literal[0]))
		return false;
	if (isSign(literal[0]))
		start++;
	if (start == literal.length())
		return false;
	if (!checkLiteralBody(start, literal, literal.length(), &pointFound))
		return false;
	return pointFound;
}

bool isPseudoFLiteral(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	return false;
}

bool isPseudoDLiteral(const std::string& literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	return false;
}

// convert literal types

std::string intToChar(int i)
{
    char c;
    std::string str;

    if (i >= 0 && i <= 255)
	{
		c = i;
		if (isprint(c))
            str = c;
		else
            str = "Non displayable";
        return str;
	}
    return "Impossible";
}

void displayConv(char c, int i, float f, double d, bool of)
{
    std::cout << "char: ";
    if (isprint(c))
        std::cout << c << std::endl;
    else if (!of)
        std::cout << intToChar(i) << std::endl;
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "int: ";
    if (!of)
        std::cout << i << std::endl;
    else
        std::cout << "Impossible" << std::endl;
    std::cout  << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void displayPseudoL(const std::string& literal)
{
    std::string c;
    std::string i;
    std::string f = literal;
    std::string d = literal;

    if (isPseudoFLiteral(literal))
	d.erase (d.size()-1);
    else
       f.push_back('f');
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}

void convertChar(const std::string& literal)
{
    char c = extractChar(literal);
    int i = static_cast<int>(c);
    float f = static_cast<float>(i);
	double d = static_cast<double>(i);

    displayConv(c, i, f, d, false);
}

void convertInt(const std::string& literal)
{
	int i = atoi(literal.c_str());
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	displayConv(0, i, f ,d, false);
}

void convertFloat(const std::string& literal)
{
    int i;
	float f;
    double d;
    bool oflow;

    f = static_cast<double>(std::strtod(literal.c_str(), NULL));
    d = static_cast<double>(f);
    oflow = false;

    if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
        oflow = true;
    i = f;
	displayConv(0, i, f ,d, oflow);
}

void convertDouble(const std::string& literal)
{
	int i;
	double d;
	float f;
    bool oflow;

    d = std::strtod(literal.c_str(), NULL);
	f = static_cast<float>(d);
    oflow = false;

    if (d > static_cast<float>(INT_MAX) || d < static_cast<float>(INT_MIN))
    oflow = true;
    i = d;
	displayConv(0, i, f ,d, oflow);
}

functPtr getConvertor(const std::string &literal)
{
    const t_literal literals[] =
    {
		{isChar, convertChar},
		{isInt, convertInt},
		{isFloat, convertFloat},
		{isDouble, convertDouble}
	};

    for (int i = 0; i < 4; i++)
    {
        if (literals[i].detectType(literal))
            return literals[i].convert;
    }

    throw InvalidLiteralException();
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudoDLiteral(literal) || isPseudoFLiteral(literal))
    {
        displayPseudoL(literal);
        return;
    }
    try
    {
        functPtr func = getConvertor(literal);
        func(literal);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}
