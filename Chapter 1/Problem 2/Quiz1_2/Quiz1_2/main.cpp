
#include "stdafx.h"
#include <iostream>

int readNumber();
void writeNumber(int i);

int main()
{
	int num1 = readNumber();
	int num2 = readNumber();
	writeNumber(num1 + num2);
	return 0;
}

