#include "Contact.hpp"

std::string get_input()
{
    char line[256];
    std::string  input;

    std::cin.getline(line, 256);
    input = line;
    if (input.size() == 0)
    {
        std::cout << RED << "empty fields are not valid\n" << GREY << "please input data\n" << END;  
        input = get_input();
    }
    return (input);
}

int get_number()
{
    char line[256];
    int  nbr;

    std::cin.getline(line, 256);
    if (!atoi(line))
    {
        std::cout << RED << "invalid input\n" << END << GREY << "Enter number\n" << END; 
        nbr = get_number();
    }
    else
        nbr = atoi(line);
    return (nbr);
}

Contact::Contact()
{}
Contact::~Contact()
{}

void    Contact::setup()
{
    std::cout << GREY << "Whats's your name?" << std::endl << END;
    first_name = get_input();
    std::cout << GREY << "And your surname?" << std::endl << END;
    last_name = get_input();
    std::cout << GREY << "Can i get your number?" << std::endl << END;
    phone_number = get_number();
    std::cout << GREY << "give me your nickname?" << std::endl << END;
    nickname = get_input();
    std::cout << GREY << "Tell me your dark secret." << std::endl << END;
    secret = get_input();
}

void    Contact::display_contact()
{
    std::cout << GREY << "fist name:  "  << END << first_name << std::endl;
    std::cout << GREY << "last name:  "  << END << last_name << std::endl;
    std::cout << GREY << "nickname:   "  << END << nickname << std::endl;
    std::cout << GREY << "phonenumber: "  << END << phone_number << std::endl;
    std::cout << GREY << "dark secret: "  << END << secret << std::endl;
}