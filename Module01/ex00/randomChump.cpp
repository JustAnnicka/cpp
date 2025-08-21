#include "Zombie.hpp"

void randomChump( std::string name )
{
	//should this be a pointer call instead with newZombie?
	Zombie chump(name);
	chump.announce();
	//should call destructor?
}