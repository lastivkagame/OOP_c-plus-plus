#pragma once

#include <iostream>
using namespace std;

class Point
{
private:
	char *name;
	int x;
	int y;

public:
	//ststic -модифікатор
	static int count;
	Point();

	Point(int x, int y, const char*name);
	Point(const Point &obj);

	void SetX(int x);
	void SetY(int y);
	void SetName(const char * name);

	int GetX()const;
	int GetY()const;
	char * GetName()const;

	void Show()const;

	~Point();
};

