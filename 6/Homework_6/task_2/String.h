#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	int size;
	char* str;
	static int count;  //статичне приватне поле – лічильник існуючих на даний момент екземплярів класу
public:
	//статичний метод доступу до count
	static int GetCount();

	//конструкторu
	String();   //к-тор по замовчуванню
	String(int size);   // к-тор з розміром(від кор.)
	String(int size, const char* str);   // к-тор з розміром + рядок
	String(String& obj);   //к-тор копій
	String(String&& obj); //конструктор копій з move

	//сеттери
	void SetSize(int size);
	void SetStr(const char* str);

	//геттери
	int GetSize()const;
	char* GetStr() const;

	//інше
	void print()const;
	String& operator=(const String& obj);
	String& operator=(String&& obj);  //операто = з переміщенням
	String operator*(const String& right);  //результатом перетину рядків "Microsoft" та "Windows" буде рядок "ioso".
	String operator+(const String& right);  //додає 2 рядки
	friend String operator+(const char* right, const String& left);
	String& operator++(int);  //результатом ++ для рядка "Abcd" буде "Bcde"
	String& operator++();

	//оператор порівняння
	bool operator<(const String& right);
	bool operator>(const String& right);

	bool operator>=(const String& right);
	bool operator<=(const String& right);

	bool operator==(const String& right);
	bool operator!=(const String& right);

	//other
	String operator!();  //здійснити реверс рядка. Наприклад, результатом реверсу String'а "Windows" буде новий String "swodniW".
	char& operator[](int index) const;
	String operator()(int start, int end);
	String operator()(int start);
	String operator()();

	String& operator+=(const String& right);

	//операції для введення та виведення рядка
	friend ostream& operator<<(ostream& os, const String& right);
	friend istream& operator>>(istream& is, String& right);

};