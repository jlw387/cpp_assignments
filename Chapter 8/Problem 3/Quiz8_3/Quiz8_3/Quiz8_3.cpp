// Quiz8_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Monster {

public:
	enum MonsterType {
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES,
	};

private:
	MonsterType monsterType;
	string monsterName;
	string monsterRoar;
	int healthPoints;

	string getTypeString(MonsterType t) {
		switch (t) {
			case (MonsterType::DRAGON): return "Dragon";
			case (MonsterType::GOBLIN): return "Goblin";
			case (MonsterType::OGRE): return "Ogre";
			case (MonsterType::ORC): return "Orc";
			case (MonsterType::SKELETON): return "Skeleton";
			case (MonsterType::TROLL): return "Troll";
			case (MonsterType::VAMPIRE): return "Vampire";
			case (MonsterType::ZOMBIE): return "Zombie";
			default: return "Monster type not known";
		}
	}

public:
	Monster(MonsterType type, string name, string roar, int hp) {
		monsterType = type;
		monsterName = name;
		monsterRoar = roar;
		healthPoints = hp;
	}

	void print() {
		cout << monsterName << " the " << getTypeString(monsterType) << " has " <<
			healthPoints << " hit points and says " << monsterRoar << "!\n";
	}

};

class MonsterGenerator {
private:
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																					 // evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

public:
	static Monster generateMonster() {
		
		//3i) These two arrays are static so that they are only initialized once

		static string names[]{ "Tickles", "Gary", "Mr. Mister", "Aunt Clara", "Jebediah", "Barry" };
		static string roars[]{ "Yo", "Wiggle", "Hey, Wassup", "Uh oh", "Give up now", "Can I go home yet" };

		Monster::MonsterType type = static_cast<Monster::MonsterType> (getRandomNumber(0, Monster::MAX_MONSTER_TYPES-1));
		string monsterName = names[getRandomNumber(0, 5)];
		string monsterRoar = roars[getRandomNumber(0, 5)];
		int hitPoints = getRandomNumber(0,100);

		return Monster(type, monsterName, monsterRoar, hitPoints);
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	for (int i = 0; i < 10; i++) {
		Monster m = MonsterGenerator::generateMonster();
		m.print();
	}
	return 0;
}

