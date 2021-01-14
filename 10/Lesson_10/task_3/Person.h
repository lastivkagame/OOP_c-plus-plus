#pragma once
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Person
{
private:
	int age;
	string name;
	string sex;
public:
	Person();
	Person(string name, int age, string sex);
	void Print()const;
	void PutInfo();
	int GetAge()const;
	string GetName()const;
	string GetSex()const;
};