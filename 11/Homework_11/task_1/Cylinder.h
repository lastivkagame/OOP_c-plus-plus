#pragma once
#include "Shape.h"

class Cylinder :public Shape
{
private:
	const double PI = 3.141;
	double radius;
	double height;
public:
	Cylinder() :Cylinder(0, 0) {};
	Cylinder(double radius, double height) :radius(radius), height(height) {};

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

	double Volume() const
	{
		return (PI * radius * radius * height);
	}
};