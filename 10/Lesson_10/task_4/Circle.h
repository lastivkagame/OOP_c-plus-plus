#pragma once
class Circle
{
protected:
	const double PI = 3.14159;
	double radius;
public:
	Circle(double radius = 0) :radius(radius) {};

	double Area()const
	{
		return (radius * radius * PI);
	}

	double CircleLength()const
	{
		return (2 * radius*PI);
	}

	double GetRadius()const 
	{
		return radius;
	}

};

