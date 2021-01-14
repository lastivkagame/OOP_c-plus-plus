#pragma once
#include "Shooter.h"

class Archer : public virtual Shooter
{
private:
	int live = 5;
public: 
	Archer(string name, int digits);
	void quot();
	int GetLive()const;
	void Wound(int number);
};

