 #ifndef PHONEBOOK_H
 #define	PHONEBOOK_H

 #include <iomanip> 
 #include <iostream>
 #include "Contact.hpp"
 #include <sstream>

class	PhoneBook
{
	private:

	public:
		Contact	entrys[8];
		int size;
		PhoneBook();
		void	print_phonebook_list();
		int		new_entry();
		int	view_entry();
};

int get_number();
#endif
