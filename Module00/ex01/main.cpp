#include <iostream>

// At program startup the phonebook is empty.
// User is prompted to enter one of three commands
// -> ADD, SEARCH and EXIT (no other is accepted)
// --> ADD: save a new contact
// ---> user is prompted to input information of the new contact one field at a time
// ----> (once all are complete add the contact to the phonebook)
// --->Contact fields are first name, last name, nickname, phone number, and darkest secret, (fields can't be empty)

// --> SEARCH: display a specific contact
// ---> display the saved contacts as a list of 4 collumns: index, first name, last name, and nickname
// ----> each collumn is 10 characters wide. A pipe (|) character seperates them. 
// -----> if text is longer than 10 chars it should be truncated and the last char replaced by a dot (.)
// ---> After displaying the contact list prompt the user to for the index of the etry to display
// ----> If the index is out of range or wrong define a relevant behaviour (error message)
// ----> else display the contact information one field per line

// --> EXIT DONE
// ---> The program quits and the contacts are lost forever! DONE

// All other input is ignored (IE NO ERROR MESSAGE???)

// if more than 8 contacts are created delete/overwrite the oldest one

#include "PhoneBook.hpp"
#include "Contact.hpp"

int ft_input(PhoneBook *pb)
{
    char line[256];
    std::string  input;
    
    std::cin.getline(line, 256); //error handle line being over 256
    input = line;
    input.resize(input.size());
    if (!input.compare("ADD"))
        pb->new_entry();
    else if (!input.compare("SEARCH"))
    {
        pb->print_phonebook_list();
       // return(std::cout << "SEARCH detected" << std::endl ,1);
    }
   /*  else if (!input.compare("EXIT"))
        exit(0); // am i allowed to use this??? */
    else if (!input.compare("EXIT"))
        return (0);
    return (1);
}
int main(int argc, char *argv[])
{
    PhoneBook   pb;

    (void)argv;
    if (argc != 1)
        return (std::cout << "Error\nJust execute the program"<< std::endl, 0);
    std::cout << "Please enter a command" << std::endl;
    while (1)
    {
        if(!ft_input(&pb))
            break ;
/*         if(!ft_input())
            continue ; */
            //std::cout << "Error\nOnly ADD, SEARCH or EXIT are valid commands"<< std::endl;
    }
    return (0);
}