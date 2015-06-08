#ifndef OGRE_HPP
#define OGRE_HPP

#include "Creature.hpp"
#include <string>

class Ogre : public Creature
{
public:

	Ogre(std::string iname, int ihealth, int istrength);

	void attack(Creature* opponent) const;

	void is_attacked(int opponent_strength);
};

#endif // !OGRE_HPP
