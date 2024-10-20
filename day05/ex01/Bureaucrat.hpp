#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Form;

class Bureaucrat
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
    unsigned int _grade;

public:
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat &b);
    Bureaucrat &operator=(const Bureaucrat &b);
    ~Bureaucrat();
    std::string get_name() const;
    unsigned int get_grade() const;
    void increment_grade();
    void decrement_grade();
    void signForm(Form& f);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);