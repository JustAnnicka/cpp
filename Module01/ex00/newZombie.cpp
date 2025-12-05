
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*new_Zb = new (std::nothrow) Zombie(name);
	if (new_Zb == NULL)
		std::cout << "Error\nCreating new Zombie";
	return (new_Zb);
}
