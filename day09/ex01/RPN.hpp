#pragma once
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

class RPN
{
private:
    std::stack<long> _op;
public:
    RPN();
    RPN(const RPN& rpn);
    RPN& operator=(const RPN& rpn);
    ~RPN();
    void solve(std::istringstream& operations);
};