#include <string>
#include <iostream>

class Form
{
private:
    const std::string _name;
    bool _is_signed = false;
    const unsigned int gr_to_sign;
    const unsigned int gr_to_exec;

public:
    Form(const std::string name, const unsigned int gr_to_sign, const unsigned int gr_to_exec);
    Form(const Form &f);
    Form &operator=(const Form &f);
    ~Form();
    std::string get_name() const;
    bool get_is_signed() const;
    unsigned int get_gr_to_sign() const;
    unsigned int get_gr_to_exec() const;
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);