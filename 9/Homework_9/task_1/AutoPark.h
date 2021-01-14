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

	// Виведення відомостей про автобуси, які знаходяться в автопарку
	void PrintAutoPark()const;

	// Виведення відомостей про автобуси, які знаходяться на маршруті.
	void PrintBusRoute()const;

	//купити автобус -- новий автобус додається до автопарку
	void BuyBus(string number, string driver, int numRoute);

	//продати автобус -- обраний автобус видаляється з автопарку
	void SellBus();

	//на маршрут -- обраний автобус видаляється з автопарку і додається до списку на маршруті
	void ToRoute();

	//на стоянку -- обраний автобус видаляється зі списку на маршруті і додається до списку Автопарку
	void ToAutoPark();
};

