#pragma once
#include <iostream>
class Point
{
	int x;
	int y;
	char name;
public:
	Point():Point(0,0,'0'){}
	Point(int x, int y, char name) : x(x), y(y), name(name)
	{
		std::cout << "ctor Point(int x, int y, char name)\n";
	}
	Point(char name) : Point(0, 0, name)
	{
		std::cout << "Ctor Point(char name) \n";
	}
	~Point();
};

