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
        if (!std::getline(std::cin, input))
            return (1);
        if (input == "ADD")
        {
            if (!pb.new_entry())
                break ;
        }
        else if (input == "SEARCH")
        {
            pb.print_phonebook_list();
            if (!pb.view_entry())
                break ;
        }
        else if (input == "EXIT")
            break ;
    }
    return (0);
}