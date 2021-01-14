#include "class.h"

//конструктори
String::String() :String(80, "it can be 80 charters") {}

String::String(int size) : String(size, "none") {}

String::String(int size, const char* someString) 
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
	cout << " " << someString << endl;
	cout << " Max size: " << size << endl;
}

//сеттери і гетери
char* String::GetSomeString()const
{
	return this->someString;
}

void String::SetSomeString(const char* someString)
{
	this->someString = new char[size + 1];
	strcpy_s(this->someString, strlen(someString) + 1, someString);
}

int String:: GetSize()const 
{
	return size;
}

void String::SetSize(int size)
{
	this->size = size;
}


String::String(const String& obj)
{
	this->SetSize(obj.GetSize());
	this->SetSomeString(obj.GetSomeString());
}