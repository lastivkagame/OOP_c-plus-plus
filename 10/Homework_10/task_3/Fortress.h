#pragma once
#include "ArcherTower.h"
#include "Catapult.h"

class Fortress : public virtual ArcherTower, public virtual Catapult
{
private:
	int wall = 60;
	int gate = 10;
	int ditch = 10;
public:
	Fortress(string name, int digits);

	void Wound(int number, string who);
	void ConsistentWound(int number);
	void QuotCatapult();
	void Archertower(string who);
	bool IsFortrees(); //перев≥р€Ї чи не р≥вна фортец€ нулю тод≥ прграш ≥накше ще не зруйнованна

	void Print()const;
};

