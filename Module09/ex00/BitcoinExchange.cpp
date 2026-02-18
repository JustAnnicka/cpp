#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::cout << "BitcoinExchange constructor called" << std::endl;
    if (!createDatabase("data.csv"))
        throw(ConstructionFail());
}

BitcoinExchange::BitcoinExchange(std::string db){
    std::cout << "BitcoinExchange string constructor called" << std::endl;
    //size_t 
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
   // std::pair<std::map<std::string,int>::iterator,bool> it;
    if (file.is_open()) {
		std::string line;
        while (getline(file, line)) {
            if (_db.size() == 0 && line == "date,exchange_rate");
            else{
                try{
                    isDBFormatValid(line);
                    std::string date = line.substr(0,10);
                    //isDateValid(date);
                    std::string value = line.substr(11);
                  //  std::size_t found_nl = value.find("\n");
                  //  if (found_nl == std::string::npos)
                  //      value.resize(found_nl);
                   // if (*value.rbegin() == '/n')
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

float BitcoinExchange::getExchangeRate(std::string date){
    //std::map<char,int>::iterator itlow;
    //itlow = _db.lower_bound(date)->second;
    return(_db.lower_bound(date)->second);
}

void BitcoinExchange::findBitcoinValue(std::string input){
    try{
        isFormatValid(input);
        std::string date = input.substr(0,10);
        isDateValid(date);
        std::string value = input.substr(13);
        //std::size_t found_nl = value.find("\n");
        //if (found_nl == std::string::npos)
        //        value.resize(found_nl);
     /*    if (*value.rbegin() == '/n')
        {
            value.erase(value.end()-1);
        } */
        float n = isValueValid(value);
        float rate = getExchangeRate(date);
        std::cout << date << "=> " << value << " = " << std::setprecision(1) << std::fixed << n * rate ;
    }
    catch(std::exception &e) // make specific catches to print correspoding value
    {
        std::cout << e.what() << std::endl;
        return ;
    }
   
}

// I think I need the throws here so that i can continue the loop in the main thing
float BitcoinExchange::isValueValid(std::string str){
    
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
    
/*     std::string::size_type pos = str.find("-");
    if (pos != 4)
        return(false);
    std::string::size_type pos = str.find("-", pos+1);
    if (pos != 4)
        return(false); */
}
void BitcoinExchange::isDBFormatValid(std::string str){
    if(str.length() < 11)
        throw(FormatNotValid());
   // std::cout << "len: " << str.length() << std::endl;
    if (str[4] != '-' || str[7] != '-' || str[10] != ',')
    {
     //   std::cout << "enter" << std::endl;
        throw(FormatNotValid());
    }
   // std::cout << "4:" << str[4] << " 7:" << str[7] << " 10:" << str[10] << std::endl;
}
// new idea convert the string into a t_time format, then check that by comparing the output strings
// if the day was over 28/30/31 the convert will change it to the next month eg if the dates are not equal its a false date


void BitcoinExchange::isDateValid(std::string date){
    
    // init a tm structur for parsed date
  //  std::cout << "date input "<< date << std::endl;
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 7);
    std::string day = date.substr(8, 9);;
   // std::cout << year << " " << month << " " << day << std::endl;
    tm time = {};
    time.tm_year = atoi(year.c_str()) - 1900;
    time.tm_mon = atoi(month.c_str()) - 1;
    time.tm_mday = atoi(day.c_str());
   // std::cout << "year: "<< time.tm_year << " month: " << time.tm_mon << " day: " << time.tm_mday << std::endl;
    char buffer [80];
    /* 
    //SADLY CPP11
    std::istringstream ss(date);
    ss >> get_time(&tm, "%F"); //Short YYYY-MM-DD date, equivalent to %Y-%m-%d
    if (ss.fail)
        throw(DateNotValid()); */

    // return (false);
    
    //convert the parsed date to a time_t value
    time_t d = mktime(&time);
    //std::string check = asctime(localtime(&d));
    strftime(buffer, 80,"%F", localtime(&d));
    std::string check = buffer;
    if (check != date)
    {
        std::cout << "ERR: check = " << check << " date= " << date << std::endl;
        throw(DateNotValid());
    }
       
        //return(false)
   // return (true);
}

//  === EXCEPTIONS ===

const char *BitcoinExchange::ConstructionFail::what() const throw(){
    return ("Error: Construction of BitcointExchange failed");
};
const char *BitcoinExchange::FormatNotValid::what() const throw(){
    return ("Error: bad format => ");
};
const char *BitcoinExchange::DateNotValid::what() const throw(){
    return ("Error: bad input => ");
};
const char *BitcoinExchange::ValueNotValid::what() const throw(){
    return ("Error: bad input => ");
};
const char *BitcoinExchange::NegativeValue::what() const throw(){
    return ("Error: not a positive number.");
};
const char *BitcoinExchange::OverMaxValue::what() const throw(){
    return ("Error: too large a number.");
};
