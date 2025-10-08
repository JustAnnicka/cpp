#ifndef CONTACT_HPP
 #define  CONTACT_HPP
 
 #include <iostream>
 #include <cstdlib>
 #include <string>

 #define RED    "\033[31m"
 #define GREEN    "\033[32m"
 #define GREY  	"\033[30m"     
 #define GREYB "\033[1,30m"     
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
        int    setup();
        void    display_contact();
        Contact();
        ~Contact();
};

#endif
