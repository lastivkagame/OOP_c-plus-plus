#pragma once
#include "BusList.h"

class AutoPark
{
private:
	BusList busOnRoute;
	BusList busInAutoPark;
public:
	AutoPark() = default;
	AutoPark(BusList busOnRoute, BusList busInAutoPark);

	// ��������� ��������� ��� ��������, �� ����������� � ���������
	void PrintAutoPark()const;

	// ��������� ��������� ��� ��������, �� ����������� �� �������.
	void PrintBusRoute()const;

	//������ ������� -- ����� ������� �������� �� ���������
	void BuyBus(string number, string driver, int numRoute);

	//������� ������� -- ������� ������� ����������� � ���������
	void SellBus();

	//�� ������� -- ������� ������� ����������� � ��������� � �������� �� ������ �� �������
	void ToRoute();

	//�� ������� -- ������� ������� ����������� � ������ �� ������� � �������� �� ������ ���������
	void ToAutoPark();
};

