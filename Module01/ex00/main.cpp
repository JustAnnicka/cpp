#include "Zombie.hpp"

int	main()
{
	Zombie	normal_Zombie;
	Zombie *new_Zombie;

	new_Zombie = newZombie("Zombie");
	randomChump("Chump");
	new_Zombie->announce();
	normal_Zombie.announce();
	delete(new_Zombie);

	return (0);
}