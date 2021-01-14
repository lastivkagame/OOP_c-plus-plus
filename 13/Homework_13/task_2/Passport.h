#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace PASSPORT
{
	class Passport
	{
	private:
		string name;
		string surname;
		string patronymic;
		string sex;
		string adress;
		int day;
		int month;
		int year;
	public:
		Passport();
		Passport(string name, string surname, string patronymic, string sex, string adress, int day, int month, int year);

		void SetAdress(string adress);

		string GetName()const;
		string GetSurname()const;
		string GetPatronymic()const;
		string GetSex()const;
		string GetAdress()const;
		int GetDay()const;
		int GetMonth()const;
		int GetYear()const;

		void Print()const;
	};
}

using namespace PASSPORT;