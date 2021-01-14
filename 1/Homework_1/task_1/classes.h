#pragma once
#include <iostream>
using namespace std;

class Car {
private:
	char* brand;
	char* model;
	char* color;
	int year;
	char* gearbox;
	char* engineType;
	double price;
public:
	//конструктор -  це метод ініціалізувати обєкт
	Car(const char* br = "brand", const char* modl = "model", const char* col = "color", int yearCar = 2019, const char* gearb = "gearbox", const char* engType = "engine Type", double pric = 0);
	void print();

	// геттери
	char* GetBrand();
	char* GetModel();
	char* GetColor();
	int GetYear();
	char* GetGearbox();
	char* GetEngineType();
	double GetPrice();

	//сеттери
	void SetBrand(const char* br);
	void SetModel(const char* modl);
	void SetColor(const char* col);
	void SetYear(int yearCar);
	void SetGearbox(const char* gearb);
	void SetEngineType(const char* engType);
	void SetPrice(double pric);

	~Car();
};
