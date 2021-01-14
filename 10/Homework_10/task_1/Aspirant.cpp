#include "Aspirant.h"

Aspirant::Aspirant() :Student()
{
	name = "none";
	date = "00.00.00";
};

Aspirant::Aspirant(string name, string date, string initials, int id, string faculty, string specialty) :Student(initials, id, faculty, specialty)
{
	this->name = name;
	this->date = date;
}

void Aspirant::SetName(string name)
{
	this->name = name;
}

string Aspirant::GetName() const
{
	return this->name;
}

string Aspirant::GetDate() const
{
	return this->date;
}

void Aspirant::Print()
{
	Student::Print();
	cout << " Name of candidate work: " << name << endl;
	cout << " Date: " << date << endl;
}