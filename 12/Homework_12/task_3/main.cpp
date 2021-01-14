/*	���������� �������. ��������(Prototype).
���������������� ��������� ����� ���� ���� ��� ����� ���(����� ��������� ������ ��� ����).
� ������� ��������� ���� ������� �������� ����.
� ������� ����� �������� ��� ���������, ��������� ���� ��������� �� �������(������ �� enum)*/

#include "Game.h"

Weapon* FactoryWeapons::prototypes[] = { new Knifes, new Grenades, new Electroshock };
//int Unit::num = 0;

int main()
{
	srand(time(nullptr));

	Game game;
	game.Start();

	return 0;
}