#include "replace.hpp"

int main(int c, const char **v)
{
    if (c != 4)
    {
        std::cerr << "Bad arguments\n";
        std::cerr << v[0] << " [file_path] [to_find_str] [replace_str]\n";
        return 1;
    }

    std::string fname = v[1];
    char *content;
    {
        std::ifstream input(fname.c_str());
        if (input.is_open() == false)
        {
            std::cerr << "Can't open file: " << fname << '\n';
            return 1;
        }
        content = read_file(input);
        if (content == NULL)
            return 1;
    }
    {
        fname += ".replace";
        std::ofstream output(fname.c_str());
        if (output.is_open() == false)
        {
            std::cerr << "Can't open file: " << fname << '\n';
            delete [] content;
            return 1;
        }
        std::string find = v[2];
        std::string replace = v[3];
        file_replace(content, output, find, replace);
    }
    return 0;
}