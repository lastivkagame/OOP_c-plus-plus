#pragma once
#include "Team.h"
#include <Windows.h>

class Game
{
private:
	Team* team[2];
public:
	Game(string name = "user's team")
	{
		team[0] = new Team(name);
		team[1] = new Team("Enemy team");
	}

	Game& operator=(Game&& obj)
	{
		if (this == &obj)
		{
			return *this;
		}

		delete team;

		team[0] = obj.team[0];
		team[1] = obj.team[1];

		obj.team[0] = nullptr;
		obj.team[1] = nullptr;
		return *this;
	}

	void Play()
	{
		system("cls");

		cout << " \t-> Start Game <-\n\n";

		while (true)
		{

			Show();

			Animation(" >>> ------ > ", "\t - Your team attack enemy team - \n");
			Attack(0, 1);

			Sleep(2000);
			system("cls");

			Animation(" >>> ------ > ", "\t - Enemy team attack you - \n");
			Attack(1, 0);

			Sleep(2000);
			system("cls");

			if (!team[0]->IsLiveMan() || !team[1]->IsLiveMan())
			{
				break;
			}
		}
		Show();
	}

	void Show() const
	{
		cout << " Team 1 (your team): ";
		team[0]->Print();

		cout << endl;

		cout << " Team 2 : ";
		team[1]->Print();

		system("pause");
		system("cls");
	}

	void Animation(string obj, string text) const
	{
		string prop = "\t";
		for (int i = 0; i < 4; i++)
		{
			cout << text << endl;
			cout << prop << obj;
			prop += "\t";
			Sleep(500);

			system("cls");
		}
	}

	void Attack(int frend, int enemy)
	{
		int num, num2;
		bool flag = false;

		do
		{
			num = rand() % 3;
		} while (team[frend]->GetUnit(num)->Die());

		for (int i = 0; i < 3; i++)
		{
			if (typeid(team[frend]->GetUnit(num)).name() == typeid(team[enemy]->GetUnit(i)).name())
			{
				if (!team[enemy]->GetUnit(i)->Die())
				{
					num2 = i;
					flag = true;
					break;
				}
			}
		}

		if (flag == false)
		{
			do
			{
				num2 = rand() % 3;
			} while (team[enemy]->GetUnit(num2)->Die());
		}

		team[frend]->GetUnit(num)->Attack(team[enemy]->GetUnit(num2));
	}
};