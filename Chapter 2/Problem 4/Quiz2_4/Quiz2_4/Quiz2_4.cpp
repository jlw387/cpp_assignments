
#include "stdafx.h"
#include <iostream>
#include "constants.h"

using namespace std;
using namespace myConstants;

float calculateHeight(int seconds, float intitialHeight);

int main()
{
	float height;
	cout << "Enter the height of the tower: ";
	cin >> height;
	for (int i = 0; i <= 5; i++) {
		cout << "After " << i << " seconds, the ball is ";
		if (calculateHeight(i, height) > 0)
			cout << "at " << calculateHeight(i, height) << " meters.\n";
		else
			cout << "on the ground.\n";
	}
    return 0;
}

float calculateHeight(int seconds, float initialHeight) {
	return initialHeight - (seconds * seconds * gravity / 2);
}

