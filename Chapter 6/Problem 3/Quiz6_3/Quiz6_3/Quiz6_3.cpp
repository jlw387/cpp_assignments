// Quiz6_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void swapInts(int& gary, int& yrag);

int main()
{
	cout << "Enter Variable 1:\n>";
	int x;
	cin >> x;
	cout << "Enter Variable 2:\n>";
	int y;
	cin >> y;

	swapInts(x, y);

	cout << "Variable 1: " << x << "\nVariable 2: " << y << endl;
}

void swapInts(int& num1_p, int& num2_p) {
	int temp = num1_p;
	num1_p = num2_p;
	num2_p = temp;
}