#pragma once
#include <string>
using namespace std;

class Visa
{
private:
	string country;
	int number;
	int digits;
public:
	Visa();
	Visa(string country, int number, int digits);

	string GetCountry()const;
	int GetNumber()const;
	int GetDigits()const;

	Visa& operator=(const Visa& obj);

	void Print()const;
};