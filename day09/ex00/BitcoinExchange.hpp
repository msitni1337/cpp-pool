#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>

class BitcoinExchange
{
private:
    std::map<unsigned long, unsigned int> db;
public:
    BitcoinExchange(std::ifstream& db_file);
    BitcoinExchange(const BitcoinExchange& be);
    BitcoinExchange& operator=(const BitcoinExchange& be);
    ~BitcoinExchange();
};