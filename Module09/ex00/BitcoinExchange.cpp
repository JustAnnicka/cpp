#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::cout << "BitcoinExchange constructor called" << std::endl;
    if (!createDatabase("data.csv"))
        throw(ConstructionFail());
}

BitcoinExchange::BitcoinExchange(std::string db){
    std::cout << "BitcoinExchange string constructor called" << std::endl;
    std::string ref = db.substr(db.size() - 4);
    if (ref != ".csv")
    {
        std::cout << "Error: invalid file format" << std::endl;
        throw(ConstructionFail());
    }
    if (!createDatabase(db))
        throw(ConstructionFail());
}

BitcoinExchange::~BitcoinExchange(){
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

bool BitcoinExchange::createDatabase(std::string input){
    std::ifstream file(input.c_str(), std::ifstream::in);
	if(file.fail())
    {
		std::cout << "Error: could not open csv file." << std::endl;
        return(false);
    }
    if (file.is_open()) {
		std::string line;
        while (getline(file, line)) {
            if (_db.size() == 0 && line == "date,exchange_rate");
            else{
                try{
                    isDBFormatValid(line);
                    std::string date = line.substr(0,10);
                    isDateValid(date);
                    std::string value = line.substr(11);
                    float n = isDBValueValid(value);  
                    _db.insert (std::pair<std::string,float>(date,n));
                 /*    it = _db.insert (std::pair<std::string,float>(date,n));
                    if (it.second==false) {
                        std::cout << "element 'z' already existed";
                        std::cout << " with a value of " << it.first->second << '\n';
                        return(false);
                    }  */
                }
                catch(std::exception &e)
                {
                    std::cout << "Error: csv " << e.what() << line << std::endl;
                    file.close();
                    return(false);
                }
            }
            // check for first line and skip validity checks (date,exchange_rate)
            /* if (!isDatabaseValid(line))
            {
                std::cout << "Error: csv format not valid file." << std::endl;
                file.close();
                return(false);
            } */
            
        }
    }
    file.close();
    return (true);
}

void BitcoinExchange::findBitcoinValue(std::string input){
    try{
        isFormatValid(input);
        std::string date = input.substr(0,10);
        isDateValid(date);
        std::string value = input.substr(13);
        float n = isValueValid(value);
        std::map<std::string, float>::iterator itLow = _db.lower_bound(date);
        if (date != itLow->first)
            itLow--;    
       float rate = itLow->second;
        std::cout << date << " => " << value << " = " << std::setprecision(2) << n * rate << std::endl;
    }
    catch(FormatNotValid::exception &e) // make specific catches to print correspoding value
    {
        std::cout << e.what() << input << std::endl;
        return ;
    }
    catch(DateNotValid::exception &e)
    {
        std::cout << e.what() << input.substr(0,10) << std::endl;
        return ;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
}

float BitcoinExchange::isValueValid(std::string str){
    
    int check = 0;
    size_t i = 0;
    if (str[i] == '-')
        i++;
    while(i < str.length())
    {
        if (str[i] == '.')
        {
            check++;
            if (check != 1)
                throw(ValueNotValid());
        }
        else if (!std::isdigit(str[i]))
            throw(ValueNotValid());
        i++;
    }
    float n;
    std::stringstream ss(str);
    ss >> n;
    if (ss.fail()){
        throw(ValueNotValid());
    }
    if (n < 0)
        throw(NegativeValue());
    if (n > 1000)
        throw(OverMaxValue());
    return (n);
}
float BitcoinExchange::isDBValueValid(std::string str){
    
    int check = 0;
    size_t i = 0;
    while(i < str.length())
    {
        if (str[i] == '.')
        {
            check++;
            if (check != 1)
                throw(ValueNotValid());
        }
        else if (!std::isdigit(str[i]))
            throw(ValueNotValid());
        i++;
    }
    float n;
    std::stringstream ss(str);
    ss >> n;
    if (ss.fail()){
        throw(ValueNotValid()); //maybe OverMaxValue
    }
    if (n < 0)
        throw(NegativeValue());
    return (n);
}

void BitcoinExchange::isFormatValid(std::string str){
    if(str.length() < 14)
        throw(FormatNotValid());
    if (str[4] != '-' || str[7] != '-' || !(str.compare(10,3," | ") == 0))
        throw(FormatNotValid());
}

void BitcoinExchange::isDBFormatValid(std::string str){
    if(str.length() < 11)
        throw(FormatNotValid());
    if (str[4] != '-' || str[7] != '-' || str[10] != ',')
        throw(FormatNotValid());
}

void BitcoinExchange::isDateValid(std::string date){
    
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 7);
    std::string day = date.substr(8, 9);;
    tm time = {};
    time.tm_year = atoi(year.c_str()) - 1900;
    time.tm_mon = atoi(month.c_str()) - 1;
    time.tm_mday = atoi(day.c_str());
    char buffer [80];
  
    time_t d = mktime(&time);
    strftime(buffer, 80,"%F", localtime(&d));
    std::string check = buffer;
    if (check != date)
        throw(DateNotValid());
}

//  === EXCEPTIONS ===

const char *BitcoinExchange::ConstructionFail::what() const throw(){
    return ("Error: Construction of BitcointExchange failed");
};
const char *BitcoinExchange::FormatNotValid::what() const throw(){
    return ("Error: bad input => ");
};
const char *BitcoinExchange::DateNotValid::what() const throw(){
    return ("Error: date not valid => ");
};
const char *BitcoinExchange::ValueNotValid::what() const throw(){
    return ("Error: value not valid => ");
};
const char *BitcoinExchange::NegativeValue::what() const throw(){
    return ("Error: not a positive number.");
};
const char *BitcoinExchange::OverMaxValue::what() const throw(){
    return ("Error: too large a number.");
};
