#include "Array.h"

bool Array::validateIndex(int index)
{
	if (index >= 0 && index < size)
	{
		return true;
	}
	return false;
}

//конструктори
Array::Array() :Array(10) {}

Array::Array(int size) : size(size)
{
	arr = new int[size];
}

Array::Array(const Array & obj)
{
	SetArr(obj.GetArr(), obj.GetSize());
}

Array::Array(Array && obj)
{
	//pVal = obj.pVal; //забираємо силку собі(get reference of obj for myself(this))
	//obj.pVal = nullptr;
	cout << "move ctor works!!!\n";

	// якщо визначили оператор = з переміщенням то перші 2 рядки моджна замінити на
	*this = move(obj);
}

//сеттери і гетери
int Array::GetSize() const
{
	return size;
}

int * Array::GetArr() const
{
	return arr;
}

void Array::SetSize(int size)
{
	this->size = size;
	this->arr = new int[size];
}

void Array::SetArr(const int * arr, int size)
{
	SetSize(size);

	for (int i = 0; i < size; i++)
	{
		this->arr[i] = arr[i];
	}
}

//інше
void Array::print() const
{
	cout << " Size: " << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Array::fillArr()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Array::Add(int elem)
{
	//v - 1
	/*size++;
	int* tempArr = new int[size];

	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			tempArr[i] = elem;
		}
		else
		{
			tempArr[i] = arr[i];
		}
	}

	delete[]arr;
	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = tempArr[i];
	}*/

	//v - 2

	Array temp(size + 1);
	for (int i = 0; i < size; i++)
	{
		temp.GetArr()[i] = this->arr[i];
	}
	temp.GetArr()[size] = elem;

	this->SetArr(temp.GetArr(), temp.GetSize());
}

void Array::remove(int index)
{
	//v-1
	/*
	size--;
	int* tempArr = new int[size];

	for (int i = 0; i < size; i++)
	{
		if (i != index)
		{
			tempArr[i] = arr[i];
		}
	}

	delete[]arr;
	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = tempArr[i];
	}
	*/

	//v - 2
	if (!validateIndex(index))
	{
		return; //перервати роботу функції (як break)
	}

	Array temp(size - 1);
	for (int i = 0; i < temp.GetSize(); i++)
	{
		if (i < index)
		{
			temp.GetArr()[i] = this->arr[i];
		}
		else {
			temp.GetArr()[i] = this->arr[i + 1];
		}
	}
	*this = temp;
}

Array & Array::operator+(const Array& right)
{
	Array temp(this->size + right.GetSize());

	for (int i = 0; i < size; i++)
	{
		temp.GetArr()[i] = this->arr[i];
	}

	for (int i = size; i < (size + right.GetSize()); i++)
	{
		temp.GetArr()[i] = right.arr[i - size];
	}
	*this = temp;
	return *this;
}

Array Array::operator++(int)
{
	Array temp = *this;

	for (int i = 0; i < size; i++)
	{
		arr[i]++;
	}

	return temp;
}

Array & Array::operator=(Array && obj)
{
	cout << "operator = (&&) works\n";

	if (this == &obj)
	{
		return *this;
	}

	size = obj.GetSize();

	/*if (arr != nullptr)
	{
		delete[]arr;
	}*/
	arr = obj.arr;
	obj.arr = nullptr;

	return *this;
}

Array & Array::operator=(const Array & obj)
{
	if (this == &obj)
	{
		cout << "it was asigned itself!!!" << endl;
		return *this;
	}

	*arr = *obj.arr;
	cout << "operator = works!\n";
	return *this;
}

void Array::operator()(int a, int b)
{
	arr[a] = b;
}

int & Array::operator[](int index)
{
	if (validateIndex(index))
	{
		return arr[index];
	}

	//if (index >= 0 && index < size) 
	//{

	//}
	throw "index error"; //генеруємо помилку!
	//cerr << "index error" << endl; // показує текст на екран
}

//деструктор
Array::~Array()
{
	if (arr != nullptr)
	{
		delete[]arr;
		arr = nullptr;
	}
}

Array operator+(int el, const Array & left)
{
	Array temp(left.GetSize());
	for (int i = 0; i < temp.GetSize(); i++)
	{
		temp[i] = left.arr[i] + el;
	}
	return temp;
}

ostream & operator<<(ostream & os, const Array & right)
{
	//v-1
	//right.print();
	//return os;

	//v-2
	for (int i = 0; i < right.GetSize(); i++)
	{
		os << right.GetArr()[i] << "\t";
	}

	os << endl;
	return os;
}

istream & operator>>(istream & is, Array & right)
{
	for (int i = 0; i < right.GetSize(); i++)
	{
		is >> right[i];
	}
	return is;
}

