#pragma once
#include "Barrack.h"
#include <string>
#include <ctime>

class Game
{
private:
	string name;
public:
	void Start()
	{
		vector<Unit*>players;
		vector<Unit*>enemyes;

		enum Players
		{
			MARINES = 1,
			CRAZYSCIENTIST,
			MILITARYDOCTOR
		};

		MedicalBarrack mb;
		ScienceBarrack sb;
		WarBarrack wb;

		Barrack* factory[] = { &mb,&sb,&wb };

		int choice;
		int digit = 0;

		cout << " \t___ WELCOME! Now please create your team ___\n\n";

		while (true)
		{
			cout << " - Please choose - \n Marines = 1\t Crazyscientist = 2\t Militarydoctor = 3\t exit = 0\n Answer: ";
			cin >> choice;

			if (choice < 0 || choice>3)
			{
				choice = 0;
				cout << " Inccorect direction!\n";
			}

			if (choice == 0)
			{
				break;
			}
			else
			{
				players.push_back(factory[choice - 1]->CreatePlayer());
				choice = rand() % 3;
				enemyes.push_back(factory[choice]->CreatePlayer());

				cout << " - Add weapont - \n";
				players[digit]->AddWeapon();
				enemyes[digit++]->AddRandWeapont();

			}
			cout << endl;
		}

		system("pause");
		system("cls");
		int k = players.size() - 1;

		cout << "  --- Print --- \n";
		for (int i = 0; i < players.size(); i++)
		{
			players[i]->Print();
		}
		cout << endl;

		cout << "__________________________________________" << endl;
		cout << " Your team is ready please give them name: ";
		cin >> name;
		cout << "\n\t Wonderful! However, the enemies are already ready. Good luck!\n";

		system("pause");
		system("cls");

		bool flag = true;
		bool flag2 = true;

		do
		{

			cout << " --- " << name << " (you) attacked --- \n ";
			cout << " Enter hero: \n";

			for (int i = 0; i < players.size(); i++)
			{
				if (!players[i]->IsHeroDie())
				{
					flag = false;
				}
			}

			for (int i = 0; i < enemyes.size(); i++)
			{
				if (!enemyes[i]->IsHeroDie())
				{
					flag2 = false;
				}
			}

			if (flag)
			{
				system("cls");
				cout << "  --- You Lose! --- \n";
				break;
			}

			if (flag2)
			{
				system("cls");
				cout << "  --- You Win! --- \n";
				break;
			}

			flag = true;
			flag2 = true;

			do
			{
				for (int i = 0; i < players.size(); i++)
				{
					cout << " \t - " << i << " -\n";
					players[i]->Print();
				}
				cout << endl;

				cout << " Answer: ";
				cin >> choice;

				if (choice > players.size() || choice < 0)
				{
					cout << " Inccorect direction!\n";
					choice = 0;
				}

			} while (players[choice]->IsHeroDie());

			int answer;

			if (players[choice]->IsHeroWeapon())
			{
				cout << " Do you want use weapon or simple skill hero ?\n";
				cout << " 1 - Weapon \n 2 - Skill hero \n Answer: ";
				cin >> answer;

				if (answer < 0 || answer > 2)
				{
					answer = 2;
				}
			}
			else
			{
				answer = 2;
				cout << " Now you not have weaponts(maybe you use it already or not take even), will be use hero's skill\n";
			}

			int en;
			cout << " After: \n";

			do
			{
				en = rand() % enemyes.size();
			} while (enemyes[en]->IsHeroDie());

			if (answer == 1)
			{
				players[choice]->UseWeapon(enemyes[en]);
			}
			else
			{
				players[choice]->Play(enemyes[en]);
			}

			system("pause");
			system("cls");

			cout << " \nEnemy is attak you\n";

			choice = rand() % enemyes.size();
			en = rand() % players.size();
			answer = rand() % 2;

			if (answer == 1 && enemyes[choice]->IsHeroWeapon())
			{
				enemyes[choice]->UseWeapon(players[en]);
			}
			else
			{
				enemyes[choice]->Play(players[en]);
			}

			cout << " \nSee resalts\n";

			system("pause");
			system("cls");

			cout << " \t--- Resalt --- \n\n";
			cout << "\t -" << name << "(you)- \n";
			for (int i = 0; i < players.size(); i++)
			{
				players[i]->Print();
			}

			cout << endl;

			cout << "\t -Enemyes- \n";
			for (int i = 0; i < enemyes.size(); i++)
			{
				enemyes[i]->Print();
			}

			system("pause");
			system("cls");

		} while (true);

		system("pause");
		system("cls");
	}
};