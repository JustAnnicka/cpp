#include "Account.hpp"
#include <ctime> //to work with time and add the std thing so taht i add the proper structures

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(){}
void	Account::_displayTimestamp( void )
{
    //double check this with std::time
   
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"%Y%m%d_%H%M%S",timeinfo);
    std::cout << "[" << buffer << "] ";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount <<";";
    std::cout << "created" << std::endl;
    _nbAccounts++;
}
Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount <<";";
    std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "deposit:" << deposit << ";";
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;

}
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}
int		Account::checkAmount( void ) const {return (_amount);}

int	Account::getTotalAmount( void ){ return (_totalAmount);}
int Account::getNbAccounts( void ){ return (_nbAccounts);}
int	Account::getNbDeposits( void ){ return (_totalNbDeposits);}
int	Account::getNbWithdrawals( void ){ return (_totalNbWithdrawals);}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
