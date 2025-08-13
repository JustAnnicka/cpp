#include "Account.hpp"
#include <ctime> //to work with time

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(){}
void	Account::_displayTimestamp( void )
{
   
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"%Y%m%d_%H%M%S",timeinfo);
    // Display the date and time represented by the timestamp
    //cout << ctime(&timestamp);
    std::cout << "[" << buffer << "] ";
}

Account::Account(int initial_deposit){

    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount <<";";
    std::cout << "created" << std::endl;
    _nbAccounts++;
}
Account::~Account(){
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount <<";";
    std::cout << "closed" << std::endl;
};
int Account::getNbAccounts( void )
{
    return (1);
   // __nbAccounts=
}

int	Account::getTotalAmount( void ){ return (1);}
int	Account::getNbDeposits( void ){ return (1);}
int	Account::getNbWithdrawals( void ){ return (1);}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "acounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << ";" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "deposits:" << deposit << ";";
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << ";" << std::endl;

}
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    if (withdrawal > _amount)
    {
        std::cout << "withrdrawal:refused" << std::endl;
        return (false);
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << "withrdrawal:" << withdrawal << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << ";" << std::endl;
    return (true);
}
int		Account::checkAmount( void ) const
{
    return (_amount);
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawls:" << _nbWithdrawals << ";" << std::endl;
}
