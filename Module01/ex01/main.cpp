#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	int	N = 5;
	horde = zombieHorde(N, "Horde");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	std::cout << "\nNow we rename Horde pointer to 'Jorge'\n\n";
	horde->set_name("Jorge");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	//horde->announce();
	delete[] horde; // allows me to delete an array (from the back to front)
	return (0);
}