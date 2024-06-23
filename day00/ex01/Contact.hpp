#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>

class Contact
{
public:
    Contact();
    Contact(const Contact &c);
    Contact &operator=(const Contact &c);
    ~Contact();
    std::string get_f_name() const;
    void set_f_name(std::string s);
    std::string get_l_name() const;
    void set_l_name(std::string s);
    std::string get_n_name() const;
    void set_n_name(std::string s);
    std::string get_phone() const;
    void set_phone(std::string s);
    std::string get_secret() const;
    void set_secret(std::string s);

private:
    std::string f_name;
    std::string l_name;
    std::string n_name;
    std::string phone;
    std::string secret;
};