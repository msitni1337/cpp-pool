#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& sc);
    ScalarConverter& operator=(const ScalarConverter& sc);
    ~ScalarConverter();
public:
    static void convert(std::string s);
};