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
    public:
        void        set_first_name(std::string first_name);
        void        set_last_name(std::string last_name);
        void        set_nickname(std::string nickname);
        void        set_secret(std::string secret);
        void        set_number(std::string input);
        void        setup();
        void        display_contact();

        std::string  get_first_name();
        std::string  get_last_name();
        std::string  get_nickname();
        Contact();
        ~Contact();

    private:
        std::string _secret;
        int         _phone_number;
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
   
};

#endif
