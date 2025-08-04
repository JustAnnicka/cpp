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

// --> EXIT DONE
// ---> The program quits and the contacts are lost forever! DONE

// All other input is ignored (IE NO ERROR MESSAGE???)

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
class Contact
{
    private:
        std::string secret;
        std::string first_name;
       // int phone_number;
    public:
        
        void    set_name(std::string _fname);
        std::string last_name;
        std::string nickname;
        std::string time;
        int phone_number;
        void        set_phonenumber();
       // Contact(/* args */);
       // ~Contact();
};

void    Contact::set_name(char *name)
{
    std::string  input;

    //std::cout << "Enter name " << std::endl;
    input = name;
    first_name = input;

}
void    Contact::set_phonenumber()
{
    int n;
    
    std::cin >> n;
    phone_number = n;
   
}

int ft_input(void)
{
    char line[256];
    char name[256];
    std::string  input;
    Contact         Contact;
    std::cin.getline(line, 256); //error handle line being over 256
   // std::string  input(line); //are constructors allowed?
    input = line;
    input.shrink_to_fit();
    if (!input.compare("ADD"))
    {
        Contact.set_phonenumber();
        input.clear();

        std::cout << "Enter name " << std::endl;
        std::cin.getline(name, 256);
        Contact.set_name(name);
        std::cout << Contact.phone_number << Contact.first_name << std::endl;
        return(1);
    }
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
    std::cout << "Please enter a command" << std::endl;
    while (1)
    {
        if(!ft_input())
            continue ;
            //std::cout << "Error\nOnly ADD, SEARCH or EXIT are valid commands"<< std::endl;
    }
    return (0);
}