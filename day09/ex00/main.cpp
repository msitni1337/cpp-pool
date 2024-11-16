#include "BitcoinExchange.hpp"

int main(int c, char **v)
{
    (void)v;
    if (c == 2)
    {
        std::ifstream db_file;
        try
        {
            db_file.open("./data.csv");
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: could not open database file './data.csv' .\n";
            return 1;
        }
        BitcoinExchange btc(db_file);
        db_file.close();
        std::ifstream input_file;
        try
        {
            input_file.open(v[1]);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: could not open file :" << v[1] << '\n';
            return 1;
        }
        btc.predict(input_file);
        input_file.close();
        return 0;
    }
    std::cerr << "Error: could not open file.\n";
    return 1;
}
