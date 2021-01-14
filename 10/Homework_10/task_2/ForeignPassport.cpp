#include "ForeignPassport.h"
#include <iostream>
using namespace std;

ForeignPassport::ForeignPassport()
{
	this->number = -1;
	this->digits = 1;
	visas = new Visa[digits];
}

ForeignPassport::ForeignPassport(string name, string surname, string patronymic, string sex, string adress, int day, int month, int year,
	int number, int digits, Visa* visas) :Passport(name, surname, patronymic, sex, adress, day, month, year)
{
	this->number = number;
	this->digits = digits;
	this->visas = new Visa[digits];

	for (int i = 0; i < digits; i++)
	{
		this->visas[i] = visas[i];
	}
}

ForeignPassport::ForeignPassport(ForeignPassport& obj)
{
	number = obj.number;
	digits = obj.digits;

	for (int i = 0; i < digits; i++)
	{
		visas[i] = obj.visas[i];
	}
}

int ForeignPassport::GetNumber() const
{
	return this->number;
}

int ForeignPassport::GetDigits() const
{
	return this->digits;
}

Visa* ForeignPassport::GetVisas() const
{
	return this->visas;
}

void ForeignPassport::addVisa(string country, int number, int digits)
{
	if (visas != nullptr)
	{
		Visa* temp = new Visa[this->digits + 1];

		Visa t(country, number, digits);

		for (int i = 0; i < this->digits; i++)
		{
			temp[i] = visas[i];
		}

		temp[this->digits] = t;

		delete[]visas;

		this->digits++;

		visas = new Visa[this->digits];

		for (int i = 0; i < this->digits; i++)
		{
			visas[i] = temp[i];
		}
	}
	else
	{
		Visa t(country, number, digits);
		this->digits = 1;
		visas = new Visa[this->digits];
		visas[0] = t;
	}
}

void ForeignPassport::Print() const
{
	Passport::Print();
	cout << " Number: " << number << endl;
	cout << " Digits: " << digits << endl;

	for (int i = 0; i < digits; i++)
	{
		visas[i].Print();
	}
}

ForeignPassport::~ForeignPassport()
{
	if (visas != nullptr)
	{
		delete[]visas;
		visas = nullptr;
	}
}