// Quiz6_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

void printCString(char* c_pointer) {
	while (*c_pointer != '\0') {
		std::cout << *c_pointer;
		c_pointer++;
	}
	std::cout << std::endl;
}

int main()
{
	printCString("Hello World!");
    return 0;
}

