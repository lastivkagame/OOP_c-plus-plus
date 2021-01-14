#pragma once
#include "Shape.h"

class Point : public Shape
{
public:
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
		return 0;
	}

	virtual double Volume()const
	{
		return 0;
	}

	virtual ~Point() {};
};