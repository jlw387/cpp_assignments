// Quiz8_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class HelloWorld
{
private:
	char *m_data;

public:
	HelloWorld()
	{
		// C++14 version
		//		m_data = new char[14]{ "Hello, World!" };

		// C++11 version
		//              m_data = new char[14]{ ‘H’, ‘e’, ‘l’, ‘l’, ‘o’, ',', ‘ ‘, ‘W’, ‘o’, ‘r’, ‘l’, ‘d’, ‘!’, ‘\0’ };

		// older than C++11 version
		m_data = new char[14];
		const char *init = "Hello, World!";
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld()
	{
		delete[] m_data;
	}

	void print()
	{
		std::cout << m_data;
	}

};

int main()
{
	HelloWorld hello;
	hello.print();

	return 0;
}

