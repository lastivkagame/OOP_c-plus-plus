#include "ArcherTower.h"

ArcherTower::ArcherTower(string name, int digits) :Archer(name, digits), Range(name, digits) {};

int ArcherTower::GetLive() const
{
	return this->live;
}

void ArcherTower::Wound(int number, string who)
{
	if (who == "archer")  //якщо лучник
	{
		Archer::Wound(number);
		live -= number;

		if (live < 0)
		{
			live = 0;
		}
	}
	else  // якщо лучник
	{
		Range::Wound(number);
		live -= number;

		if (live < 0)
		{
			live = 0;
		}
	}
}