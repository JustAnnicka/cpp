#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	horde = zombieHorde(5, "horde");
	horde->announce();
	return (0);
}