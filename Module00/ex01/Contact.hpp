#ifndef CONTACT_HPP
 #define  CONTACT_HPP
 
 #include <iostream>
 #include <cstdlib>
 #include <string>
 #include <sstream> //needed for stream (possibe to do this differently?)

 #define RED    "\033[31m"
 #define GREY  	"\033[30m"     
 #define GREY_B "\033[1,30m"     
 #define END  	"\033[0m"

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
        void    display_contact();
        Contact(); //constructor 
        ~Contact();
};

#endif
