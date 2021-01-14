#pragma once

#include <iostream>
using namespace std;

class String {
private:
	int size;
	char* someString;
public:

	//конструктори
	String();
	String(int size);
	String(int size, const char* someString);

	//деструктор
	~String();

	//функція виводу
	void print()const;

	//сеттери і гетери
	char* GetSomeString()const;
	void SetSomeString(const char* someString);

	int GetSize()const;
	void SetSize(int size);

	//конструктор копій(хай буде)
	String(const String& obj);

};