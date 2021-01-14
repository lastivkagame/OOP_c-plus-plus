#include "Person.h"

Person::Person() :Person("empty",0, "undefined")
{
	//cout << "default C-tor Person\n";
};

Person::Person(string name, int age, string sex)
{
	//cout << "Overload c-tor person\n";
	this->age = age;
	this->name = name;
	this->sex = sex;
}

void Person::Print() const
{
	cout << " Person: \n";
	cout << " Age: " << age << endl;
	cout << " Name: " << name << endl;
	cout << " Sex: " << sex << endl;
}

void Person::PutInfo()
{
	cout << "Enter name: ";
	cin >> name;

	cout << "Enter age: ";
	cin >> age;

	cout << "Enter sex: ";
	cin >> sex;
}

int Person::GetAge() const
{
	return age;
}

string Person::GetName() const
{
	return name;
}

string Person::GetSex() const
{
	return sex;
}