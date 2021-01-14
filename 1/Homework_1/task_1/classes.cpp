#include "classes.h"

Car::Car(const char* br, const char* modl, const char* col, int yearCar, const char* gearb, const char* engType, double pric)
{
	SetBrand(br);
	SetModel(modl);
	SetColor(col);
	SetYear(yearCar);
	SetGearbox(gearb);
	SetEngineType(engType);
	SetPrice(pric);
}

void Car::print() {
	cout << "   Car \n";
	cout << " - brand: " << brand << endl;
	cout << " - model: " << model << endl;
	cout << " - color: " << color << endl;
	cout << " - year: " << year << endl;
	cout << " - gearbox: " << gearbox << endl;
	cout << " - engine type: " << engineType << endl;
	cout << " - price: " << price << endl;
}

// геттери
char* Car::GetBrand()
{
	return brand;
}

char* Car::GetModel()
{
	return model;
}

char* Car::GetColor()
{
	return color;
}

int Car::GetYear()
{
	return year;
}

char* Car::GetGearbox()
{
	return gearbox;
}

char* Car::GetEngineType()
{
	return engineType;
}

double Car::GetPrice()
{
	return price;
}

//сеттери
void Car::SetBrand(const char* br)
{
	//if (brand != nullptr)
	//{
	delete[]brand;
	//}

	brand = new char[strlen(br) + 1];
	strcpy_s(brand, strlen(br) + 1, br);
}

void Car::SetModel(const char* modl)
{
	//if (model != nullptr)
	//{
	delete[]model;
	//}

	model = new char[strlen(modl) + 1];
	strcpy_s(model, strlen(modl) + 1, modl);
}

void Car::SetColor(const char* col)
{
	//if (color != nullptr)
	//{
	delete[]color;
	//}

	color = new char[strlen(col) + 1];
	strcpy_s(color, strlen(col) + 1, col);
}

void Car::SetYear(int yearCar)
{
	year = yearCar;
}

void Car::SetGearbox(const char* gearb)
{
	//if (gearbox != nullptr)
	//{
	delete[]gearbox;
	//}

	gearbox = new char[strlen(gearb) + 1];
	strcpy_s(gearbox, strlen(gearb) + 1, gearb);
}

void Car::SetEngineType(const char* engType)
{
	//if (engineType != nullptr)
	//{
	delete[]engineType;
	//}

	engineType = new char[strlen(engType) + 1];
	strcpy_s(engineType, strlen(engType) + 1, engType);
}

void Car::SetPrice(double pric)
{
	price = pric;
}

Car::~Car()
{
	if ((brand) != nullptr)
	{
		delete[]brand;
		brand = nullptr;
	}

	if ((model) != nullptr)
	{
		delete[]model;
		model = nullptr;
	}

	if ((color) != nullptr)
	{
		delete[]color;
		color = nullptr;
	}

	if ((gearbox) != nullptr)
	{
		delete[]gearbox;
		gearbox = nullptr;
	}

	if ((engineType) != nullptr)
	{
		delete[]engineType;
		engineType = nullptr;
	}
}