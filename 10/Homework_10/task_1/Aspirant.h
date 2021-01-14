#pragma once
#include "Student.h"
#include <string>

class Aspirant : public Student
{
private:
	string name;  // - кандидатской работы
	string date;
public:
	Aspirant();
	Aspirant(string name, string date, string initials, int id, string faculty, string specialty);

	void SetName(string name);
	string GetName()const;
	string GetDate()const;

	void Print();
};

