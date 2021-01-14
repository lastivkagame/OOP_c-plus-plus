#pragma once
#include "Circle.h"
#include "Square.h"
#include <iostream>
using namespace std;

class CircleInSquare: public Square, public Circle
{
public:
	CircleInSquare(double side, double radius) : Square(side), Circle(radius) 
	{
		if (side < radius) 
		{
			cout << "I cant create circle in square\n";

			this->side = 4;
			this->radius = 1;
		}
	};

	double totalLength() const
	{
		return (CircleLength() + Perumentr());
	}

	double AreaPartFigure() const
	{
		return (Square::Area() - Circle::Area());
	}

	void SetRadius(double radius)
	{
		this->radius = radius;
		side = ((totalLength() - 2 * radius * PI) / 4);
	}

	void SetSide(double side)
	{
		this->side = side;
		radius = ((totalLength() - 4 * side) / (2 * PI));
	}
};

