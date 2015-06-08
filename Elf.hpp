#ifndef ELF_HPP
#define ELF_HPP

#include "Creature.hpp"


class Elf : public Creature
{
public:
	Elf(std::string iname, int ihealth, int istrength);

	void attack(Creature* opponent) const;

	void is_attacked(int opponent_strength);
};

#endif // !ELF_HPP
