#include "Int.h"

Int::Int(const Int& obj)
{
	this->SetNumber(obj.GetNumber());
}

int Int::GetNumber()const
{
	return number;
}

void Int::SetNumber(int number)
{
	this->number = number;
}

void Int::print()const
{
	cout << number << endl;
}

Int Int::Sum(const Int& a)
{
	Int temp;
	temp.SetNumber(this->number + a.GetNumber());
	return temp;
}

Int Int::Sub(const Int& a)
{
	Int temp;
	temp.SetNumber(this->number - a.GetNumber());
	return temp;
}

Int Int::Mnz(const Int& a)
{
	Int temp;
	temp.SetNumber(this->number * a.GetNumber());
	return temp;
}

Int Int::Del(const Int& a)
{
	Int temp;
	if (a.GetNumber() != 0)
	{
		temp.SetNumber(this->number / a.GetNumber());
		return temp;
	}
	else
	{
		cout << "Inccorect! You can't divide by zero!\n";
		return -1;
	}
}