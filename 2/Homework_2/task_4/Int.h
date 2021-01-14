#pragma once
#include<iostream>
using namespace std;

class Int
{
private:
	int number;
public:
	Int() :number(0) {}
	Int(int number) : number(number) {}
	Int(const Int& obj);

	int GetNumber()const;
	void SetNumber(int number);

	void print()const;

	Int Sum(const Int& a);

	Int Sub(const Int& a);

	Int Mnz(const Int& a);

	Int Del(const Int& a);
};