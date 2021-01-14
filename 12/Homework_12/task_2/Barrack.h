#pragma once
#include <iostream>
using namespace std;

class Unit
{
private:
	int hp;
	int dmg;
	int dodge;
public:
	Unit(int hp, int dmg, int dodge) :hp(hp), dmg(dmg), dodge(dodge) {};

	virtual void Print() = 0;
	virtual void Play(Unit*& enemy) = 0;
	virtual ~Unit() {};

	virtual int Gethp()const
	{
		return this->hp;
	}

	virtual int Getdmg()const
	{
		return this->dmg;
	}

	virtual int Getdodge()const
	{
		return this->dodge;
	}

	virtual void Sethp(int el)
	{
		this->hp -= el;
	}
};

class Marine : public Unit
{
public:
	Marine() :Unit(10, 5, 60) {};

	void Play(Unit*& enemy) override
	{
		cout << " - Play a Marine - \n";

		int temp = rand() % 100;

		if (enemy->Getdodge() < temp)
		{
			enemy->Sethp(this->Getdmg());
			cout << " I hit to enemy\n";

			if (enemy->Gethp() < 0)
			{
				cout << " Enemy is dead!\n";
			}
		}
		else
		{
			cout << " It is missed out!\n";
		}
	}

	void Print()
	{
		if (this->Gethp() > 0)
		{
			cout << "  - Marine - \n";
			cout << " hp: " << Gethp() << endl;
			cout << " dmg: " << Getdmg() << endl;
			cout << " dodge: " << Getdodge() << endl;
			cout << endl;
		}
	}
};

class CrazyScientist : public Unit
{
public:
	CrazyScientist() :Unit(8, 15, 30) {};

	void Play(Unit*& enemy)override
	{
		cout << " - Play a CrazyScientist - \n";

		int temp = rand() % 100;

		if (enemy->Getdodge() < temp)
		{
			enemy->Sethp(this->Getdmg());
			cout << " I hit to enemy\n";

			if (enemy->Gethp() < 0)
			{
				cout << " Enemy is dead!\n";
			}
		}
		else
		{
			cout << " It is missed out!\n";
		}
	}

	void Print()
	{
		if (this->Gethp() > 0)
		{
			cout << "  - Crazy Scientist - \n";
			cout << " hp: " << Gethp() << endl;
			cout << " dmg: " << Getdmg() << endl;
			cout << " dodge: " << Getdodge() << endl;
			cout << endl;
		}
	}
};

class MilitaryDoctor : public Unit
{
public:
	MilitaryDoctor() : Unit(15, 8, 40) {};

	void Play(Unit*& enemy) override
	{
		cout << " - Play a MilitaryDoctor - \n";

		int temp = rand() % 100;

		if (enemy->Getdodge() < temp)
		{
			enemy->Sethp(this->Getdmg());
			cout << " I hit to enemy\n";

			if (enemy->Gethp() < 0)
			{
				cout << " Enemy is dead!\n";
			}
		}
		else
		{
			cout << " It is missed out!\n";
		}
	}

	void Print()
	{
		if (this->Gethp() > 0)
		{
			cout << "  - Military Doctor - \n";
			cout << " hp: " << Gethp() << endl;
			cout << " dmg: " << Getdmg() << endl;
			cout << " dodge: " << Getdodge() << endl;

			cout << endl;
		}
	}
};

class Barrack
{
public:
	virtual Unit* CreatePlayer() = 0;
};

class WarBarrack : public Barrack
{
public:
	Unit* CreatePlayer()
	{
		return new Marine();
	}
};

class ScienceBarrack : public Barrack
{
public:
	Unit* CreatePlayer()
	{
		return new CrazyScientist();
	}
};

class MedicalBarrack : public Barrack
{
public:
	Unit* CreatePlayer()
	{
		return new MilitaryDoctor();
	}
};