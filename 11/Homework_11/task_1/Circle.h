#pragma once
#include "Point.h"

class Circle : public Point
{
private:
	const double PI = 3.141;
	double radius;
public:
	Circle() :Circle(0) {};
	Circle(double radius) :radius(radius) {};

	void Print()const
	{
		cout << " --- ";
		PrintShapeName();
		cout << " --- \n";
		cout << "Area: " << Area() << endl;
		cout << "Volume: " << Volume() << endl;
	}

	void PrintShapeName()const
	{
		cout << typeid(*this).name();
	}

	double Area()const
	{
		return (PI * radius * radius);
	}

	double Volume()const
	{
		return 0;
	}

	virtual ~Circle() {};
};