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
	Person(int age, string name, string sex);
	void Print()const;
	void PutInfo();
	int GetAge()const;
	string GetName()const;
	string GetSex()const;
};

class Student: public Person  //наслідує клас Person
{
private:
	string spec;
	int id;
	string group;
public:
	Student();
	Student(string spec, string group, int age, string name, string sex);
	Student(string spec, string group, Person&p);

	void PutInfo();
	int GetId()const;
	string GetSpec()const;
	string GetGroup()const;

	void Print()const;
	//Student: public Person();
	//~Student: public Person();
};

class Employee: public Person
{
protected:
	string placeWork;
	string position;
	double wage;
public:
	Employee();
	Employee(string placeWork, string position, double wage, int age, string name, string sex);
	Employee(string placeWork, string position, double wage, Person&p);

	string GetPlaceWork()const;
	string GetPosition()const;
	double GetWage()const;
	void PutInfo();
	void Print()const;
};

class Manager :public Employee
{
private:
	int count;
	Employee* arr;
public:
	Manager();
	Manager(int count, Employee*arr, string placeWork, string position, double wage, int age, string name, string sex);
	Manager(int count, Employee*arr);
	Manager(int count, Employee&p);

	void RemoveEmpl(int el);
	void AddEmpl(int el);

	void Print()const;
	Employee* GetArr()const;
	int GetCount()const;

	~Manager();
};