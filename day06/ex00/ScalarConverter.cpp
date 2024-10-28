#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &sc)
{
	(void)sc;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc)
{
	(void)sc;
	return *this;
}
ScalarConverter::~ScalarConverter()
{
}
/*
static bool isNumeric(std::string s)
{
	size_t i = 0;
	for (; i < s.length() && s[i] >= '0' && s[i] <= '9'; i++)
	{}
	if (i && i == s.length())
		return true;
	return false;
}
*/
static void ConvertChar(std::string s)
{
	if (std::isprint(s[0]) && std::isdigit(s[0]) == 0)
	{
		std::cout << "char: " << s[0] << '\n';
		std::cout << "int: " << static_cast<int>(s[0]) << '\n';
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(s[0]) << "f\n";
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(s[0]) << '\n';
	}
	else
	{
		std::cout << "char: Non displayable\n";
		std::cout << "int: " << atoi(s.c_str()) << '\n';
		std::cout << "float: " << std::fixed << std::setprecision(1) << atof(s.c_str()) << "f\n";
		std::cout << "double: " << std::fixed << std::setprecision(1) << atof(s.c_str()) << '\n';
	}
}
static void ConvertInt(std::string s)
{
	long long value = atol(s.c_str());
	std::cout << value << '\n';
	if (value <= INT_MAX && value >= INT_MIN)
	{
		if (value >= ' ' && value <= '~')
			std::cout << "char: " << static_cast<char>(value) << '\n';
		else if (value <= 127)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: impossible\n";
		std::cout << "int: " << static_cast<int>(value) << '\n';
	}
	else
	{
		std::cout << "char: impossible\n";
		std::cout << "int: " << "Overflow" << '\n';
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << '\n';
}
void ScalarConverter::convert(std::string s)
{
	if (s.empty())
	{
		std::cout << "Empty String Provided.\n";
	}
	else if (s.length() == 1)
	{
		ConvertChar(s);
	}
	else //if (isNumeric(s))
	else
	{
		ConvertInt(s);
	}
}
