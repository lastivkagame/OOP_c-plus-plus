#include "Archer.h"

Archer::Archer(string name, int digits) :Shooter(name, digits) {};

void Archer::quot()
{
	if (live > 0)
	{
		Shooter::quot();
		cout << " - Fired an archer - \n";
	}
	else 
	{
		cout << "\nHe can't shoot becose dead!!!\n\n";
	}
}

int Archer::GetLive() const
{
	return this->live;
}

void Archer::Wound(int number)
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