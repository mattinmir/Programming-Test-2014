#include "Creature.hpp"
#include "Elf.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

Elf::Elf(std::string iname, int ihealth, int istrength) : Creature("elf", iname, ihealth, istrength){}

void Elf::attack(Creature* opponent) const
{
	srand(time(NULL));
	for (unsigned int i = 0; i < 4; i++)
	{
		if (rand() % 3 == 0) // 1 in 3 chance of attacking
			opponent->is_attacked(strength / 3);
	}
}
void Elf::is_attacked(int opponent_strength)
{
	srand(time(NULL));
	for (unsigned int i = 0; i < 4; i++)
	{
		if (rand() % 3 != 0) // 2 in 3 chance of getting damaged
			health -= opponent_strength;
	}

	if (health <= 0)
		alive = false;
}