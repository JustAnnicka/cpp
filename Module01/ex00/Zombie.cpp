
#include "Zombie.hpp"

Zombie::Zombie(){name = "random";}
Zombie::~Zombie()
{
	std::cout << "destroyed " << name << std::endl;
	//should I add the destroy function here?
}

Zombie::Zombie(const std::string name) : name(name){}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}