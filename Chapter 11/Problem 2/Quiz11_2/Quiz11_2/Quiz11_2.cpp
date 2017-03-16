// Quiz11_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Fruit {
private:
	string name;
	string color;

public:
	Fruit(string na) {
		name = na;
		color = "";
	}

	Fruit(string na, string co) {
		name = na;
		color = co;
	}

	string getName() {
		return name;
	}

	string getColor() {
		return color;
	}
};

class Banana : public Fruit {
public:
	Banana() : Fruit("banana", "yellow") {

	}

	Banana(string co) : Fruit("banana", co) {

	}
};

class Apple : public Fruit {
public:
	Apple() : Fruit("apple") {

	}

	Apple(string co) : Fruit("apple", co) {
		
	}

	Apple(string appleName, string co) : Fruit(appleName + " apple", co) {

	}
};

class GrannySmith : public Apple {
public:
	GrannySmith() : Apple("granny smith", "green"){

	}
};

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}

