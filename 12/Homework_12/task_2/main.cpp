/*	�������� ���� �����, �� ������� �ᒺ��� ���� ���.
 �������� �����:
 - ������ �����, �� ������� �ᒺ��� ���� �������� ϳ��������,
 - ������ �����, �� ������� �ᒺ��� ���� ���������� ������,
 - �������� �����, �� ������� �ᒺ��� ���� ������ ˳���.
���������� ������� �������� �����, �������� ��������� ������� ������ ���������.
���� ������ ���������� ����������������: �������, ����������� ����������� (damage).
����������� ��� �������� �������� ��������� ����� � �������� ���������.*/

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