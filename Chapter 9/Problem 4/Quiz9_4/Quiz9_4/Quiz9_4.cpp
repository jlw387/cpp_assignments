// Quiz9_4.cpp : Defines the entry point for the console application.
//
//4 a) To represent a floating-point number with two decimal places, two ints could be used. Since the
//     question wants the range between -32768.99 and 32767.99, the first int will need to be a 16-bit
//     integer or higher. The decimal component will need to be an 8-bit integer or higher.

#include "stdafx.h"
#include <iostream>
#include <string>

class FixedPoint2 {
private:
	int16_t intNum;
	int8_t decNum;
	bool isNegative;

public:
	FixedPoint2(int16_t integerNum, int8_t decimalNum) {
		intNum = integerNum;
		decNum = decimalNum;
		isNegative = false;
		if (intNum < 0) {
			isNegative = !isNegative;
			intNum *= -1;
		}
		if (decNum < 0) {
			isNegative = !isNegative;
			decNum *= -1;
		}
	}

	FixedPoint2(double d) {
		intNum = static_cast<int>(d);
		decNum = round((d - intNum) * 100);
		isNegative = false;
		if (intNum < 0 || decNum < 0) {
			isNegative = !isNegative;
			intNum *= -1;
			decNum *= -1;
		}
	}

	operator double(){
		double d = intNum + static_cast<double>(decNum) / 100;
		if (isNegative)
			d *= -1;
		return d;
	}

	FixedPoint2 operator-() {
		return FixedPoint2(-intNum, decNum);
	}

	friend FixedPoint2 operator + (FixedPoint2 f1, int num2);
	friend FixedPoint2 operator + (int num2, FixedPoint2 f2);
	friend FixedPoint2 operator + (FixedPoint2 f1, double num2);
	friend FixedPoint2 operator + (double num1, FixedPoint2 f2);
	friend FixedPoint2 operator + (FixedPoint2 f1, FixedPoint2 f2);
	friend std::ostream& operator << (std::ostream& out, FixedPoint2 f);
	friend std::istream& operator >> (std::istream& in, FixedPoint2& f);
};

void checkDecimalValue(int16_t& num1, int8_t& num2) {
	while (num2 > 100 || num2 < -100) {
		if (num2 > 0) {
			num2 -= 100;
			num1++;
		}
		else {
			num2 += 100;
			num1--;
		}
	}
}

void checkDecimalSign(int16_t& num1, int8_t& num2) {
	if ((num1 < 0) != (num2 < 0)) {
		if (num1 > 0)
			num1--;
		else
			num1++;

		if (num2 > 0)
			num2 -= 100;
		else
			num2 += 100;
	}
}

FixedPoint2 operator + (FixedPoint2 f1, int num2) {
	f1.intNum += num2;
	return f1;
}

FixedPoint2 operator + (int num1, FixedPoint2 f2) {
	f2.intNum += num1;
	return f2;
}

FixedPoint2 operator + (FixedPoint2 f1, double num2) {
	f1.intNum += static_cast<int>(num2);
	f1.decNum += static_cast<int>(round(num2 - static_cast<int>(num2) * 100));
	checkDecimalValue(f1.intNum, f1.decNum);
	checkDecimalSign(f1.intNum, f1.decNum);

	if (f1.intNum < 0 || f1.decNum < 0) {
		f1.isNegative = !f1.isNegative;
		f1.intNum *= -1;
		f1.decNum *= -1;
	}

	return f1;
}

FixedPoint2 operator + (double num1, FixedPoint2 f2) {
	return operator+(f2, num1);
}

FixedPoint2 operator + (FixedPoint2 f1, FixedPoint2 f2) {
	if (f1.isNegative == f2.isNegative) {
		f1.intNum += f2.intNum;
		f1.decNum += f2.decNum;
		checkDecimalValue(f1.intNum, f1.decNum);
		checkDecimalSign(f1.intNum, f1.decNum);
	}
	else {
		if (f1.intNum > f2.intNum || (f1.intNum == f2.decNum && f1.decNum > f2.decNum)) {
			f1.intNum -= f2.intNum;
			f1.decNum -= f2.decNum;
			
		}
		else {
			f1.intNum -= f2.intNum;
			f1.decNum -= f2.decNum;
			f1.intNum *= -1;
			f1.decNum *= -1;
			f1.isNegative = f2.isNegative;
			checkDecimalValue(f1.intNum, f1.decNum);
			checkDecimalSign(f1.intNum, f1.decNum);
		}
	}

	return f1;
}

std::ostream& operator << (std::ostream& out, FixedPoint2 f) {
	if (f.isNegative)
		out << '-';
	out << f.intNum << '.';
	if (f.decNum / 10 < 1)
		out << '0';
	out << static_cast<int>(f.decNum);
	return out;
}

std::istream& operator >> (std::istream& in, FixedPoint2& f) {
	double d;
	in >> d;
	f = FixedPoint2(d);
	return in;
}

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	FixedPoint2 g(34, 56);
	std::cout << g << '\n';

	FixedPoint2 b(0, -8);
	std::cout << b << '\n';

	std::cout << static_cast<double>(b) << std::endl;

	FixedPoint2 c(0.01);
	std::cout << c << '\n';

	FixedPoint2 d(-0.01);
	std::cout << d << '\n';

	FixedPoint2 e(5.01); // stored as 5.0099999... so we'll need to round this
	std::cout << e << '\n';

	FixedPoint2 f(-5.01); // stored as -5.0099999... so we'll need to round this
	std::cout << f << '\n';

	testAddition();

	FixedPoint2 a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}

