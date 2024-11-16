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
    size_t i;
    for (i = 0; i < param.length() && std::isdigit(param[i]); i++)
        ;
    if (i > 0 && i == param.length())
        return true;
    return false;
}
void RPN::solve(std::istringstream &operations)
{
    while (_op.size())
        _op.pop();
    std::stack<std::string> tmp_stack;
    while (operations.eof() == false)
    {
        std::string param;
        operations >> param;
        if (is_numeric(param) == false)
        {
            if (param == "-" || param == "+" || param == "/" || param == "*")
            {
                tmp_stack.push(param);
                continue;
            }
            std::cout << "Error\n";
            return;
        }
        tmp_stack.push(param);
    }
    while (tmp_stack.size())
    {
        _op.push(tmp_stack.top());
        tmp_stack.pop();
    }
    while (_op.size())
    {
        std::cout << _op.top() << '\n';
        _op.pop();
    }
}