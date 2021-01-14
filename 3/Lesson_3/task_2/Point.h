#pragma once
#include <iostream>
using namespace std;


class Point
{
	int x;
	int y;
	char name;
public:
	Point() :Point(0, 0, '0') {}
	Point(int x, int y, char name) : x(x), y(y), name(name)
	{
		cout << "Point(int x, int y, char name) : x(x), y(y), name(name)\n";
	}
	Point(char name) : Point(0, 0, name){}
};

