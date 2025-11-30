#include "Contact.hpp"

void Contact::set_first_name(std::string first_name)
{
    if (first_name.length() == 0)
    {
        std::cout << RED << "invalid input\n" << END << GREY << "Enter first name\n" << END;
        if (!std::getline(std::cin, first_name))
            return ;
        set_first_name(first_name);
    }
    else
        this->_first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
    if (last_name.length() == 0)
    {
        std::cout << RED << "invalid input\n" << END << GREY << "Enter last name\n" << END;
        if (!std::getline(std::cin, last_name))
            return ;
        set_last_name(last_name);
    }
    else
        this->_last_name = last_name;
}

void Contact::set_nickname(std::string nickname)
{
    if (nickname.length() == 0)
    {
        std::cout << RED << "invalid input\n" << END << GREY << "Enter nickname\n" << END;
        if (!std::getline(std::cin, nickname))
            return ;
        set_nickname(nickname);
    }
    else
        this->_nickname = nickname;
}

void Contact::set_secret(std::string secret)
{
    if (secret.length() == 0)
    {
        std::cout << RED << "invalid input\n" << END << GREY << "Enter secret\n" << END;
        if (!std::getline(std::cin, secret))
            return ;
        set_secret(secret);
    }
    else
        this->_secret = secret;
}

void Contact::set_number(std::string input)
{
    char *line = (char*)input.c_str();

    if (!atoi(line))
    {
        std::cout << RED << "invalid input\n" << END << GREY << "Enter number\n" << END;
        if (!std::getline(std::cin, input))
            return ;
        set_number(input);
    }
    else
        this->_phone_number = atoi(line);
}

Contact::Contact()
{}
Contact::~Contact()
{}

void    Contact::setup()
{
    std::string input = "";
    std::string question[] = {"Whats's your name?", "And your surname?", "Can i get your number?", "Give me your nickname?",  "Tell me your dark secret."};
    int i = 0;
    while (!std::cin.fail() && i < 5)
    {
        std::cout << GREY << question[i] << std::endl << END;
        if (!std::getline(std::cin, input))
            return ;
        if (i == 0)
            set_first_name(input);
        else if (i == 1)
            set_last_name(input);
        else if (i == 2)
            set_number(input);
        else if (i == 3)
            set_nickname(input);
        else if (i == 4)
            set_secret(input);
        i++;
    }
    std::cout << GREEN << this->_first_name << " was added as contact." << std::endl << END;
}

void    Contact::display_contact()
{
    std::cout << GREY << "fist name:  "  << END << this->_first_name << std::endl;
    std::cout << GREY << "last name:  "  << END << this->_last_name << std::endl;
    std::cout << GREY << "nickname:   "  << END << this->_nickname << std::endl;
    std::cout << GREY << "phonenumber: "  << END << this->_phone_number << std::endl;
    std::cout << GREY << "dark secret: "  << END << this->_secret << std::endl;
}

std::string Contact::get_first_name() {
	return this->_first_name;
}
std::string Contact::get_last_name() {
	return this->_first_name;
}
std::string Contact::get_nickname() {
	return this->_first_name;
}
