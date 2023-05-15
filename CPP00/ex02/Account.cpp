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
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
	return;
}

Account::Account( void )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created";
	std::cout << std::endl;

	Account::_nbAccounts++;
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
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
	return ;
}

//public non static
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount<< ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	_totalNbDeposits++;
	return ;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal <= Account::checkAmount())
	{
		this->_nbWithdrawals++;
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount<< ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
		std::cout << std::endl;
		_totalNbWithdrawals++;
	}
	else
	{
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount<< ";";
		std::cout << "withdrawal:refused";
		std::cout << std::endl;
	}
	return (true);
}
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount<< ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ";";
	std::cout << std::endl;
	return ;
}

//private
void Account::_displayTimestamp( void )
{
	std::time_t now;
	std::tm *time;

	now = std::time(0);
	time  = localtime(&now);
	std::cout << "[" << time->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_mday << "_";
	std::cout << std::setw(2) << std::setfill('0') << time->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_sec << "] ";
	return ;
}