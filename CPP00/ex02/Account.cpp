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
	(void)initial_deposit;
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
	return (0);
}

int	Account::getTotalAmount( void )
{
	return (0);
}

int	Account::getNbDeposits( void )
{
	return (0);
}

int	Account::getNbWithdrawals( void )
{
	return (0);
}

void	Account::displayAccountsInfos( void )
{
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
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;


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