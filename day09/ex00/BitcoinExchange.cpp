#include "BitcoinExchange.hpp"

static inline bool is_decimal(std::string &param)
{
    size_t i = 0;

    while (std::isspace(param[i]))
        i++;
    if(param[i] =='-' || param[i] == '+')
        i++;
    for (; i < param.length() && std::isdigit(param[i]); i++)
        ;
    if(param[i] == '.')
        i++;
    for (; i < param.length() && std::isdigit(param[i]); i++)
        ;
    if (i && std::isdigit(param[i - 1]))
        return true;
    return false;
}
static date_t parse_date(std::string date)
{
    date_t date_key;
    char *str;

    date_key.year = std::strtoul(date.c_str(), &str, 10);
    date_key.month = std::strtoul(str + 1, &str, 10);
    date_key.day = std::strtoul(str + 1, &str, 10);
    date_key.stamp = date_key.year * 10000 + date_key.month * 100 + date_key.day;
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
        _db[parse_date(date).stamp] = std::strtof(rate.c_str(), NULL);
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &be) : _db(be._db)
{
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &be)
{
    if (this != &be)
        _db = be._db;
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{
}
static inline bool validate_date(date_t date)
{
    if (date.year < 2009 || date.year > 2024)
        return false;
    if (date.month < 1 || date.month > 12)
        return false;
    /* days */
    if (date.day < 1)
        return false;
    if (date.month % 2 == 1 && date.day > 31)
        return false;
    if (date.month % 2 == 0)
    {
        if (date.month == FEBRUARY)
        {
            if (date.year % 4 == 0 && date.day > 29)
                return false;
            if (date.year % 4 != 0 && date.day > 28)
                return false;
            return true;
        }
        if (date.month == AUGUST && date.day <= 31)
            return true;
        if (date.day > 30)
            return false;
    }
    return true;
}
void BitcoinExchange::predict(std::ifstream &input_file) const
{
    std::string line;
    
    while (input_file.eof() == false)
    {
        getline(input_file, line);
        if (line == "date | value")
            continue;
        size_t pipe = line.find('|');
        std::string raw_date;
        if (pipe == std::string::npos)
            raw_date = line;
        else
            raw_date = line.substr(0, pipe);
        date_t date = parse_date(raw_date);
        if (validate_date(date) == false)
        {
            std::cout << "Error: bad input => " << raw_date << '\n';
            continue;
        }
        if (pipe == std::string::npos)
        {
            std::cout << "Error: bad input line => " << line << '\n';
            continue;
        }
        std::string raw_rate = line.substr(pipe + 1);
        if (is_decimal(raw_rate) == false)
        {
            std::cout << "Error: bad number => [" << raw_rate << "]\n";
            continue;
        }
        float value = std::strtof(raw_rate.c_str(), NULL);
        if (value < 0.0f)
        {
            std::cout << "Error: not a positive number." << '\n';
            continue;
        }
        if (value > 1000.0f)
        {
            std::cout << "Error: too large a number." << '\n';
            continue;
        }
        std::map<unsigned long, float>::const_iterator it = _db.lower_bound(date.stamp);
        while (it->first > date.stamp)
            it--;
        std::cout << std::setfill('0') << date.year << '-' << std::setw(2) << date.month << '-' << std::setw(2) << date.day << " => " << value << " = " << it->second * value << '\n';
    }
}
