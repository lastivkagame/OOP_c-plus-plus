#pragma once
#include<iostream>
#include<ctime>
using namespace std;


class Array
{
	//const int SIZE;
	int arr[10];
	int size;
public:
	Array() :arr{0}
	{
		for (int i = 0; i < 10; i++)
		{
			arr[i] = rand() % 20;
		}
		size = 100;
	}

	void print()const 
	{
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int GetSize()const
	{
		return size;
	}

	Array(const Array& obj) 
	{
		for (int i = 0; i < 10; i++) 
		{
			arr[i] = obj.GetArray()[i];
		}
		this->size = obj.GetSize();
	}

	const int* GetArray() const
	{
		return arr;
	}

	

	int &operator[](int index)  //int& - важливо для присвоєння!
	{
		return arr[index];
	}

	Array& operator=(const Array& obj) 
	{
		if (this == &obj) //коли зліва і справа той самий обєкт
		{
			return *this;
		}

		Array temp; //c-tor copy

		for (int i = 0; i < 10; i++)
		{
			arr[i] = obj.GetArray()[i];
		}

		//*this = temp;
		return *this;
	}

	void SetSize(int num)
	{
		size = num;
	}

	Array& operator++() //префіксна форма
	{
		for (int i = 0; i < 10; i++) 
		{
			arr[i]++;
		}

		++size;
		return *this;

	}

	Array& operator--() //префіксна форма
	{
		for (int i = 0; i < 10; i++)
		{
			arr[i]--;
		}


		--size;
		return *this;

	}

	Array& operator++(int) //постфіксна форма, параметр int просто прапорець можна не ініціалізувати
	{
		Array temp = *this;

		for (int i = 0; i < 10; i++) 
		{
			arr[i]++;
		}

		temp.SetSize(this->size);
		size++;
		return temp;
	}

	Array& operator--(int) //постфіксна форма, параметр int просто прапорець можна не ініціалізувати
	{
		Array temp = *this;

		for (int i = 0; i < 10; i++)
		{
			arr[i]--;
		}


		temp.SetSize(this->size--);
		//size--;
		return temp;
	}
};

