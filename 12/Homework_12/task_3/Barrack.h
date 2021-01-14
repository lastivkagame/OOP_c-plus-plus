#pragma once
#include <iostream>
#include <vector>
#include "Weapon.h"
using namespace std;

class Unit
{
private:
	int hp;
	int dmg;
	int dodge;
	vector<Weapon*>weapons;
	int num = 0;
public:
	Unit(int hp = 0, int dmg = 0, int dodge = 0) :hp(hp), dmg(dmg), dodge(dodge) {};

	virtual void Print() = 0;
	virtual void Play(Unit*& enemy) = 0;
	virtual ~Unit() {};

	void AddWeapon()
	{
		if (num <= 0)
		{
			num++;

			int choice;
			cout << " KNIFES = 1,\t GRENADES = 2,\t ELECTROSHOCK = 3\t exit = 0\n Answer: ";
			cin >> choice;

			if (choice == 1 || choice == 2 || choice == 3)
			{
				weapons.push_back(FactoryWeapons::CreateWeapon((WEAPONTYPE)choice));
			}
			else if (choice == 0)
			{
				cout << " This hero have only skill\n";
			}
			else
			{
				cout << " Inccorect direction!\n";
			}

		}
		else
		{
			cout << " You already have weapon\n";
		}
	}

	void AddRandWeapont()
	{
		if (num <= 0)
		{
			num++;

			int choice = rand() % 4;

			if (choice == 1 || choice == 2 || choice == 3)
			{
				weapons.push_back(FactoryWeapons::CreateWeapon((WEAPONTYPE)choice));
			}
		}
	}

	bool IsHeroWeapon() const
	{
		if (num > 0)
		{
			return true;
		}
		return false;
	}

	bool IsHeroDie() const
	{
		if (hp < 0)
		{
			return true;
		}
		return false;
	}

	void UseWeapon(Unit*& unit)
	{
		if (num > 0)
		{
			num--;

			int temp = rand() % 100;

			if (unit->Getdodge() < temp)
			{
				unit->Sethp(weapons[0]->Shot());
				cout << " it succses hit!\n";
			}
			else
			{
				cout << " Its missed\n";
			}
		}
	}

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

	virtual int GetNum()const
	{
		return this->num;
	}

	virtual void Sethp(int el)
	{
		this->hp -= el;
	}

	virtual Weapon* GetWeapon()const
	{
		return this->weapons[0];
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
				cout << " Hero is dead!\n";
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

			if (GetNum() > 0)
			{
				cout << " I have weapon. \n";
			}

			cout << endl;
		}
		else
		{
			cout << " Hero is dead\n";
		}
	}
};

class CrazyScientist : public Unit
{
public:
	CrazyScientist() :Unit(8, 10, 30) {};

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
				cout << " Hero is dead!\n";
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

			if (GetNum() > 0)
			{
				cout << " I have weapon.\n ";
			}
			cout << endl;
		}
		else
		{
			cout << " Hero is dead\n";
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
				cout << " Hero is dead!\n";
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

			if (GetNum() > 0)
			{
				cout << " I have weapon. \n";
			}

			cout << endl;
		}
		else
		{
			cout << " Hero is dead\n";
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