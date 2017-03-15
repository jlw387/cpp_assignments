// Quiz9_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <cassert>

class IntArray {
private:
	int* numArray;
	int length;
public:
	IntArray(int arrayLength) {
		numArray = new int[arrayLength];
		length = arrayLength;
	}

	int& operator[](int num) {
		assert(num >= 0 && num < length);
		return numArray[num];
	}

	friend std::ostream& operator<< (std::ostream& out, IntArray& a);

	~IntArray() {
		delete[] numArray;
	}
};

std::ostream& operator<< (std::ostream& out, IntArray& a) {
	out << "[";
	for (int i = 0; i < a.length; i++)
		out << a[i] << " ";
	out << "]";
	return out;
}

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}
