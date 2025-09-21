#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>//do i neew this i think not
#include <string>

class	Zombie
{
	private:
		std::string	name;
	public:
		void	announce(void); //should be a member function?
		Zombie();
		Zombie(const std::string name);
		~Zombie();	
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
