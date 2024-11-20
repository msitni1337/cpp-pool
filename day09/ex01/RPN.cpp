#include "RPN.hpp"

RPN::RPN()
{
}
RPN::RPN(const RPN &rpn) : _op(rpn._op)
{
}
RPN &RPN::operator=(const RPN &rpn)
{
    if (this != &rpn)
        _op = rpn._op;
    return *this;
}
RPN::~RPN()
{
}
static inline bool is_numeric(std::string &param)
{
    size_t i = 0;

    for (; i < param.length() && std::isdigit(param[i]); i++)
        ;
    if (i > 0 && i == param.length())
        return true;
    return false;
}
static bool do_op(std::stack<long> &stck, std::string op)
{
    long num1 = stck.top();
    stck.pop();
    long num2 = stck.top();
    stck.pop();
    if (op == "+")
        stck.push(num2 + num1);
    else if (op == "-")
        stck.push(num2 - num1);
    else if (op == "*")
        stck.push(num2 * num1);
    else if (op == "/")
    {
        if (num1 == 0)
        {
            std::cout << "Dividing by zero.\n";
            return false;
        }
        stck.push(num2 / num1);
    }
    return true;
}
void RPN::solve(std::istringstream &operations)
{
    while (_op.size())
        _op.pop();
    while (operations.eof() == false)
    {
        std::string str;
        operations >> str;
        if (str.length() == 0)
            break;
        if (is_numeric(str))
            _op.push(std::strtol(str.c_str(), NULL, 10));
        else if (_op.size() > 1 && (str == "+" || str == "-" || str == "*" || str == "/") && do_op(_op, str))
            ;
        else
        {
            std::cout << "Error\n";
            return;
        }
    }
    if (_op.size() == 1)
        std::cout << _op.top() << '\n';
    else
        std::cout << "Error\n";
}