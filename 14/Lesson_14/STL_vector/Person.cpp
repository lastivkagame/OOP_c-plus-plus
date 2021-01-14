#include "Person.h"

ostream & operator<<(ostream & out, const Student & st)
{
	out << "Name: " << st.name << endl;
	out << "Age: " << st.age << endl;
	out << "Mark: " << st.mark << endl;
	return out;

}

Student::Student(string name = "none", int age = 0, float mark = 0) :name(name), age(age), mark(mark) {}

bool Student::operator<(Student & st)
{
	//return this->name.compare(st.name);  //1 - true
	return this->name < st.name;  //1 - true
}

bool Student::operator>(Student & st)
{
	return	this->name > st.name;
}

Student::~Student()
{

};
