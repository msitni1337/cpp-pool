#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Bureaucrat
{
public:
    class GradeTooHighException : public std::exception
    {
    private:
    public:
        GradeTooHighException() _NOEXCEPT;
        ~GradeTooHighException() _NOEXCEPT;
        const char* what() const _NOEXCEPT;
    };

    class GradeTooLowException : public std::exception
    {
    private:
    public:
        GradeTooLowException() _NOEXCEPT;
        ~GradeTooLowException() _NOEXCEPT;
        const char* what() const _NOEXCEPT;
    };
    class EmptyNameException : public std::exception
    {
    private:
    public:
        EmptyNameException() _NOEXCEPT;
        ~EmptyNameException() _NOEXCEPT;
        const char* what() const _NOEXCEPT;
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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);