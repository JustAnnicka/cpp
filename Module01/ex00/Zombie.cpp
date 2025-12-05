
#include "Zombie.hpp"

Zombie::Zombie(){_name = "Random";}

Zombie::~Zombie()
{
	std::cout << "destroyed " << _name << std::endl;
}

Zombie::Zombie(const std::string name) : _name(name){}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}