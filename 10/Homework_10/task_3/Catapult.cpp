#include "Catapult.h"

Catapult::Catapult(string name, int digits) :Shooter(name, digits) {};

void Catapult::quot()
{
	if (live > 0)
	{
	Shooter:quot();
		cout << " - Fired a catapult - \n";
	}
	else 
	{
		cout << "\nHe can't shoot becose dead!!!\n\n";
	}
}

int Catapult::GetLive() const
{
	return this->live;
}

void Catapult::Wound(int number)
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