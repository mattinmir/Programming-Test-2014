#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Creature.hpp"
#include "Elf.hpp"
#include "Ogre.hpp"
#include <vector>


using namespace std;

int main(int argc, char* argv[])
{
	vector<Creature*> creatures;
	string name;
	string type;
	int health;
	int strength;

	ifstream infile;
	infile.open(argv[1]); // argv[1] will be a .txt file 
	if (!infile.is_open())
	{
		cout << "Could not open file" << endl;
		exit(EXIT_FAILURE);
	}

	while (infile >> type >> name >> health >> strength)
	{
		if (type == "elf")
			creatures.push_back(new Elf(name, health, strength));
		else if (type == "ogre")
			creatures.push_back(new Ogre(name, health, strength));
	}

	infile.close();
	bool finished = false;
	while (!finished)
	{
		cout << "Creatures Available: " << endl;

		vector<Creature*>::iterator it;
		for (it = creatures.begin(); it != creatures.end(); ++it)
		{
			if ((*it)->is_alive())
				cout << it - creatures.begin() << ": " << *it << endl; 
		}

		int attacker;
		int target;
		cout << endl << "Enter index of attacking and target creatures: " << endl;
		cin >> attacker >> target;

		if (attacker < 0 || target < 0) // End game
			finished = true;
		else
		{
			cout << endl << creatures[attacker] << endl << "attacks" << endl << creatures[target] << endl;
			creatures[attacker]->attack(creatures[target]);

			cout << endl << "After the attack:" << endl;
			cout << creatures[target] << endl << endl << endl;
		}
	}
	return 0;
}