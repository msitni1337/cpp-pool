#include "BitcoinExchange.hpp"

int main(int c, char **v)
{
    (void)v;
    if (c == 2)
    {
        try
        {
            std::ifstream db_file("./data.csv");
            BitcoinExchange btc(db_file);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: could not open database file.\n";
            return 1;
        }
        return 0;
    }
    std::cerr << "Error: could not open file.\n";
    return 1;
}
