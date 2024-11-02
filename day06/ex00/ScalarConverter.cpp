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
// static bool isNumeric(std::string s)
// {
// 	size_t i = 0;
// 	for (; i < s.length() && s[i] >= '0' && s[i] <= '9'; i++)
// 	{
// 	}
// 	if (i && i == s.length())
// 		return true;
// 	return false;
// }
static void ConvertChar(std::string s)
{
	std::cout << "ConvertChar\n";
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
	std::cout << "ConvertInt\n";
	double value = strtod(s.c_str(), NULL);
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
		if (value == NAN || value == INFINITY || value == -INFINITY)
			std::cout << "int: " << "impossible\n";
		else
			std::cout << "int: " << "Overflow\n";
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << '\n';
}
static void ConvertDouble(std::string s)
{
	std::cout << "ConvertDouble\n";
	double value = strtod(s.c_str(), NULL);
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
		if (s == "nan" || value == INFINITY || value == -INFINITY)
			std::cout << "int: " << "impossible\n";
		else
			std::cout << "int: " << "Overflow\n";
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << '\n';
}
static void ConvertFloat(std::string s)
{
	std::cout << "ConvertFloat\n";
	double value = strtod(s.c_str(), NULL);
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
		if (s == "nanf" || value == INFINITY || value == -INFINITY)
			std::cout << "int: " << "impossible\n";
		else
			std::cout << "int: " << "Overflow\n";
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << '\n';
}
static void parse_string(std::string s)
{
	size_t i = 0;
	bool has_dot = false;
	for (; i < s.length(); i++)
	{
		if ((s[i] == '-' || s[i] == '+'))
		{
			if (i != 0)
			{
				std::cout << "Bad String Provided.\n";
				return;
			}
		}
		else if (s[i] == '.' && i > 0 && std::isdigit(s[i - 1]))
		{
			if (has_dot)
			{
				std::cout << "Bad String Provided.\n";
				return;
			}
			has_dot = true;
		}
		else if (std::isdigit(s[i]) == 0)
			break;
	}
	if (i != s.length())
	{
		if (s == "inf" || s == "+inf" || s == "-inf" || s == "nan")
			ConvertDouble(s);
		else if (s == "inff" || s == "+inff" || s == "-inff" || s == "nanf")
			ConvertFloat(s);
		else if (s[i] == 'f' && i == s.length() - 1 && i > 0 && std::isdigit(s[i - 1]))
			ConvertFloat(s);
		else
			std::cout << "Bad String Provided.\n";
	}
	else
	{
		if (i == 0 || std::isdigit(s[i - 1]) == 0)
			std::cout << "Bad String Provided.\n";
		else if (has_dot)
			ConvertDouble(s);
		else
			ConvertInt(s);
	}
}
void ScalarConverter::convert(std::string s)
{
	if (s.empty())
		std::cout << "Empty String Provided.\n";
	else if (s.length() == 1)
		ConvertChar(s);
	else
		parse_string(s);
}
