/*	Створити клас Барак, що створює об’єкти типу Юніт.
 Створити класи:
 - Воєнний Барак, що створює об’єкти типу Морський Піхотинець,
 - Вчений Барак, що створює об’єкти типу Божевільний Вчений,
 - Медичний Барак, що створює об’єкти типу Воєнний Лікар.
Побудувати відповідні ієрархії класів, коректно визначити фабричні методи створення.
Юніти повинні відрізнятись характеристиками: здоров’я, максимальне пошкодження (damage).
Використати при виконанні завдання Фабричний метод у класичній реалізації.*/

#include "Barrack.h"
#include <vector>

int main()
{
	vector<Unit*>players;

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
	while (true)
	{
		cout << " - Please choose - \n Marines = 1\t Crazyscientist = 2\t Militarydoctor = 3\t exit = 0\n Answer: ";
		cin >> choice;

		if (choice < 0 || choice>3)
		{
			choice = 0;
		}

		if (choice == 0)
		{
			break;
		}
		else
		{
			players.push_back(factory[choice - 1]->CreatePlayer());
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

	system("pause");
	system("cls");

	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Play(players[k--]);
		cout << endl;
	}

	system("pause");
	system("cls");

	cout << "  --- Print --- \n";
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Print();
	}
	cout << endl;

	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}

	return 0;
}