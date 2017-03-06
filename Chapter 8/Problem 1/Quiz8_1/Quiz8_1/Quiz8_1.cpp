// Quiz8_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Point2d {
	double m_x;
	double m_y;

public:
	Point2d() {
		m_x = 0;
		m_y = 0;
	}

	Point2d(double param_x, double param_y) {
		m_x = param_x;
		m_y = param_y;
	}

	void print() {
		cout << "Point2d(" << m_x << ", " << m_y << ");\n";
	}

	double distanceTo(const Point2d otherPoint) {
		return sqrt((m_x - otherPoint.m_x)*(m_x - otherPoint.m_x) + (m_y - otherPoint.m_y)*(m_y - otherPoint.m_y));
	}
};

int main()
{
	Point2d first;
	Point2d second(3.0, 4.0);
	first.print();
	second.print();
	std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
	return 0;
}
