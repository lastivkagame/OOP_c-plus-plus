#pragma once
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
class Array
{
private:
	int size;
	T*arr;
	static int count;
public:
	Array();
	Array(int size);
	void Show()const;
	void Fill();

	int GetSize()const;
	T*GetArr()const;
	T&operator[](int index);
	T Max()const;

	template <typename T>
	friend ostream& operator<<(ostream& os, const Array<T>& obj);
	template <typename T>
	friend istream& operator>>(istream& is, Array<T>& obj);

	static int GetCount() 
	{
		return count;
	}
};

template <typename T>
int Array<T>::count = 0;

template<typename T>
Array<T>::Array()
{
	size = 5;
	arr = new T[size];
}

template<typename T>
Array<T>::Array(int size)
{
	arr = new T[size];
	this->size = size;
}

template<typename T>
void Array<T>::Show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<typename T>
void Array<T>::Fill()
{
	for (int i = 0; i < size; i++)
	{
		//arr[i] = rand() % 20; //неуніверсальний спосіб заповнення!
		cin >> arr[i];
	}
	cout << endl;
}

template<typename T>
int Array<T>::GetSize() const
{
	return size;
}

template<typename T>
T * Array<T>::GetArr() const
{
	return arr;
}

template<typename T>
T & Array<T>::operator[](int index)
{
	static T bad = T();
	if (index >= 0 && index < size)
	{
		return arr[index];
	}
	return bad;
}

template<typename T>
T Array<T>::Max() const
{
	T max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

template<typename T>
ostream & operator<<(ostream & os, const Array<T>& obj)
{
	obj.Show();
	return os;
}

template<typename T>
istream & operator>>(istream & is, Array<T>& obj)
{
	for (int i = 0; i < obj.GetSize(); i++)
	{
		is >> obj.arr[i];
	}
	return is;
}

template<>
const char* Array<const char*>::Max()const
{
	int indMax = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i] , arr[indMax]) > 0)
		{
			indMax = i;
		}
	}
	return arr[indMax];
}
