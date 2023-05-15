#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = 0;
	this->_amount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created";
	std::cout << std::endl;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	return;
}

Account::~Account()
{
	return;
}

Account::Account( void )
{
	return ;
}

//public static
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << &Account::getNbAccounts << ";";
	std::cout << "total:" << &Account::getTotalAmount << ";";
	std::cout << "deposits:" << &Account::getNbDeposits << ";";
	std::cout << "withdrawals:" << &Account::getNbWithdrawals;
	std::cout << std::endl;
	return ;
}




//public non static
void	Account::makeDeposit( int deposit )
{
	(void)deposit;
	return ;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	(void)withdrawal;
	return (true);
}
int		Account::checkAmount( void ) const
{
	_displayTimestamp();
	return (0);
}
void	Account::displayStatus( void ) const
{
	return ;
}

//private
void Account::_displayTimestamp( void )
{
	std::time_t now;

	now = std::time(nullptr);
	std::tm *time;

	time  = localtime(&now);
	std::cout << "[" << time->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_mday << "_";
	std::cout << std::setw(2) << std::setfill('0') << time->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_sec << "] ";
	return ;
}