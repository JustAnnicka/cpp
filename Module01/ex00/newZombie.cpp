
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*new_Zb = new (std::nothrow) Zombie(name); //new is just dynamic memmory assignment (no malloc)
	if (new_Zb == NULL)
		std::cout << "Error\nCreating new Zombie";
	//new_Zb =  // new is 
	return (new_Zb);
}

//endl flushes stream buffer '\n' does not
//delete new_Zb would delete the allocated memmory (like free)