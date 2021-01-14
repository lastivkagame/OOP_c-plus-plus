#include "class.h"

//������������
String::String()
{
	this->size = 80;
	SetSomeString("none");
}

String::String(int size) :String("none")
{
	this->size = size;
}


String::String(const char* someString, int size)
{
	this->size = size;
	SetSomeString(someString);
}

//����������
String::~String()
{
	if (someString != nullptr)
	{
		delete[]someString;
		someString = nullptr;
	}
}

//������� ������
void String::print()const
{
	cout << someString << endl;
}

//������ � �����
char* String::GetSomeString()const
{
	return this->someString;
}

void String::SetSomeString(const char* someString)
{
	this->someString = new char[size];
	strcpy_s(this->someString, strlen(someString) + 1, someString);
}

String::String(const String& obj)
{
	this->SetSomeString(obj.GetSomeString());
}