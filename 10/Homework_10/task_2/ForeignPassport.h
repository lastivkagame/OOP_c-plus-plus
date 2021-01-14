#pragma once
#include "Passport.h"
#include "Visa.h"

class ForeignPassport : Passport
{
private:
	int number;
	int digits;
	Visa* visas;
public:
	ForeignPassport();
	ForeignPassport(string name, string surname, string patronymic, string sex, string adress, int day, int month, int year,
		int number, int digits, Visa* visas);
	ForeignPassport(ForeignPassport& obj);

	int GetNumber()const;
	int GetDigits()const;
	Visa* GetVisas()const;

	void addVisa(string country, int number, int digits);  // додає до масиву віз ще одну

	void Print()const;

	~ForeignPassport();
};