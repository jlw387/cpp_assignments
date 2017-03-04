// Quiz6_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Student {
	string name;
	int grade;
};

int getNumberInput(string prompt);
string getStringInput(string prompt);
void sortArray(Student students[], int length);

int main()
{
	int numStudents = getNumberInput("How many students would you like to add? ");
	Student* students = new Student[numStudents];
	for (int i = 0; i < numStudents; i++) {
		students[i].name = getStringInput("Please enter the name of Student " + to_string(i+1) + ": ");
		students[i].grade = getNumberInput("Please enter the grade of Student " + to_string(i+1) + ": ");
	}

	sortArray(students, numStudents);

	for (int i = 0; i < numStudents; i++) {
		cout << students[i].name << " got a grade of " << students[i].grade << ".\n";
	}

    return 0;
}

int getNumberInput(string prompt) {
	int input;
	while (true) {
		cout << prompt;
		cin >> input;
		if (cin.fail() || input < 0) {
			cin.clear();
			cin.ignore(255, '\n');
			cout << "Please try again!\n";
		}
		else {
			cin.ignore(255, '\n');
			break;
		}
	}
	return input;
}

string getStringInput(string prompt) {
	cout << prompt;
	string input;
	getline(cin, input);
	return input;
}

void sortArray(Student students[], int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i+1; j < length; j++) {
			if (students[j].grade > students[i].grade) {
				Student temp = students[j];
				students[j] = students[i];
				students[i] = temp;
			}
		}
	}
}

