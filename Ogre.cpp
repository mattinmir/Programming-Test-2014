#include "Creature.hpp"
#include "Ogre.hpp"
#include <string>

Ogre::Ogre(std::string iname, int ihealth, int istrength): Creature("ogre", iname, ihealth, istrength){}

void Ogre::attack(Creature* opponent) const
{
	opponent->is_attacked(strength);
}

void Ogre::is_attacked(int opponent_strength)
{
	health -= opponent_strength;
	
	if (health <= 0)
		alive = false;
}