#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream& db_file)
{
    std::string line;
    while (db_file.eof() == false)
    {
        getline(db_file, line);
        std::cout << line << '\n';
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &be)
{
    (void) be;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &be)
{
    (void) be;
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{
}