#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	int size;
	char* str;
	static int count;
public:
	//статичний метод доступу
	static int GetCount();

	//конструкторu
	String();
	String(int size);
	String(int size, const char* str);
	String(String& obj);

	//сеттери
	void SetSize(int size);
	void SetStr(const char* str);

	//геттери
	int GetSize()const;
	char* GetStr()const;

	//інше
	void print()const;
	String& operator=(const String& obj);

	String& operator*(const String& right);

	String operator+(const String& right);
	friend String& operator+(const char* right, const String& left);
	String  operator++(int);
	String  operator++();

	//оператор порівняння
	bool operator<(const String& right);
	bool operator>(const String& right);

	bool operator>=(const String& right);
	bool operator<=(const String& right);

	bool operator==(const String& right);
	bool operator!=(const String& right);

	void operator!();

	char& operator[](int index);

	String operator()(int start, int end);
	String operator()(int start);
	String operator()();

	void operator+=(const String& right);
};

