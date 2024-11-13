#include "BitcoinExchange.hpp"

static inline unsigned long get_date_key(std::string date)
{
    unsigned long date_key;
    char *str;

    date_key = std::strtoul(date.c_str(), &str, 10) * 100;
    date_key += std::strtoul(str + 1, &str, 10) * 10;
    date_key += std::strtoul(str + 1, &str, 10);

    return date_key;
}
BitcoinExchange::BitcoinExchange(std::ifstream &db_file)
{
    std::string line;
    getline(db_file, line);
    while (db_file.eof() == false)
    {
        getline(db_file, line);
        std::string date;
        std::string rate;
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        date = line.substr(0, comma);
        rate = line.substr(comma + 1);
        _db[get_date_key(date)] = std::strtof(rate.c_str(), NULL);
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &be) : _db(be._db)
{}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &be)
{
    if (this != &be)
        _db = be._db;
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{}