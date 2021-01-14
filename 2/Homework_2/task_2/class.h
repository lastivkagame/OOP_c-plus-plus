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
	//������������
	Person() :Person("none", 0, "unknown", 0) {};
	Person(const char* name, int age, const char* gender, int number);

	//�������
	void SetName(const char* name);
	void SetAge(int age);
	void SetGender(const char* gender);
	void SetNumber(int number);

	//�������
	char* GetName();
	int GetAge();
	char* GetGender();
	int GetNumber();

	//����������� ����
	Person(Person& obj);

	//�� ���� ������
	void Print();

	//����������
	~Person();
};