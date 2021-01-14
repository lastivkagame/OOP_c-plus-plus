#include "Student.h"

//������������
Student::Student() :Student("none", -999998, "none", "none") {};

Student::Student(string initials, int id, string faculty, string specialty) :initials(initials), id(id), faculty(faculty), specialty(specialty) {}

Student::Student(Student& obj)   // c-tor copy 
{
	this->initials = obj.GetInitials();
	this->faculty = obj.GetFaculty();
	this->specialty = obj.GetSpecialty();
	this->id = obj.GetId();
}

Student::Student(Student&& obj)  // c-tor copy with move
{
	*this = move(obj);
}

Student& Student::operator=(const Student& obj)   //�������� = 
{
	if (this == &obj)
	{
		return *this;
	}

	this->initials = obj.GetInitials();
	this->faculty = obj.GetFaculty();
	this->specialty = obj.GetSpecialty();
	this->id = obj.GetId();

	return *this;
}

Student& Student::operator=(Student&& obj)  //�������� = � move
{
	this->initials = obj.GetInitials();
	this->faculty = obj.GetFaculty();
	this->specialty = obj.GetSpecialty();
	this->id = obj.GetId();

	return *this;
}

//�������
void Student::SetInitials(string initials)
{
	this->initials = initials;
}

void Student::SetFaculty(string faculty)
{
	this->faculty = faculty;
}

void Student::SetSpecialty(string specialty)
{
	this->specialty = specialty;
}

//�������
string Student::GetFaculty()const
{
	return faculty;
}

string Student::GetSpecialty()const
{
	return specialty;
}

string Student::GetInitials()const
{
	return initials;
}

int Student::GetId()const
{
	return id;
}

//other
void Student::Print()const
{
	cout << "  --- Student ---\n ";
	cout << " Id: " << id << endl;
	cout << " Initials: " << initials << endl;
	cout << " Faculty: " << faculty << endl;
	cout << " Specialty: " << specialty << endl;
}
