#include "AutoPark.h"

AutoPark::AutoPark(BusList busOnRoute, BusList busInAutoPark) 
{
	this->busOnRoute = busOnRoute;
	this->busInAutoPark = busInAutoPark;
}

// Виведення відомостей про автобуси, які знаходяться в автопарку
void AutoPark::PrintAutoPark() const
{
	system("cls");
	cout << "  -> Bus in autopark <-  \n";
	busInAutoPark.Print();
	cout << endl;
}

// Виведення відомостей про автобуси, які знаходяться на маршруті.
void AutoPark::PrintBusRoute() const
{
	system("cls");
	cout << "  -> Bus on route <-  \n";
	busOnRoute.Print();
	cout << endl;
}

//купити автобус -- новий автобус додається до автопарку
void AutoPark::BuyBus(string number, string driver, int numRoute)
{
	busInAutoPark.AddHead(number, driver, numRoute);
}

//продати автобус -- обраний автобус видаляється з автопарку
void AutoPark::SellBus()
{
	int el = busInAutoPark.choose();
	busInAutoPark.DelCurrent(el);
}

//на маршрут -- обраний автобус видаляється з автопарку і додається до списку на маршруті
void AutoPark::ToRoute()
{
	int i = busInAutoPark.choose();
	busOnRoute.AddHead(busInAutoPark.GetNumber(i), busInAutoPark.GetDriver(i), busInAutoPark.GetnumRoute(i));
	busInAutoPark.DelCurrent(i);
}

//на стоянку -- обраний автобус видаляється зі списку на маршруті і додається до списку Автопарку
void AutoPark::ToAutoPark()
{
	int i = busOnRoute.choose();
	busInAutoPark.AddHead(busOnRoute.GetNumber(i), busOnRoute.GetDriver(i), busOnRoute.GetnumRoute(i));
	busOnRoute.DelCurrent(i);
}
