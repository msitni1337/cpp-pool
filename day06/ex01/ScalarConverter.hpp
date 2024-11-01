#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <cstdlib>
#include <cfloat>
#include <cmath>

#define FLOAT_MAX   1E31
#define FLOAT_MIN  -1E31
#define DOUBLE_MAX  1E31
#define DOUBLE_MIN -1E31
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