#pragma once
class Square
{
protected:
	double side;
public:
	Square(double side = 0) :side(side) {};
	double Area() const
	{
		return (side*side);
	}

	double Perumentr()const
	{
		return (4 * side);
	}

	double GetSide()const 
	{
		return side;
	}
};

