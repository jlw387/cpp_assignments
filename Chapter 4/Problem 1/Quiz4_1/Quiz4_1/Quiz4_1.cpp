// Quiz4_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

enum class MonsterType
{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME,
};

struct Monster
{
	MonsterType type;
	string name;
	int healthPoints;
};

string getType(MonsterType m) {
	switch (m) {
		case MonsterType::OGRE:
			return "Ogre";
			break;
		case MonsterType::DRAGON:
			return "Dragon";
			break;
		case MonsterType::ORC:
			return "Orc";
			break;
		case MonsterType::GIANT_SPIDER:
			return "Giant Spider";
			break;
		case MonsterType::SLIME:
			return "Slime";
			break;
	}
	return "";
}

void printMonster(Monster m) {
	cout << "This " << getType(m.type) << " is named " << m.name << " and has " << m.healthPoints << " health.\n";
}

int main()
{
	Monster m1{MonsterType::OGRE,"Torg",145};
	Monster m2{ MonsterType::SLIME,"Blurp",23 };
	printMonster(m1);
	printMonster(m2);
    return 0;
}

