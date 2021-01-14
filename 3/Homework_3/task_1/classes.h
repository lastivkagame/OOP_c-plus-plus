#pragma once
#include <iostream>
#include <ctime>
using namespace std;

enum typeCar {
	COMPARTMENT = 36,     //купе        МАХ - 36 пасажирів
	SLEEPING = 10,       //спальний     МАХ - 10 пасажирів     ось тут про вагони і заг к-сть місць -http://droid.pp.ua/?p=15986
	SEATPOST = 54       //плацкарт      МАХ - 54 пасажирів
};

class Car {
private:
	int passengers;
	typeCar type;
public:
	//конструктори
	Car();
	Car(int passengers, typeCar type);

	//сеттери
	void SetPassengers();
	void SetTypeCar(typeCar type);

	//геттери
	int GetPassengers()const;
	typeCar GetTypeCar()const;

	//конструктор копій
	Car(const Car& obj1);

	//operator = 
	Car& operator=(const Car& obj);

	//методи виводу
	void print();
};

class Train {
	int size; //кількість вагонів - константне поле, ініціалізують у списку ініціалізації конструктора
	int number;     //номер поїзда
	Car* train = new Car[size];  //поле “вагони” - вказівник на тип Car, якому буде виділятися динамічна пам`ять
	char* name;  //назва поїзда (сполучення, наприклад “Львів – Київ”)
public:
	//конструктори
	Train(int size, int number, Car* train, char* name);    //повний
	Train();   //дефолтний

	//метод виводу
	void print()const;

	//сеттери
	void SetNumber(int number);
	void SetName(const char* name);
	void SetTrain(Car* train, int size);
	void SetSize(int size);

	//геттери
	int GetSize()const;
	int GetNumber()const;
	char* GetName()const;
	Car* GetTrain()const;

	//конструктор копій
	Train(const Train& tr);

	//operator = 
	Train& operator=(const Train& obj);

	// загальна кількість вагонів.
	int AllCars()const;

	// загальна кількість пасажирів.
	int Passengers()const;

	//mетод для знаходження вагона з максимальною кількість пасажирів
	int MaxPassengers()const;

	//mетод для знаходження вагона з мінімальною кількість пасажирів
	int MinPassengers()const;

	int FindTrainMaxPass(const Train* tr, int size);
	int FindTrainMinPass(const Train* tr, int size);

	//деструктор
	~Train();

};