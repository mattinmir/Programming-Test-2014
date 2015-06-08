#include "Creature.hpp"
#include <string>
#include <sstream>
#include <iostream>

Creature::Creature(std::string itype, std::string iname, int ihealth, int istrength) : type(itype), name(iname), health(ihealth), strength(istrength), alive(true) {}

bool Creature::is_alive() const
{
	return alive;
}

std::string Creature::stats() const
{
	std::stringstream ss;

	ss << type << " " << name << " Health: " << health << " Strength: " << strength;
	return ss.str();
}

std::ostream& operator<<(std::ostream& out, Creature* c)
{
	out << c->stats();
	return out;
}