#ifndef CONTACT_HPP
 #define  CONTACT_HPP
 
 #include <iostream>
 #include <cstdlib>
 #include <string>

class Contact
{
    private:
        std::string secret;
        int phone_number;
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        void    setup();
     // std::string time_created; //decided to work with a counter
        Contact(); //constructor 
       // ~Contact();
};

#endif
