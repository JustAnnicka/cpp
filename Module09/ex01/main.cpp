
#include "RPN.hpp"

//program takes inverted Polish mathematical excpression as an argument
    //The numbers used in this operation and passed as arguments will always be < 10.
    //does not apply to the calculation and result 
//Program mus process this expression and output the correct result on the standard output
//If eroor there should be a standard error displayd
//program must handle to handle operations with these tokens "+ - / *"
    // NO NEED TO HANDLE BRACKETS OR DECIMALS

//VECtor s might be the way to go
// Stack

int main (int argc, char *argv[])
{
    if (argc != 2)
       return ( std::cerr << "Error: Wrong number of arguments" << std::endl, 1);
   
    try{
        RPN calc(argv[1]);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

}


/* $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$> */