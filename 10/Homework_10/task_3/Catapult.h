#pragma once
#include "Shooter.h"

class Catapult :public virtual Shooter
{
private:
	int live = 10;
public:
	Catapult(string name, int digits);
	void quot();
	int GetLive()const;
	void Wound(int number);
};