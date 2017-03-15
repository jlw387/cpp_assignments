// Quiz9_2.cpp : Defines the entry point for the console application.
//
// 2 b) No user-defined copy constructor or assignment operator is needed.

#include "stdafx.h"
#include <iostream>
#include <cstdint>

class Average {
private:
	int32_t sum;
	int8_t count;

public:
	Average() {
		sum = 0;
		count = 0;
	}

	friend void operator+(Average &a, const int i);
	friend void operator+(const int i, Average &a);
	friend std::ostream& operator<< (std::ostream &out, const Average &a);
	Average& operator+=(const int i) {
		sum += i;
		count++;
		return *this;
	}
};

std::ostream& operator<< (std::ostream &out, const Average &a) {
	out << ((static_cast<double>(a.sum) / a.count));
	return out;
}

void operator+(Average &a, const int i) {
	a.sum += i;
	a.count++;
}

void operator+(const int i, Average &a) {
	a.sum += i;
	a.count++;
}

int main()
{
	Average avg = Average();

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}

