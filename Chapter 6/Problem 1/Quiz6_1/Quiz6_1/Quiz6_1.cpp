// Quiz6_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int countTotalItems(int i[], int length) {
	int k = 0;
	for (int j = 0; j < length; j++) {
		k += i[j];
	}
	return k;
}

enum ItemTypes{
	HEALTH_POTIONS,
	TORCHES,
	ARROWS,
};

int main()
{
	int items[3];
	
	items[HEALTH_POTIONS] = 2;
	items[TORCHES] = 5;
	items[ARROWS] = 10;

	cout << countTotalItems(items, sizeof(items)/sizeof(items[0])) << endl;

    return 0;
}

