/*3. ������� ���� Fortress (�������).
 ��� �������, �������� ���� Shooter (�������), ���� ���� ������ ��� ����:
	o ����� �������
	o ������� �������.
 ������� ����
	o �������� �� &quot;������&quot; � ��������� ��� ����� ������� �������, ����������� �
		�������, �� ���� ����������;
	o �������� �� &quot;���� �������&quot;, ��� ��������������� ����� � ������� �������,
		��������� �� ��� ����� ���������.

������� �� ��� ������ �����: Archer (������), Range (��������) �� Catapult(����������),
�� �������� �� &quot;������&quot;, ���������� ����������� � �������
����������� ��� ��, ��� ���� � ��� ��������.

����� ��� ������ ������� �������, � ���������� - ��������.
³� ������ ���� ����������� ���� ArcherTower(C�������� ����), � ��� ����� �������
�� ���� ���� (�������) ��� ����: ������� � ��������� (���������, ���� �������
���������� ������������ ��� ����� �����������).

³� ����� �������� ���� � ���������� �� �������� ���� Fortress.
���� � �� ����������� ����� ������������ ����� ��� �������� ��� � ����� ���
����������.

������� �� ������� �� ����� ���� - ������� ���, ���� ���� � ��������, � �. �. - ��
���� ������� �� �������.

� ������� � ���� �� ������ � ��� �������� �� ���� ������������ ������������ �����
�������, � ������������ �� ���������� �� ������� ����������� �� �������
�������������� �������.

��� �����, ��� � main() ����� ���� �������� ��������:
	�������� ��'��� �������
	��������� ��������(�-� 3 ����), ����������(�-�, 2 ����) � � ����������

����, ������ �� ���� 6 �����, ��������� ������ ����� ��� � ���� �������, ���� ����
��'��� ��� ���� ��������.

������� �� �� ����� - 6 ����� �������, �� ����������������. ��� ��'��� � ��� ������� ����(�������)

	���̲���! ���� ���������������� �������, �������� � �������� ���� ���� 4 �����,
��� ���� ���� �����, �� �� ������ ������ ��������� ���� �� ���������, �������
������ ����� ��� �������� 3 �� 4-� ����.*/

#include "Fortress.h"
#include <ctime>

int main()
{
	srand(time(nullptr));

	Fortress fortress("pule", 4);
	fortress.Archertower("archer");
	fortress.Archertower("archer");
	fortress.Archertower("archer");
	fortress.Archertower("range");
	fortress.Archertower("range");

	system("pause");
	system("cls");

	Fortress fortress2("pule", 300);
	Fortress myfortress("pule", 300);
	cout << " --- Welcome --- \n";
	cout << " You have a fortress, you can choose who must shoot.\nThey fired my fortress. I fire your fortress. \nIf you first destroyed my fortress  -  you win, else I win\n\n";
	int choose;

	while (fortress2.IsFortrees())
	{
		cout << " Choose who you want that fire:\n";
		cout << " 1 - archer\n";
		cout << " 2 - ranger\n";
		cout << " 3 - catapulta\n";
		cout << "Answer: ";
		cin >> choose;

		if (choose == 1)
		{
			cout << " --- Your attac ---- \n";
			fortress2.Archertower("archer");  //������� ������
			cout << endl;
			cout << " --- Enemy attac ---- \n";
			myfortress.Archertower("catapult");  //� �������

			// �������� �����������
			fortress2.ConsistentWound((rand() % 20));
			myfortress.ConsistentWound((rand() % 20));
		}
		else if (choose == 2)
		{
			cout << " --- Your attac ---- \n";
			fortress2.Archertower("range");  //������� ������
			cout << endl;
			cout << " --- Enemy attac ---- \n";
			myfortress.Archertower("archer");  //� �������

			// �������� �����������
			fortress2.ConsistentWound((rand() % 20));  //������� ������
			myfortress.ConsistentWound((rand() % 20));  //� �������
		}
		else
		{
			cout << " --- Your attac ---- \n";
			fortress2.Archertower("catapult");  //������� ������
			cout << endl;
			cout << " --- Enemy attac ---- \n";
			myfortress.Archertower("range");   //� �������

			// �������� �����������
			fortress2.ConsistentWound((rand() % 20));
			myfortress.ConsistentWound((rand() % 20));
		}

		if (!myfortress.IsFortrees())
		{
			break;
		}
		system("pause");
		system("cls");
		cout << " --- Your fortress ---\n";
		fortress2.Print();
		system("pause");
		system("cls");
		cout << " --- Enemies fortress ---\n";
		myfortress.Print();
		system("pause");
		system("cls");
	}

	if (fortress2.IsFortrees())
	{
		cout << " \nYou Win!\n";
	}
	else
	{
		cout << " \nYou Lose!\n";
	}

	cout << " --- Your fortress ---\n";
	fortress2.Print();
	cout << endl << endl;
	cout << " --- Enemies fortress ---\n";
	myfortress.Print();
	cout << endl << endl;

	return 0;
}