#include "classes.h"

// -------------- CLASS Car ----------------

Car::Car() :Car(1, COMPARTMENT) {}
Car::Car(int passengers, typeCar type) : passengers(passengers)
{
	SetTypeCar(type);
}

//�������
void Car::SetPassengers(int passengers)
{
	switch (type)
	{
	case COMPARTMENT:
		if (passengers <= COMPARTMENT)
		{
			this->passengers = passengers;
		}
		else
		{
			cout << "Inccorect direction! (I take my value)\n";
			this->passengers = rand() % 37; //�� 37 �� �������
		}
		break;
	case SLEEPING:
		if (passengers <= SLEEPING)
		{
			this->passengers = passengers;
		}
		else
		{
			cout << "Inccorect direction!(I take my value)\n";
			this->passengers = rand() % 11; //�� 10
		}
		break;
	case SEATPOST:
		if (passengers <= SEATPOST)
		{
			this->passengers = passengers;
		}
		else
		{
			cout << "Inccorect direction!(I take my value)\n";
			this->passengers = rand() % 55; //�� 54
		}
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

//�������
int Car::GetPassengers() const
{
	return passengers;
}

typeCar Car::GetTypeCar()const
{
	return type;
}

//����������� ����
Car::Car(const Car& obj1)
{
	this->SetPassengers(obj1.GetPassengers());
	this->SetTypeCar(obj1.GetTypeCar());
}

//operator = 
/*
Car& Car:: operator=(const Car& obj)
{
	Car temp(obj);
	*this = temp;
	return *this;
}*/

//������ ������
void Car::print()
{
	cout << "Passengers: " << passengers << endl;
	cout << "TypeCar: " << type << endl;
}

// ----------- CLASS Train ----------------

//������������
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
	SetTrain(train);
}

//����������� ����
Train::Train(const Train& obj) :size(obj.size), number(obj.number)
{
	this->SetName(obj.GetName());

	for (int i = 0; i < size; i++)
	{
		this->train[i] = obj.train[i];
	}
}

//����� ������
void Train::print()const
{
	cout << "Number: " << number << endl;
	cout << "Name: " << name << endl;

	cout << "All Car: ";
	AllCars();
	cout << endl;

	cout << "All Passengers: ";
	Passengers();
	cout << endl;

	cout << "MaxPassengers: ";
	MaxPassengers();
	cout << endl;

	cout << "MinPassengers";
	MinPassengers();
	cout << endl;
}

//�������
void Train::SetNumber(int number)
{
	this->number = number;
}

void Train::SetName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Train::SetTrain(Car* train)
{
	this->train = new Car[size];
	this->train = train;
}

//�������
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

	for (int i = 0; i < size; i++)
	{
		this->train[i] = obj.train[i];
	}
	
	return *this;
}

// �������� ������� ������.
int Train::AllCars() const
{
	return size;
}

// �������� ������� ��������.
int Train::Passengers() const
{
	int temp = 0;

	for (int i = 0; i < size; i++)
	{
		temp += train[i].GetPassengers();
	}

	return temp;
}

//m���� ��� ����������� ������ � ������������ ������� ��������
int Train::MaxPassengers() const
{
	int index = 0;
	int max;

	for (int i = 0; i < size; i++)
	{
		max = train[i].GetPassengers();

		if (max > train[i + 1].GetPassengers())
		{
			index = i;
		}
	}
	return index;
}

//m���� ��� ����������� ������ � ��������� ������� ��������
int Train::MinPassengers() const
{
	int index = 0;
	int min;

	for (int i = 0; i < size; i++)
	{
		min = train[i].GetPassengers();

		if (min < train[i + 1].GetPassengers())
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