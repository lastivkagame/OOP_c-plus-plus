#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student
{
private:
	string initials;  //�������� � ��'� ��������
	int id;
	string faculty;
	string specialty;
public:
	//������������
	Student();
	Student(string initials, int id, string faculty, string specialty);
	Student(Student& obj);   // c-tor copy 
	Student(Student&& obj);  // c-tor copy with move

	Student& operator=(Student&& obj);
	Student& operator=(const Student& obj);

	//�������
	void SetInitials(string initials);
	void SetFaculty(string faculty);
	void SetSpecialty(string specialty);

	//�������
	string GetFaculty()const;
	string GetSpecialty()const;
	string GetInitials()const;
	int GetId()const;

	//other
	void Print()const;
};

