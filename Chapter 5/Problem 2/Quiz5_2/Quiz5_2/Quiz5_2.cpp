// Quiz5_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int generateRandomNumber(int minValue, int maxValue) {
	return rand()%(maxValue - minValue + 1) + minValue;
}

int main()
{
	srand(time(0));
	bool playedOnce = false;
	while (true) {

		while (true) {
			if(!playedOnce)
				cout << "Do you want to play a guessing game ('y'/'n')?\n>";
			else
				cout << "Do you want to play again ('y'/'n')?\n>";
			char choice;
			cin >> choice;
			if (choice != 'y' && choice != 'n') {
				cout << "Please enter either 'y' or 'n'.\n";
				cin.ignore(32767, '\n');
			}
			else if (choice == 'n') {
				cout << "Okay then, goodbye!\n";
				return 0;
			}
			else {
				cout << "Yay! I'm thinking of a number between 1 and 100. You have 7 tries to guess it!\n";
				playedOnce = true;
				break;
			}
		}

		int goalNumber = generateRandomNumber(1, 100);
		int tries;
		for (tries = 7; tries > 0; tries--) {
			int guess = 0;

			while (true) {
				cout << "Guess #" << 8 - tries << ": ";
				cin >> guess;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Uhhhhh...... you might wanna give that another go.\n";
				}
				else {
					cin.ignore(32767, '\n');
					break;
				}
			}

			if (guess > goalNumber) {
				cout << "Your guess was higher than the number.\n";
			}
			else if (guess < goalNumber) {
				cout << "Your guess was lower than the number.\n";
			}
			else {
				cout << "You got it! You win!\n";
				break;
			}
		}
		if (tries == 0) {
			cout << "I'm sorry; you're out of guesses. :( The number was: " << goalNumber << endl;
		}
	}
}

