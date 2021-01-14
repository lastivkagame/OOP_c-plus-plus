#pragma once
#include "Programmer.h"
#include "Singer.h"

class SingerProggramer: public Programmer, public Singer
{
public:
	SingerProggramer(string name, int age, string sex, string voice) : Programmer(name, age, sex), Singer(name, age, voice), Person(name, age, sex)
	{
		cout << "SingerProggramer(string name, int age, string sex, string voice) : Programmer(name, age, sex), Singer(name, age, voice)\n";
	}
};

