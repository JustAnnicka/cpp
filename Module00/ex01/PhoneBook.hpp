// -> Has an array of contacts ->see contacts
// --> Can store a max of 8 Contacts contacts[8]
// Dynamic allocation is forbiden (No string thing??)

#ifndef PHONEBOOK_H
 #define	PHONEBOOK_H

 #include <iomanip> 
 #include "Contact.hpp"

class	PhoneBook
{
	private:

	public:
		Contact	entrys[8];
		int size;
		PhoneBook();
		void	print_phonebook_list();
		void	new_entry();
		void	view_entry();
};

int get_number(); // allowed??
#endif
