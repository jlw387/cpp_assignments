// Quiz11_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

int getRandomNumber(int min, int max);

class Creature {
private:
	string name;
	char symbol;
	int health;
	int gold;

protected:
	int attack;

public:
	Creature(string n, char s, int h, int a, int g) {
		name = n;
		symbol = s;
		health = h;
		attack = a;
		gold = g;
	}

	string getName() { return name; }
	char getSymbol() { return symbol; }
	int getHealth() { return health; }
	int getAttackDamage() { return attack; }
	int getGold() { return gold; }
	void reduceHealth(int i) { health -= i; }
	bool isDead() { return health <= 0; }
	void addGold(int i) { gold += i; }

};

class Player : public Creature {
private:
	int level;
public:
	Player(string name) : Creature(name, '@', 10, 1, 0){
		level = 1;
	}

	void levelUp() { level++; attack++; }
	int getLevel() { return level; }
	bool hasWon() { return level >= 20; }
	void buyPotion() { addGold(-50); while (getHealth() < 10) reduceHealth(-1); }
};

class Monster : public Creature {
public:
	enum MonsterType {
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES,
	};

	struct MonsterData {
		string m_name;
		char m_symbol;
		int m_health;
		int m_attack;
		int m_gold;
	};

	static Monster getRandomMonster() {
		int i = getRandomNumber(1,10);
		if(i < 6)
			return Monster(MonsterType::SLIME);
		else if (i < 10) 
			return Monster(MonsterType::ORC);
		else 
			return Monster(MonsterType::DRAGON);
	}

	static MonsterData monsterData[MAX_TYPES];

	Monster(MonsterType type) : Creature(monsterData[type].m_name, monsterData[type].m_symbol, monsterData[type].m_health, monsterData[type].m_attack, monsterData[type].m_gold) {}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

int getRandomNumber(int min, int max) {
	rand();
	return (rand() % (max - min + 1) + min);
}

void attackPlayer(Player& p, Monster& m) {
	cout << "You attacked with " << p.getAttackDamage() << " damage!\n";
	m.reduceHealth(p.getAttackDamage());
	cout << "The " << m.getName() << " now has " << m.getHealth() << " health!\n";
}

void attackMonster(Player& p, Monster& m) {
	cout << "The monster attacked with " << m.getAttackDamage() << " damage!\n";
	p.reduceHealth(m.getAttackDamage());
	cout << "You now have " << p.getHealth() << " health!\n";
}

void fightMonster(Player& p) {
	Monster m = Monster::getRandomMonster();
	cout << p.getName() << ", you've encountered a " << m.getName() << "!\n";
	while (!p.isDead() && !m.isDead()) {
		cout << "What would you like to do, run or fight?\n>";
		char input;
		cin >> input;
		cin.ignore(255, '\n');
		if (input == 'r' || input == 'R'){
			if (rand() % 2 == 0) {
				cout << "You escaped!\n";
				return;
			}
			else {
				cout << "You failed to escape!\n";
			}
		}
		else {
			attackPlayer(p,m);
		}

		if (!m.isDead()) {
			attackMonster(p,m);
		}
	}
	if (m.isDead()) {
		cout << "You beat the " << m.getName() << " and got " << m.getGold() << " gold!\n";
		p.addGold(m.getGold());
		cout << "You now have " << p.getGold() << " gold!\n";
		p.levelUp();
		cout << "You leveled up! You're now at level " << p.getLevel() << "!\n";
		Sleep(500);
	}
	else {
		cout << "You died! You lost with " << p.getGold() << " gold!\n";
		Sleep(500);
		return;
	}
}

int main()
{
	cout << "Enter your name: ";
	string name;
	getline(cin, name);
	Player p = Player(name);
	cout << "Welcome to the game, " << p.getName() << ". Good luck.\n";
	Sleep(1000);

	srand(time(0));
	rand();

	bool hasRejectedPotion = false;
	while (!p.isDead() && !p.hasWon()) {
		fightMonster(p);
		cout << "\n\n================================\n\n";
		if (p.getGold() >= 50 && p.getLevel() < 20 && !p.isDead()) {
			cout << "Would you like to spend 50 gold on a potion to\nrestore your health to max (yes or no)?\n>";
			char c;
			cin >> c;
			cin.ignore(255,'\n');
			if (c == 'y' || c == 'Y') {
				p.buyPotion();
				cout << "You now have full health (" << p.getHealth() << " health)!\n";
			}
			else if(!hasRejectedPotion){
				cout << "Okay then.\n";
				Sleep(1000);
				cout << "Fine.\n";
				Sleep(1000);
				cout << "Whatever.\n";
				Sleep(1000);
				cout << "Don't take advantage of this extra mechanic I added to save your sorry butt.\n";
				Sleep(2000);
				cout << "It's fine.\n";
				Sleep(1000);
				hasRejectedPotion = true;
			}

			cout << "\n\n================================\n\n";
		}
	}

	if (!p.isDead()) {
		cout << "You won! You ended the game with " << p.getGold() << " gold!";
	}

	return 0;
}

