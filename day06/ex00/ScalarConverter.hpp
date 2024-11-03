#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <cstdlib>
#include <cfloat>
#include <cmath>

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