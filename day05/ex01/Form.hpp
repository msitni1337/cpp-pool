#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Form
{
public:
    class GradeTooHighException : public std::exception
    {
    private:
    public:
        GradeTooHighException();
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    private:
    public:
        GradeTooLowException();
        const char* what() const throw();
    };
    
    class EmptyNameException : public std::exception
    {
    private:
    public:
        EmptyNameException();
        const char* what() const throw();
    };
private:
    const std::string _name;
    bool _is_signed;
    const unsigned int gr_to_sign;
    const unsigned int gr_to_exec;

public:
    Form(const std::string name, const unsigned int gr_to_sign, const unsigned int gr_to_exec);
    Form(const Form &f);
    Form &operator=(const Form &f);
    std::string get_name() const;
    bool get_is_signed() const;
    unsigned int get_gr_to_sign() const;
    unsigned int get_gr_to_exec() const;
    void beSigned(const Bureaucrat& b);
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);