#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Array
{
private:
	int size;
	int * arr;

	bool validateIndex(int index);
public:
	//конструктори
	Array();
	Array(int size);
	Array(const Array& obj);
	//Array() = default;  //просимо компілятор надати конструктор по замовчуванню
	//Array(const Array & obj) = delete;

	//сеттери і гетери
	int GetSize()const;
	int * GetArr()const;

	void SetSize(int size);
	void SetArr(const int * arr, int size);

	//інше
	void print()const;
	void fillArr();

	void Add(int elem);
	void remove(int index);

	Array & operator+(const Array& right);
	Array  operator++(int);
	Array&  operator=(const Array& obj);

	friend Array operator+(int el, const Array& left);

	friend ostream& operator <<(ostream& os, const Array &right);
	friend istream& operator >>(istream& is, Array &right);

	void operator()(int a, int b);

	int & operator[](int index);

	//деструктор
	~Array();
};

