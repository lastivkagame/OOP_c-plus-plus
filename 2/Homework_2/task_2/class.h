#pragma once

#include <iostream>
using namespace std;

class Person {
private:
	char* name;
	int age;
	char* gender;
	int number;
public:
	//конструктори
	Person() :Person("none", 0, "unknown", 0) {};
	Person(const char* name, int age, const char* gender, int number);

	//сеттери
	void SetName(const char* name);
	void SetAge(int age);
	void SetGender(const char* gender);
	void SetNumber(int number);

	//геттери
	char* GetName();
	int GetAge();
	char* GetGender();
	int GetNumber();

	//конструктор копій
	Person(Person& obj);

	//ще інші методи
	void Print();

	//деструктор
	~Person();
};