/*������� ����� Swordsman; (������), Archer (������) � Mage (���), ����� � ���� �
����������� ��������(����� ������������) ����� Unit (�����, �������) � �����������
��, � ���� ���������, ��������� �� ���� � �������.
� ������� 15 ���-����� (�����), ����������� ��� ����� 5, ���� ��������� 60%.
������: 12 hp, 4 dmg, 40% dodge
���: 8 hp, 10 dmg, 30% dodge
-------------------------------------------------------------------------------------------------------------
������� ���� Team(�������), � ����� � ����
o ����� �������
o ����� �� ������ �� ���(�� �����) �����, ������� ��� ����� (������, ������ �� ���) �� ���������� ���������,
��� ���������� �������(�� ������� ���).
�������� ������:
o �������� �� � ������ � �� ���� ������
o ������ ������� �������
-------------------------------------------------------------------------------------------------------------
������� ���� Game;(���), �� ������ 2 ������� ���������� �����
������ ������� ���������� �����:
 - ��� ������� ����� ������� � ���� ����, ��� ������, ������ � ��� ����� ���� ������� �
������� � �.�(��� ������� ������� � ������ 3).

������� ����� ��� �� ���������, ���� ���� ������ � ����� �� �� ��������. �
������� ��� ����� �������� ����������� ��� ���� ��������, �� ������� �����, ������
����� ���������� � ������ �� ���� ��������. ����� �� ���������� ���������, ��
���������� ������ spacebar (������), ��� �� ����� ����������� ���� ����� �� ������.
� ���� ��� ��������, ��� ������� ��������� (�����/�����, ����/�������, ������/���� �� ��.).
...............................................................................................................
������� ��� : ����� ���� (���, ������ �� ���) ������ ����� ������ ��������� �����
���� � ����� ����.
������, ���� ���� �������:
A11 - M21
A12 - S22
S13 - A23
...�� �11 �� ������� �� ����� �23.
���� ������ ����� ���� �� ��������, ��� ����� ���� �������� ��������� ���������*/

#include "Game.h"

int main()
{
	srand(time(0));

	string name;

	cout << " Enter name for your team: ";
	getline(cin, name);

	Game game(name);
	game.Play();

	return 0;
}