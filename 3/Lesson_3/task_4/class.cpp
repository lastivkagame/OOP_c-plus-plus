#include "class.h"

//конструктори
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

//деструктор
String::~String()
{
	if (someString != nullptr)
	{
		delete[]someString;
		someString = nullptr;
	}
}

//функція виводу
void String::print()const
{
	cout << someString << endl;
}

//сеттер і гетер
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