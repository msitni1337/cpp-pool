#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    //  [19920104_091532] index:0;amount:42;created
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}
Account::~Account(void)
{
    _nbAccounts--;
    //  [19920104_091532] index:0;amount:47;closed
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}
int Account::getTotalAmount(void)
{
    return _totalAmount;
}
int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}
void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(0);
    std::tm *now_s = std::localtime(&now);
    std::cout << '[' << now_s->tm_year + 1900
              << std::setw(2) << std::setfill('0') << now_s->tm_mon
              << std::setw(2) << std::setfill('0') << now_s->tm_mday << '_'
              << std::setw(2) << std::setfill('0') << now_s->tm_hour
              << std::setw(2) << std::setfill('0') << now_s->tm_min
              << std::setw(2) << std::setfill('0') << now_s->tm_sec << ']';
}
void Account::displayAccountsInfos(void)
{
    // [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << " accounts:"
              << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
              << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << '\n';
}
void Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    // [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:"
              << deposit << ";amount:" << _amount << ";nb_deposits:"
              << _nbDeposits << '\n';
}
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if (withdrawal > _amount)
    {
        // [19920104_091532] index:0;p_amount:47;withdrawal:refused
        std::cout << "refused\n";
        return false;
    }
    else
    {
        // [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << '\n';
        return true;
    }
}
int Account::checkAmount(void) const
{
    return _amount;
}
void Account::displayStatus(void) const
{
    // [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
              << _nbDeposits << ";withdrawals:" << _nbWithdrawals << '\n';
}