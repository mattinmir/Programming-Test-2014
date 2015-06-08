#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include <iostream>

class Creature
{
public:
	Creature(std::string itype, std::string iname, int ihealth, int istrength);

	virtual ~Creature() {}

	virtual void attack(Creature* opponent) const = 0; 

	virtual void is_attacked(int strength) = 0;

	bool is_alive() const;

	std::string stats() const;

	friend std::ostream& operator<<(std::ostream& out, Creature* c);

protected:
	std::string type;
	std::string name;
	int health;
	int strength;
	bool alive;
};

#endif // !CREATURE_HPP
