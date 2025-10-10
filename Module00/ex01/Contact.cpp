#include "Contact.hpp"

void Contact::get_number(std::string input)
{
    char *line = (char*)input.c_str();

    if (!atoi(line))
    {
        std::cout << RED << "invalid input\n" << END << GREY << "Enter number\n" << END;
        if (!std::getline(std::cin, input))
            return ;
        get_number(input);
    }
    else
        phone_number = atoi(line);
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
    while ( i < 5)
    {
        std::cout << GREY << question[i] << std::endl << END;
        if (!std::getline(std::cin, input))
            return ;
        if (i == 0)
            first_name = input;
        else if (i == 1)
            last_name = input;
        else if (i == 2)
            get_number(input);
        else if (i == 3)
            nickname = input;
        else if (i == 4)
            secret = input;
        i++;
    }
    std::cout << GREEN << first_name << " was added as contact." << std::endl << END;
}

void    Contact::display_contact()
{
    std::cout << GREY << "fist name:  "  << END << first_name << std::endl;
    std::cout << GREY << "last name:  "  << END << last_name << std::endl;
    std::cout << GREY << "nickname:   "  << END << nickname << std::endl;
    std::cout << GREY << "phonenumber: "  << END << phone_number << std::endl;
    std::cout << GREY << "dark secret: "  << END << secret << std::endl;
}