#pragma once
#include <iostream>
using namespace std;

class Shape
{
public:
	virtual void Print()const = 0;
	virtual void PrintShapeName()const = 0;
	virtual double Area()const = 0;
	virtual double Volume()const = 0;
	virtual ~Shape() {};
};