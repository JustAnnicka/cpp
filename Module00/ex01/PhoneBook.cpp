// Phonebook must be instantiated as an instance of the PhoneBook class(same for contacts)
#include "PhoneBook.hpp"

void	PhoneBook::print_phonebook_list(void)
{
	int	i;

	i = 0;
	while (i < size)
	{
		std::cout << std::setw(11) << i << "|";
		if (entrys[i].first_name.length() > 11)
			std::cout << std::setw(11) << entrys[i].first_name.substr(0, 9) << "." << "|"; //check memmory leaks
		else
			std::cout << std::setw(11) << entrys[i].first_name << "|";
		if (entrys[i].last_name.length() > 11)
		std::cout << std::setw(11) << entrys[i].last_name.substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(11) << entrys[i].last_name << "|";
		if (entrys[i].nickname.length() > 11)
			std::cout << std::setw(11) << entrys[i].nickname.substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(11) << entrys[i].nickname << "|";
		std::cout << std::endl;
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
		//delete orignal oldest entry contact
		entrys[oldest] = new_entry;
		oldest++;
	}
}

void	PhoneBook::view_entry()
{
	int i;

	i = get_number();
	if (i > 8 || i > size)
		std::cout << "not a valid index" << std::endl;
	else
		entrys[i].display_contact();
}