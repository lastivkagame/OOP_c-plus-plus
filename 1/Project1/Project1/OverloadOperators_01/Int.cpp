#include "Int.h"
#include <iostream>
Int::Int() :test(10), number(0)
{
	count++;
}

Int::Int(int number) : number(number), test(0)  //спискова ініціалізація
{
	count++;
}

Int::Int(const Int & obj) : test(0)
{

	//*this = obj;

	this->number = obj.number;
	count++;
}


Int::~Int()
{
	//	this->count--;
}

int Int::GetNumber() const
{
	return this->number;
}

void Int::SetNumber(int number)
{
	this->number = number;
}

void Int::print() const
{
	std::cout << " Number = " << number << std::endl;
}

int Int::GetCount()
{
	return count;
}

Int Int::Sum(const Int & a)
{
	Int temp;
	temp.SetNumber(this->number + a.GetNumber());
	return temp;
}

Int Int::Sub(const Int & a)
{
	Int temp;
	temp.SetNumber(this->number - a.GetNumber());
	return temp;
}

Int & Int::SumEqual(const Int & obj)
{
	this->number += obj.GetNumber();
	return *this;
}


