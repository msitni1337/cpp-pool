#include "replace.hpp"

char* read_file(std::ifstream& input)
{
    size_t len;
    char* content;

    try
    {
        input.seekg(0, std::ios_base::end);
        len = input.tellg();
        input.seekg(0, std::ios_base::beg);
        content = new char[len + 1];
        input.read(content, len);
        content[len] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        if (content != NULL)
            delete [] content;
        return NULL;
    }
    return content;
}


void file_replace(std::string content, std::ofstream& output, std::string& find, std::string& replace)
{
    (void) content;
    (void) output;
    (void) find;
    (void) replace;
    size_t pos = 0;
    while (pos < content.length())
    {
        size_t occ = content.find(find, pos);
        if (occ == std::string::npos)
        {
            std::string tmp = content.substr(pos);
            output << tmp;
            return;
        }
        std::string tmp = content.substr(pos, occ - pos);
        output << tmp;
        output << replace;
        pos = occ + find.length();
    }
}