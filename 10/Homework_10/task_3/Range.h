#pragma once
#include "Shooter.h"

class Range :public virtual Shooter
{
private:
	int live = 5;
public:
	Range(string name, int digits);
	void quot();
	int GetLive()const;
	void Wound(int number);
};

