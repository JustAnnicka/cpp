// Stand for a phonebook contact
// contacts must be instantiated as an instance of the Contacts class
// -> each contact mus be an instance ofg the Contacts class
#include "Contact.hpp"

std::string get_input()
{
    char line[256];
    std::string  input;

    std::cin.getline(line, 256);
    input = line;
    return (line);
}

int get_number()
{
    char line[256];
    int  nbr;

    std::cin.getline(line, 256); 
    nbr = atoi(line); //could be done with a stringstream?
    
    return (nbr);
}

Contact::Contact()
{
   
}
void    Contact::setup()
{
    std::cout << "Whats's your name?" << std::endl;
    first_name = get_input();
    std::cout << "And your surname?" << std::endl;
    last_name = get_input();
    std::cout << "Can i get your number?" << std::endl;
    phone_number =get_number();
    std::cout << "give me your nickname?" << std::endl;
    nickname = get_input();
    std::cout << "Tell me your dark secret." << std::endl;
    secret = get_input();
}

void    Contact::display_contact()
{
    std::cout << first_name << std::endl;
    std::cout << last_name << std::endl;
    std::cout << nickname << std::endl;
    std::cout << phone_number << std::endl;
    std::cout << secret << std::endl;
}

/*
Contact::~Contact()
{

} */

