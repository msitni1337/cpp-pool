#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class AForm
{
public:
    class GradeTooHighException : public std::exception
    {
    private:
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    private:
    public:
        const char* what() const throw();
    };
    
    class EmptyNameException : public std::exception
    {
    private:
    public:
        const char* what() const throw();
    };

    class EmptyTargetException : public std::exception
    {
    private:
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    private:
    public:
        const char* what() const throw();
    };
private:
    const std::string _name;
    bool _is_signed;
    const unsigned int gr_to_sign;
    const unsigned int gr_to_exec;

public:
    AForm(const std::string name, const unsigned int gr_to_sign, const unsigned int gr_to_exec);
    AForm(const AForm &f);
    AForm &operator=(const AForm &f);
    virtual ~AForm();
    std::string get_name() const;
    bool get_is_signed() const;
    unsigned int get_gr_to_sign() const;
    unsigned int get_gr_to_exec() const;
    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const;
    virtual void setTarget(std::string newTarget) = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &rhs);