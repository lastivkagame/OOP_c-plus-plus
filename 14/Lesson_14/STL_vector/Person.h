#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int age;
	float mark;
public:
	Student(string name, int age, float mark);
	friend ostream&operator<<(ostream&out, const Student &st);
	bool operator<(Student&st);
	bool operator>(Student&st);

	string GetNAme()const 
	{
		this->name;
	}

	int GetAge()const
	{
		return this->age;
	}

	float GetMark()const
	{
		return this->mark;
	}

	~Student();
};

