#include "classes.h"

// -------------- CLASS Car ----------------

Car::Car() :Car(1, COMPARTMENT) {}
Car::Car(int passengers, typeCar type) : passengers(passengers)
{
	SetTypeCar(type);
}

//сеттери
void Car::SetPassengers()
{
	//по умові сказано що користувач не має вводити к-сть пасажирів значитть це робимо ми і робимо це рандомом
	switch (type)
	{
	case COMPARTMENT:
		this->passengers = rand() % 37; //до 37 не включно
		break;
	case SLEEPING:
		this->passengers = rand() % 11; //до 10
		break;
	case SEATPOST:
		this->passengers = rand() % 55; //до 54
		break;
	default:
		cout << "How it?\n";
		break;
	}
}

void Car::SetTypeCar(typeCar type)
{
	this->type = type;
}

//геттери
int Car::GetPassengers() const
{
	return passengers;
}

typeCar Car::GetTypeCar()const
{
	return type;
}

//конструктор копій
Car::Car(const Car& obj1)
{
	this->SetTypeCar(obj1.GetTypeCar());
	this->passengers = obj1.GetPassengers();
}

//operator = 
Car& Car:: operator=(const Car& obj)
{
	//Train temp;
	this->SetTypeCar(obj.GetTypeCar());
	this->passengers = obj.GetPassengers();

	return *this;
}

//методи виводу
void Car::print()
{
	cout << "Passengers: " << passengers << endl;
	cout << "Type: ";
	switch (type)
	{
	case COMPARTMENT:
		cout << "COMPARTMENT\n";
		break;
	case SLEEPING:
		cout << "SLEEPING\n";
		break;
	case SEATPOST:
		cout << "SEATPOST\n";
		break;
	default:
		break;
	}
}

// ----------- CLASS Train ----------------

//конструктори
Train::Train() :size(1), number(1)
{
	for (int i = 0; i < size; i++)
	{
		this->train[i] = Car();
	}

	SetName("none");
}

Train::Train(int size, int number, Car* train, char* name) : size(size), number(number)
{
	SetName(name);
	SetTrain(train, size);
}

//конструктор копій
Train::Train(const Train& obj) :size(obj.GetSize()), number(obj.number)
{
	this->SetName(obj.GetName());
	this->SetTrain(obj.GetTrain(), obj.GetSize());
}

//метод виводу
void Train::print()const
{

	cout << "Number: " << number << endl;
	cout << "Name: " << name << endl;
	cout << "All Car: " << AllCars() << endl;
	cout << "All Passengers: " << Passengers() << endl;
	cout << "MaxPassengers in car: " << train[MaxPassengers()].GetPassengers() << endl;
	cout << "MinPassengers in  car: " << train[MinPassengers()].GetPassengers() << endl;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Car #" << i << endl;
		train[i].print();
		cout << endl;
	}
	cout << "--------------------------------\n";
}

//сеттери
void Train::SetNumber(int number)
{
	this->number = number;
}

void Train::SetName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Train::SetTrain(Car* train, int size)
{
	this->train = new Car[size];

	for (int i = 0; i < size; i++)
	{
		this->train[i] = train[i];
	}
}

void Train::SetSize(int size)
{
	this->size = size;
}

//геттери
int Train::GetSize()const
{
	return size;
}

int Train::GetNumber()const
{
	return number;
}

char* Train::GetName()const
{
	return name;
}

Car* Train::GetTrain()const
{
	return train;
}

//operator = 
Train& Train:: operator=(const Train& obj)
{
	//Train temp;
	this->SetName(obj.GetName());
	this->SetNumber(obj.GetNumber());
	this->SetSize(obj.GetSize());

	this->SetTrain(obj.GetTrain(), obj.GetSize());

	return *this;
}

// загальна кількість вагонів.
int Train::AllCars() const
{
	return size;
}

// загальна кількість пасажирів.
int Train::Passengers() const
{
	int temp = 0;

	for (int i = 0; i < size; i++)
	{
		temp += train[i].GetPassengers();
	}

	return temp;
}

//mетод для знаходження вагона з максимальною кількість пасажирів
int Train::MaxPassengers() const
{
	int index = 0;
	int max;

	for (int i = 0; i < size; i++)
	{
		max = train[i].GetPassengers();

		if (max < train[i + 1].GetPassengers())
		{
			index = i;
		}
	}
	return index;
}

//mетод для знаходження вагона з мінімальною кількість пасажирів
int Train::MinPassengers() const
{
	int index = 0;
	int min;

	for (int i = 0; i < size; i++)
	{
		min = train[i].GetPassengers();

		if (min > train[i + 1].GetPassengers())
		{
			index = i;
		}
	}
	return index;
}

int Train::FindTrainMaxPass(const Train* tr, int size)
{
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (tr[i - 1].Passengers() < tr[i].Passengers())
		{
			index = i;
		}
	}

	return index;
}

int Train::FindTrainMinPass(const Train* tr, int size)
{
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (tr[i - 1].Passengers() > tr[i].Passengers())
		{
			index = i;
		}
	}

	return index;
}

Train::~Train()
{
	if (name != nullptr)
	{
		delete[]name;
		name = nullptr;
	}

	if (train != nullptr)
	{
		delete[]train;
		train = nullptr;
	}
}