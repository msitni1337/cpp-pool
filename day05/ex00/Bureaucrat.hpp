#pragma once
#include <string>

class Bureaucrat
{
private:
    const std::string   _name;
    unsigned int        _grade;
public:
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat& b);
    Bureaucrat& operator=(const Bureaucrat& b);
    ~Bureaucrat();
    std::string get_name();
    unsigned int get_grade();
    void increment_grade();
    void decrement_grade();
};