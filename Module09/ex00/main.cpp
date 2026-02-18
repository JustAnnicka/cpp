
#include "BitcoinExchange.hpp"

int main (int argc, char  *argv[])
{
	if (argc != 2)
		return (std::cout << "Error\nWrong number of arguments" << std::endl, 1);
	std::ifstream file (argv[1]);
	if(file.fail())
		return (std::cout << "Error: could not open file.") << std::endl, 1;
	if (file.is_open()) {
		try{
			BitcoinExchange exchange;
			std::string line;
			int count = 0;
			while (getline(file, line)) {
				if (count == 0 && line == "date | value");
				else
					exchange.findBitcoinValue(line);

				//check if first line == "date | value" in this case skip check
				std::cout << line << std::endl;
				//do the exchange task
				//find the value by lower bound
				//check if the date is valid (eg numbers over 31 are forbidden)
					// insane but maybe chek for leap years as well
				//then do the multiplication (all in the class) output value or error
			}
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
		file.close();
    }
	// input file need to follow this formating per line:
	// "date | value".
	
	// A valid date is in this format:
	// Year-Month-Day

	// A valid value must be either a float or a positive intefer (between 0 & 1000)


/* You must use at least one container in your code to validate this
exercise. You should handle possible errors with an appropriate
error message. */

/* If the date used in the input does not exist in your DB then you
must use the closest date contained in your DB. Be careful to use the
lower date and not the upper one. */
}

//EXAMPLE OUTPUT OF SUBJECT
/* $> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$> */
