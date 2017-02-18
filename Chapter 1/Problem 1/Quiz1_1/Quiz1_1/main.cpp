#include "stdafx.h"
#include <iostream>

using namespace std;


int readNumber() {
	int i;
	cin >> i;
	return i;
}

void writeNumber(int i) {
	cout << i << "\n";
}

int main()
{
	int num1 = readNumber();
	int num2 = readNumber();
	writeNumber(num1 + num2);
}
