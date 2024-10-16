#pragma once
#include <string>

class Bureaucrat
{
public:
    class GradeTooHighException : std::exception
    {
    private:
    public:
        GradeTooHighException();
        virtual ~GradeTooHighException() _NOEXCEPT;
    };

    class GradeTooLowException : std::exception
    {
    private:
    public:
        GradeTooLowException();
        virtual ~GradeTooLowException() _NOEXCEPT;
    };
    class EmptyNameException : std::exception
    {
    private:
    public:
        EmptyNameException();
        virtual ~EmptyNameException() _NOEXCEPT;
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