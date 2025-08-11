#include "Account.hpp"

Account::Account(){
    
   // _nbAccounts = getNbAccounts();
   // _totalAmount = getTotalAmount();
   // _totalNbDeposits = getNbDeposits();
   // _nbWithdrawals = getNbWithdrawals();
};
Account::Account(int initial_deposit){
 (void)initial_deposit;
    //  makeDeposit(initial_deposit);
};
Account::~Account(){};
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
    //std::cout << "Account: " << _accountIndex << std::endl;
   // std::cout << "Total amount: " << _totalAmount << std::endl;
  //  std::cout << "Timestamp:  " << Account::_displayTimestamp << std::endl;
   // std::cout << "Total amount: " << _totalAmount << std::endl;

}
void	Account::makeDeposit( int deposit )
{
    (void)deposit;
   //  _totalAmount +=  deposit;
   //  _totalNbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    (void)withdrawal;
    return (true);
}
int		Account::checkAmount( void ) const
{
    return 1;
}
void	Account::displayStatus( void ) const
{

}

/* int main (int argc, char *argv[])
{
    
    return (0);
}
*/ 