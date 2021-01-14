/*���������� ���� ��� ������ � �����������(��� ����������) ������� (class BusList).

������� ������ ������ �������� ���������� ��� ������� (class ��� struct Bus) :
o ����� �������� ;
o ������� �� ������� ����;
o ����� ��������.

�� ����� ����� BusList �������� ���� AutoPark, ������ ������� �������������
1) ��������� ���������� ���� ������:
o � ������ ��� ��������, �� ����������� � ���������;
o � ������ ��� ��������, �� ����������� �� ���������.

2) ��� ���� ������� �������� � ��������� �������� ������� ��� ��� ��� ������� �
������ ��������, �� ����������� � ���������, �� ������ �� ��� � ������
��������, �� ����������� �� �������. ���� ������ ������� ����������� �
��������, ���������� ���������� ��������

3) ��������� ��������� ��� ��������, �� ����������� � ���������
4) ��������� ��������� ��� ��������, �� ����������� �� �������.

���� AutoPark �������� � ����.
�������:
o ������ ������� -- ����� ������� �������� �� ���������
o ������� ������� -- ������� ������� ����������� � ���������
o �� ������� -- ������� ������� ����������� � ��������� � �������� �� ������ ��
�������
o �� ������� -- ������� ������� ����������� � ������ �� ������� � �������� ��
������ ���������
������� ������� ����� ����� �������:
o �������� ���� ����� � ������,
o ��� ���������� ���� �������� �������� ������� (����� / ������) �������
������� ���������� ��������� ��������*/

#include "BusList.h"
#include "AutoPark.h"

int main()
{
	BusList listbus;
	listbus.AddHead("S1", "A.P.Ivanov", 1406);
	listbus.AddHead("S2", "T.L.Kotovsky", 1545);
	listbus.AddHead("S3", "W.Q.Petrov", 1091);
	listbus.Print();

	BusList busOnRoute;
	busOnRoute.AddHead("W1", "R.P.Popov", 8702);
	busOnRoute.AddHead("W2", "P.L.Sayetskiy", 9123);
	busOnRoute.AddHead("W3", "K.Q.Petrovich", 6209);
	busOnRoute.Print();

	AutoPark autopark(busOnRoute, listbus);

	int choose, numRoute;
	string  driver, num;

	do
	{
		system("cls");
		cout << " --- Menu --- \n";
		cout << " 1 - buy bus\n";
		cout << " 2 - sell bus\n";
		cout << " 3 - bus on route\n";
		cout << " 4 - bus in autopark(stopping)\n";
		cout << " 5 - print bus on route\n";
		cout << " 6 - print in autopark(stopping);\n";
		cout << " 7 - exit\n";
		cout << "Answer: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			cout << "Enter pls num bus, driver and numRoute\n";
			cin >> num >> driver >> numRoute;
			autopark.BuyBus(num, driver, numRoute);
			break;
		case 2:
			autopark.SellBus();
			break;
		case 3:
			autopark.ToRoute();
			break;
		case 4:
			autopark.ToAutoPark();
			break;
		case 5:
			autopark.PrintBusRoute();
			break;
		case 6:
			autopark.PrintAutoPark();
			break;
		case 7:
			break;
		default:
			cout << "Inccorect direction!\n\n";
			break;
		}
		system("pause");

	} while (choose != 7);

	return 0;
}