#include "Contact.hpp"

int get_number(std::string input)
{
    char *line = (char*)input.c_str();
    int  nbr;

    if (!atoi(line))
    {
        std::cout << RED << "invalid input\n" << END << GREY << "Enter number\n" << END; 
        if (std::getline(std::cin, input))
            nbr = get_number(input);
        else
            return (0);
    }
    else
        nbr = atoi(line);
    return (nbr);
}

Contact::Contact()
{}
Contact::~Contact()
{}

int    Contact::setup()
{
    std::string input = "";
    std::cout << GREY << "Whats's your name?" << std::endl << END;
    std::string question[] = {"And your surname?", "Can i get your number?", "Give me your nickname?",  "Tell me your dark secret."};
    int i = 0;
    while ( i < 5 && std::getline(std::cin, input))
    {
        if (input == "")
            return (0);
        if (i == 0)
            first_name = input;
        else if (i == 1)
            last_name = input;
        else if (i == 2)
          phone_number = get_number(input);
        else if (i == 3)
            nickname = input;
        else if (i == 4)
            secret = input;
        std::cout << GREY << question[i] << std::endl << END;
        i++;
    }
    std::cout << GREEN << first_name << " was added as contact." << std::endl << END;
    return (1);
}

void    Contact::display_contact()
{
    std::cout << GREY << "fist name:  "  << END << first_name << std::endl;
    std::cout << GREY << "last name:  "  << END << last_name << std::endl;
    std::cout << GREY << "nickname:   "  << END << nickname << std::endl;
    std::cout << GREY << "phonenumber: "  << END << phone_number << std::endl;
    std::cout << GREY << "dark secret: "  << END << secret << std::endl;
}