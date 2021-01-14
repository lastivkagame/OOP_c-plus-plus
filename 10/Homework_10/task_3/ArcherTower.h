#pragma once
#include "Archer.h"
#include "Catapult.h"
#include "Range.h"
#include <string>

class ArcherTower :public virtual Archer, public virtual Range
{
private:
	int live = Archer::GetLive() + Range::GetLive();
public:
	ArcherTower(string name, int digits);
	int GetLive()const;
	void Wound(int number, string who);
};