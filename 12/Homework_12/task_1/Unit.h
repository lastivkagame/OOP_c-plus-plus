#pragma once
#include <iostream>
using namespace std;

enum Players
{
	ARCHER = 1, MAGE, SWARDMEN
};

class Unit abstract
{
private:
	int hp;		//хіт-поінтів (життів)
	int dmg;		//пошкодження при атаці
	int dodge;	//шанс ухилятись
public:
	Unit(int hp = 0, int dmg = 0, int dodge = 0) :hp(hp), dmg(dmg), dodge(dodge) {};

	virtual void Attack(Unit* enemy) = 0;

	Unit(Unit& obj)
	{
		this->hp = hp;
		this->dmg = dmg;
		this->dodge = dodge;
	}

	virtual bool Die()
	{
		if (Gethp() <= 0)
		{
			return true;
		}

		return false;
	};

	virtual int Gethp()const
	{
		return this->hp;
	}

	virtual int Getdmg() const
	{
		return this->dmg;
	}

	virtual int Getdodge()const
	{
		return this->dodge;
	}

	virtual void EnemyAttak(Unit*& enemy)
	{
		if ((!enemy->Die()) && !(this->Die()))
		{
			int temp;
			temp = rand() % 100;

			if (enemy->Getdodge() < temp)
			{
				enemy->hp -= this->Getdmg();
				cout << " I hit the target\n";

				if (enemy->hp < 0)
				{
					cout << " Enemy is die\n";
				}
			}

			else
			{
				cout << " Its missed\n";
			}
		}
		else
		{
			cout << " Attaka can be only if both person is not die \n";
		}
	}

	virtual void Print() = 0;

	virtual	~Unit() {};
};

class Archer :public Unit
{
public:
	Archer() :Unit(12, 4, 40) {};

	void Attack(Unit* enemy)
	{
		cout << " - Attacked by Archer - \n\n";
		this->EnemyAttak(enemy);
	};

	void Print()
	{
		cout << " \t - Archer - \n";
		cout << " Hp: " << Gethp() << "   Dmg: " << Getdmg() << "   Dodge: " << Getdodge() << endl;
	}
};

class Mage :public Unit
{
public:
	Mage() :Unit(8, 10, 30) {};

	void Attack(Unit* enemy)
	{
		cout << " - Attacked by Mage - \n";
		this->EnemyAttak(enemy);
	};

	void Print()
	{
		cout << " \t - Mage - \n";
		cout << " Hp: " << Gethp() << "   Dmg: " << Getdmg() << "   Dodge: " << Getdodge() << endl;
	}
};

class Swardman :public Unit
{
public:
	Swardman() :Unit(15, 5, 60) {};

	void Attack(Unit* enemy)
	{
		cout << " - Attacked by Swardman - \n";
		this->EnemyAttak(enemy);
	};

	void Print()
	{
		cout << " \t - Swardman - \n";
		cout << " Hp: " << Gethp() << "   Dmg: " << Getdmg() << "   Dodge: " << Getdodge() << endl;
	}
};