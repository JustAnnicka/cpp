#include <iostream>

// At program startup the phonebook is empty.
// User is prompted to enter one of three commands
// -> ADD, SEARCH and EXIT (no other is accepted)
// --> ADD: save a new contact
// ---> user is prompted to unput information of the new contact one field at a time
// ----> (once all are complete add the contact to the phonebook)
// --->Contact fields are first name, last name, nickname, phone number, and darkest secret, (fields can't be empty)

// --> SEARCH: display a specific contact
// ---> display the saved contacts as a list of 4 collumns: index, first name, last name, and nickname
// ----> each collumn is 10 characters wide. A pipe (|) character seperates them. 
// -----> if text is longer than 10 chars it should be truncated and the last char replaced by a dot (.)
// ---> After displaying the contact list prompt the user to for the index of the etry to display
// ----> If the index is out of range or wrong define a relevant behaviour (error message)
// ----> else display the contact information one field per line

// --> EXIT
// ---> The program quits and the contacts are lost forever!

// All other input is ignored

// if more than 8 contacts are created delete/overwrite the oldest one

#include <iostream>
#include <iomanip> //for fields and time
#include <string>

void    list_contacts(void)
{
    std::string firstName;
    std::string lastName;
    std::string nickName;

    firstName = "ANNNNIIICKA";
    lastName = "EHRL";
    nickName = "CapAndHat";

    std::cout << std::setw(10) << "index" << "|";
    if (firstName.length() > 10)
        std::cout << std::setw(10) << firstName.substr(0, 9) << "." << "|"; //check memmory leaks
    else
        std::cout << std::setw(10) << firstName << "|";
    if (lastName.length() > 10)
       std::cout << std::setw(10) << lastName.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << lastName << "|";
    if (nickName.length() > 10)
        std::cout << std::setw(10) << nickName.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << nickName << "|";
    std::cout << std::endl;
}


int ft_input(void)
{
    char line[256];

    std::cin.getline(line, 256);
    std::string  input(line);
    
    input.shrink_to_fit();
    if (!input.compare("ADD"))
        return(std::cout << "ADD detected" << std::endl ,1);
    else if (!input.compare("SEARCH"))
        return(std::cout << "SEARCH detected" << std::endl ,1);
    else if (!input.compare("EXIT"))
        exit(0); // am i allowed to use this???
    return (0);
}
int main(int argc, char *argv[])
{
    (void)argv;
    if (argc != 1)
        return (std::cout << "Error\nJust execute the program"<< std::endl, 0);
    while (1)
    {
        std::cout << "Please enter a command" << std::endl;
        if(!ft_input())
            std::cout << "Error\nOnly ADD, SEARCH or EXIT are valid commands"<< std::endl;
    }
    return (0);
}