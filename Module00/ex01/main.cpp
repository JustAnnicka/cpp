#include <iostream>

// At program startup the phonebook is empty.
// User is prompted to enter one of three commands
// -> ADD, SEARCH and EXIT (no other is accepted) DONE
// --> ADD: save a new contact
// ---> user is prompted to input information of the new contact one field at a time DONE
// ----> (once all are complete add the contact to the phonebook) DONE
// --->Contact fields are first name, last name, nickname, phone number, and darkest secret, (fields can't be empty)
//---> if contact number is over 8 replace the oldest contact in the phonebook DONE

// --> SEARCH: display a specific contact
// ---> display the saved contacts as a list of 4 collumns: index, first name, last name, and nickname
// ----> each collumn is 10 characters wide. A pipe (|) character seperates them. DONE
// -----> if text is longer than 10 chars it should be truncated and the last char replaced by a dot (.)
// ---> After displaying the contact list prompt the user to for the index of the etry to display DONE
// ----> If the index is out of range or wrong define a relevant behaviour (error message)
// ----> else display the contact information one field per line DONE

// --> EXIT DONE
// ---> The program quits and the contacts are lost forever! DONE

// All other input is ignored (IE NO ERROR MESSAGE???) DONE

#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
    PhoneBook   pb;
    std::string input = " ";

    (void)argv;
    if (argc != 1)
        return (std::cout << RED << "Error\nJust execute the program"<< std::endl << END, 1);
    while (1)
    {
        std::cout << GREYB << "valid commands: ADD | SEARCH | EXIT" << std::endl << END;
        std::getline(std::cin, input);
        if (input == "ADD")
            pb.new_entry();
        else if (input == "SEARCH")
        {
            pb.print_phonebook_list();
            pb.view_entry();
        }
        else if (input == "EXIT")
            break ;
    }
    return (0);
}