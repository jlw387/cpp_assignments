
#include "stdafx.h"
#include <iostream>
#include "io.h"

using namespace std;

int main()
{
	int num1 = readNumber();
	int num2 = readNumber();
	writeNumber(num1 + num2);
}

