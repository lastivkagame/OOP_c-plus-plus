#include "Visa.h"

namespace VISA
{
	Visa::Visa() :Visa("none", -1, 0) {};

	Visa::Visa(string country, int number, int digits) :country(country), number(number), digits(digits) {};

	string Visa::GetCountry() const
	{
		return this->country;
	}

	int Visa::GetNumber() const
	{
		return this->number;
	}

	int Visa::GetDigits() const
	{
		return this->digits;
	}

	Visa& Visa::operator=(const Visa& obj)
	{
		if (this == &obj)
		{
			return *this;
		}

		this->country = obj.country;
		this->number = obj.number;
		this->digits = obj.digits;

		return *this;

	}

	void Visa::Print() const
	{
		cout << "  --- Visa ---  \n";
		cout << " Country: " << country << endl;
		cout << " Number: " << number << endl;
		cout << " Digits: " << digits << endl;
		cout << endl;
	};
}