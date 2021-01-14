#pragma once
#include "Unit.h"
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

class Team
{
private:
	string name;
	Unit* unit[3];
public:
	Team(string name)
	{
		this->name = name;

		int temp;

		for (int i = 0; i < 3; i++)
		{
			temp = rand() % 3;

			switch (temp)
			{
			case 1:
				unit[i] = new Archer();
				break;
			case 2:
				unit[i] = new Mage();
				break;
			default:case 3:
				unit[i] = new Swardman();  // ÿךשמ םףכü
				break;
			}
		}
	}

	Team(Team& obj)
	{
		this->name = obj.name;

		for (int i = 0; i < 3; i++)
		{
			this->unit[i] = obj.unit[i];
		}
	}

	Team& operator=(Team&& obj)
	{
		if (this == &obj)
		{
			return *this;
		}

		delete unit;

		for (int i = 0; i < 3; i++)
		{
			unit[i] = obj.unit[i];
			obj.unit[i] = nullptr;
		}
		return *this;
	}

	bool IsLiveMan()const
	{
		if (unit[0]->Die() && unit[1]->Die() && unit[2]->Die())
		{
			return false;
		}
		return true;
	}

	Unit* GetUnit(int index) const
	{
		return unit[index];
	}

	void Print()const
	{
		cout << name << endl;
		cout << "\t-> Players <- \n";

		if (!unit[0]->Die())
		{
			unit[0]->Print();
		}

		if (!unit[1]->Die())
		{
			unit[1]->Print();
		}

		if (!unit[2]->Die())
		{
			unit[2]->Print();
		}
		cout << endl;
	}
};