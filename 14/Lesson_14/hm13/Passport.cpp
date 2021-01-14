#include "Passport.h"

namespace PASSPORT
{

#include <iostream>
#include <Windows.h>

	Passport::Passport() :Passport("name", "surname", "patronymic", "sex", "adress", 0, 0, 0) {};

	Passport::Passport(string name, string surname, string patronymic, string sex, string adress, int day, int month, int year)
		:name(name), surname(surname), patronymic(patronymic), sex(sex), adress(adress), day(day), month(month), year(year) {}

	void Passport::SetAdress(string adress)
	{
		this->adress = adress;
	}

	string Passport::GetName() const
	{
		return this->name;
	}

	string Passport::GetSurname() const
	{
		return this->surname;
	}

	string Passport::GetPatronymic() const
	{
		return this->patronymic;
	}

	string Passport::GetSex() const
	{
		return this->sex;
	}

	string Passport::GetAdress() const
	{
		return this->adress;
	}

	int Passport::GetDay() const
	{
		return this->day;
	}

	int Passport::GetMonth() const
	{
		return month;
	}

	int Passport::GetYear() const
	{
		return this->year;
	}

	void Passport::Print() const
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Patronymic: " << patronymic << endl;
		cout << " Sex: " << sex << endl;
		cout << " Adress: " << adress << endl;

		cout << " Date of birth: " << day << "." << month << "." << year << endl;
		cout << endl;
	};
}