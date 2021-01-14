#include "class.h"

//конструктор
Person::Person(const char* name, int age, const char* gender, int number)
{
	SetName(name);
	SetAge(age);
	SetGender(gender);
	SetNumber(number);
}

//сеттери
void Person::SetName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Person::SetAge(int age)
{
	this->age = age;
}

void Person::SetGender(const char* gender)
{
	this->gender = new char[strlen(gender) + 1];
	strcpy_s(this->gender, strlen(gender) + 1, gender);
}

void Person::SetNumber(int number)
{
	this->number = number;
}


//геттери
char* Person::GetName()
{
	return name;
}

int  Person::GetAge()
{
	return age;
}

char* Person::GetGender()
{
	return gender;
}

int  Person::GetNumber()
{
	return number;
}

//конструктор копій
Person::Person(Person& obj)
{
	this->SetName(obj.GetName());
	this->SetAge(obj.GetAge());
	this->SetGender(obj.GetGender());
	this->SetNumber(obj.GetNumber());
}

//ще інші методи
void Person::Print()
{
	cout << " Name: " << name << endl;
	cout << " Age: " << age << endl;
	cout << " Gender: " << gender << endl;
	cout << " Number: " << number << endl;
}

//деструктор
Person::~Person()
{
	if (name != nullptr)
	{
		delete[]name;
		name = nullptr;
	}

	if (gender != nullptr)
	{
		delete[]gender;
		gender = nullptr;
	}
}