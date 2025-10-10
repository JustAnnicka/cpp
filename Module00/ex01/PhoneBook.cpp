#include "PhoneBook.hpp"

void	PhoneBook::print_phonebook_list(void)
{
	int	i;

	i = 0;
	std::cout << GREY << "index     |name      |surname   |nickname"  <<std::endl << END;
	while (i < size)
	{
		std::cout << std::setw(10) <<  std:: left << i << "|";
		if (entrys[i].first_name.length() > 10)
			std::cout << std::setw(10) << entrys[i].first_name.substr(0, 9) + "."; //check memmory leaks
		else
			std::cout << std::setw(10) << entrys[i].first_name;
		std::cout << "|";
		if (entrys[i].last_name.length() > 10)
			std::cout << std::setw(10) << entrys[i].last_name.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << entrys[i].last_name;
		std::cout << "|";
		if (entrys[i].nickname.length() > 10)
			std::cout << std::setw(10) << entrys[i].nickname.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << entrys[i].nickname;
		std::cout << std::endl << END;
		i++;
	}
}

PhoneBook::PhoneBook() : size(0) {}

void	PhoneBook::new_entry()
{
	Contact	new_entry;
	static int	oldest;

	new_entry.setup();
	if (size < 8)
	{
		entrys[size] = new_entry;
		size++;
	}
	else
	{
		if (oldest == 8)
			oldest = 0;
		entrys[oldest].~Contact();
		entrys[oldest] = new_entry;
		oldest++;
	}
}

void	PhoneBook::view_entry()
{
	std::string	input	= " ";
	int i;
	
	if (size == 0)
	{
		std::cout << GREY << "No contacts to display! Create one with ADD" << END << std::endl;
		return ;
	}
	print_phonebook_list();
	std::cout << GREY << "Please enter the Contact index to view" << END << std::endl;
	std::getline(std::cin, input); 
	std::stringstream stream(input);
	if (input == "")
            return ;
	stream >> i;
	if (i > 8 || i > size || i < 0) 
		std::cout <<RED"not a valid index" << END << std::endl;
	else
	{
		std::cout << GREY << "Contact #" << i << END << std::endl;
		entrys[i].display_contact();
	}
}