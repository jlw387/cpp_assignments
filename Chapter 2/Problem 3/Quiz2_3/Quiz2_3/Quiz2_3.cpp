#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double num1, num2;
	char operation;
	cout << "Enter a number: ";
	cin >> num1;
	cout << "Enter another number: ";
	cin >> num2;
	cout << "Enter an operator ('+', '-', '*', or '/'): ";
	cin >> operation;
	cout << "\nAnswer: " << num1 << " " << operation << " " << num2 << " = ";
	switch (operation) {
		case '+':
			cout << (num1 + num2);
			break;
		case '-':
			cout << (num1 - num2);
			break;
		case '*':
			cout << (num1 * num2);
			break;
		case '/':
			cout << (num1 / num2);
			break;
	}
	cout << "\n\n";
    return 0;
}

