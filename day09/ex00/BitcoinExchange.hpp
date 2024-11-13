#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<unsigned long, float> _db;

public:
    BitcoinExchange(std::ifstream &db_file);
    BitcoinExchange(const BitcoinExchange &be);
    BitcoinExchange &operator=(const BitcoinExchange &be);
    ~BitcoinExchange();
};