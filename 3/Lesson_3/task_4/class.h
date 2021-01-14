#pragma once

#pragma once

#include <iostream>
using namespace std;

class String {
private:
	char* someString;
	int size;
public:

	//конструктори
	String();
	String(int size);

	String(const char* someString = "none", int size = 20);

	//деструктор
	~String();

	//функція виводу
	void print()const;

	//сеттер і гетер
	char* GetSomeString()const;
	void SetSomeString(const char* someString);

	//конструктор копій(хай буде)
	String(const String& obj);

};
