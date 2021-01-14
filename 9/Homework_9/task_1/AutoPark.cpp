#include "AutoPark.h"

AutoPark::AutoPark(BusList busOnRoute, BusList busInAutoPark) 
{
	this->busOnRoute = busOnRoute;
	this->busInAutoPark = busInAutoPark;
}

// ��������� ��������� ��� ��������, �� ����������� � ���������
void AutoPark::PrintAutoPark() const
{
	system("cls");
	cout << "  -> Bus in autopark <-  \n";
	busInAutoPark.Print();
	cout << endl;
}

// ��������� ��������� ��� ��������, �� ����������� �� �������.
void AutoPark::PrintBusRoute() const
{
	system("cls");
	cout << "  -> Bus on route <-  \n";
	busOnRoute.Print();
	cout << endl;
}

//������ ������� -- ����� ������� �������� �� ���������
void AutoPark::BuyBus(string number, string driver, int numRoute)
{
	busInAutoPark.AddHead(number, driver, numRoute);
}

//������� ������� -- ������� ������� ����������� � ���������
void AutoPark::SellBus()
{
	int el = busInAutoPark.choose();
	busInAutoPark.DelCurrent(el);
}

//�� ������� -- ������� ������� ����������� � ��������� � �������� �� ������ �� �������
void AutoPark::ToRoute()
{
	int i = busInAutoPark.choose();
	busOnRoute.AddHead(busInAutoPark.GetNumber(i), busInAutoPark.GetDriver(i), busInAutoPark.GetnumRoute(i));
	busInAutoPark.DelCurrent(i);
}

//�� ������� -- ������� ������� ����������� � ������ �� ������� � �������� �� ������ ���������
void AutoPark::ToAutoPark()
{
	int i = busOnRoute.choose();
	busInAutoPark.AddHead(busOnRoute.GetNumber(i), busOnRoute.GetDriver(i), busOnRoute.GetnumRoute(i));
	busOnRoute.DelCurrent(i);
}
