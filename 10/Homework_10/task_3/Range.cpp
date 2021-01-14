#include "Range.h"

Range::Range(string name, int digits) :Shooter(name, digits) {};

void Range::quot()
{
	if (live > 0)
	{
	Shooter::quot();
		cout << " - Fired a range - \n";
	}
	else 
	{
		cout << "\nHe can't shoot becose dead!!!\n\n";
	}
}

int Range::GetLive() const
{
	return this->live;
}

void Range::Wound(int number)
{
	if (number >= live) 
	{
		cout << "Dead!";
		live = 0;
	}
	else
	{
		live -= number;
	}
}
