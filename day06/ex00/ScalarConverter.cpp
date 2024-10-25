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
void ScalarConverter::convert(std::string s)
{
	if (s.empty())
	{
		std::cout << "Empty String Provided.\n";
		return;
	}
	if (s.length() == 1)
	{
		return ConvertChar(s);
	}
}
