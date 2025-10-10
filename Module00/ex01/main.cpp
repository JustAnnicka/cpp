#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
    PhoneBook   pb;
    std::string input;

    (void)argv;
    if (argc != 1)
        return (std::cout << RED << "Error\nJust execute the program"<< std::endl << END, 1);
    while ((!std::cin.fail() && input != "EXIT"))
    {
        std::cout << GREYB << "valid commands: ADD | SEARCH | EXIT" << std::endl << END;
        if (!std::getline(std::cin, input))
            return (1);
        if (input == "ADD")
            pb.new_entry();
        else if (input == "SEARCH")
            pb.view_entry();
    }
    return (0);
}