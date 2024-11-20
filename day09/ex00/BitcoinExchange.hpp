#pragma once
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#define AUGUST 8
#define FEBRUARY 2
typedef struct date_s
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned long stamp;
} date_t;

class BitcoinExchange
{
private:
    std::map<unsigned long, float> _db;

public:
    BitcoinExchange(std::ifstream &db_file);
    BitcoinExchange(const BitcoinExchange &be);
    BitcoinExchange &operator=(const BitcoinExchange &be);
    ~BitcoinExchange();
    void predict(std::ifstream &input_file) const;
};