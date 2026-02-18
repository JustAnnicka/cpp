#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <limits>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <cmath>

class BitcoinExchange{
    public:
        BitcoinExchange();
        BitcoinExchange(std::string db);
        
        ~BitcoinExchange();

        void findBitcoinValue(std::string input); // could be long or unsigned float?
       // bool isFormatValid(std::string str)
       // bool isDateValid(std::string date)
       // bool isValueValid(float v)

    class ConstructionFail : public  std::exception{
	    public:
			virtual const char* what() const throw();
    };
    class FormatNotValid : public  std::exception{
	    public:
			virtual const char* what() const throw();
    };
    class DateNotValid : public  std::exception{
	    public:
			virtual const char* what() const throw();
    };
    class ValueNotValid : public  std::exception{
	    public:
			virtual const char* what() const throw();
	};
    class NegativeValue : public  std::exception{
	    public:
			virtual const char* what() const throw();
	};
    class OverMaxValue : public  std::exception{
	    public:
			virtual const char* what() const throw();
	};

    private:
        std::map<std::string,float> _db;
        bool createDatabase(std::string input);
        void isDatabaseValid(std::string str);
        void isDBFormatValid(std::string str);
        void isFormatValid(std::string str);
        void isDateValid(std::string date);
        float isValueValid(std::string value);
        float isDBValueValid(std::string value);
};

#endif