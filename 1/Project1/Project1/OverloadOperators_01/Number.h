#pragma once
#include <iostream>
#include "Int.h"
using namespace std;
class Number
{
	int number;
public:
	Number() : number(0) {}
explicit	Number(int n) : number(n) {}
	~Number();
	int GetNumber() const {
		return number;
	}
	Number operator+ (const Number& right) {
		Number res(this->number + right.GetNumber());
		return res;
	}
	Number operator+ (int right)
	{
		return Number(number + right);
	}
	Number operator- (const Number& right)
	{
		Number res(this->number - right.GetNumber());
		return res;
	}

	bool operator > (const Number & right)
	{
		return this->number > right.GetNumber();
	}
	bool operator < (const Number & right)
	{
		return this->number < right.GetNumber();
	}

	void Print() const
	{
		cout << number << endl;
	}
 /*explicit*/ operator int()
	{
		return number;
	}
	operator char()
	{
		return (char)number;
	}
	operator Int()
	{
		Int res(number);
		return res;
	}

};

