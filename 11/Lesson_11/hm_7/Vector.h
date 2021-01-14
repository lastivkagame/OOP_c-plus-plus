#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Vector
{
private:
	T* buffer = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	static T errorFront;
public:
	//конструктори
	Vector()
	{
		this->size = 0;
		this->capacity = 0;
		this->buffer = new T[this->size];
	}

	Vector(size_t size)
	{
		this->capacity = size + 3;
		this->size = size;
		this->buffer = new T[size]{ 0 };
	}

	Vector(size_t size, T value)
	{
		this->capacity = size * 2;
		this->size = size;
		buffer = new T[size];

		for (int i = 0; i < size; i++)
		{
			buffer[i] = value;
		}
	}

	//к-тор копій
	Vector(const Vector& obj)
	{
		this->size = obj.size;
		this->capacity = obj.capacity;
		this->buffer = new T[this->size + 1];

		for (int i = 0; i < this->size; i++)
		{
			this->buffer[i] = obj.buffer[i];
		}
	}

	//Метод зміни capacity(reserve(size_t newCapacity)дані не втрачаються при
	//збільшення capacity, не дозволяти зменшувати capacity
	void Reserv(size_t newCapacity)
	{
		if (newCapacity <= capacity)
		{
			capacity = +size;
		}

		T* result = new T[newCapacity];

		for (int i = 0; i < size; i++)
		{
			result[i] = buffer[i];
		}

		delete[] buffer;
		buffer = new T[newCapacity];
		capacity = newCapacity;

		for (int i = 0; i < capacity; i++)
		{
			buffer[i] = result[i];
		}
	}

	//Метод зміни фактичної довжини масиву void resize(size_t newSize, int value)
	void Resize(size_t newSize, const T& value = 0)
	{
		if (newSize >= size)   // !!!
		{
			Reserv(newSize * 2);
		}

		for (size_t i = 0; i < newSize; i++)
		{
			if (i == size)
			{
				buffer[i] = value;
			}
		}

		size = newSize;
	}

	//Метод додавання нового елемента(pushBack(T elem)) у кінець масиву
	void PushBack(const T& elem)
	{
		Resize(size + 1, elem);
	}

	void Print() const
	{
		for (int i = 0; i < size; ++i)
		{
			cout << buffer[i] << "\t";
		}
		cout << endl;
	}

	//геттери
	size_t GetCapacity() const
	{
		return capacity;
	}

	size_t GetSize() const
	{
		return size;
	}

	size_t GetBuffer() const
	{
		return buffer;
	}

	//метод що перевіряє чи пустий вектор
	bool Empty()
	{
		if (this->size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Метод встановлення(зміни) елемента за індексом
	void SetValue(size_t index, T value)
	{
		if (index > 0 && index < size)
		{
			for (int i = 0; i < size; i++)
			{
				if (index == i)
				{
					buffer[i] = value;
				}
			}
		}
	}

	//Метод доступу(читання) елемента за індексом
	T GetValue(size_t index)
	{
		for (int i = 0; i < size; i++)
		{
			if (index == i)
			{
				return buffer[i];
			}
		}
	}

	//Метод вилучення останнього елемента(popBack()), перевіряти чи можна вилучити
	void PopBack()
	{
		if (GetSize() > 0)
		{
			this->size = GetSize() - 1;
		}
	}

	//Метод, що повертає посилання на перший елемент вектору T & front(), якщо
	//вектор пустий повертати посилання на деяку статичну локальну змінну методу
	T& GetFront()
	{
		T static errorFront = 0;

		if (Empty())
		{
			return errorFront;
		}
		else
		{
			return buffer[0];
		}
	}

	//Метод, що повертає посилання на останній елемент вектору T & back(), якщо
	//вектор пустий повертати посилання на деяку статичну локальну змінну методу
	T& GetBack()
	{
		T static errorFront = 0;

		if (Empty())
		{
			return errorFront;
		}
		else
		{
			return buffer[size - 1];
		}
	}

	//Метод вставки нового елемента за вказаним індексом(валідувати індекс)
	void SetNewValue(size_t index, const T& value)
	{
		index--;

		//валідуймо індекс
		if (index <= 0)
		{
			index = 0;
		}

		if (index >= size)
		{
			index = size;
		}

		Resize(size + 1, value);

		T* temp = new T[size];

		for (int i = 0; i < size; i++)
		{
			temp[i] = buffer[i];
		}

		for (int i = index; i < size - 1; i++)
		{
			buffer[i + 1] = temp[i];
		}

		buffer[index] = value;
	}

	//Метод вилучення елемента за індексом(валідувати індекс)
	void DeleteValue(size_t index)
	{
		index--;

		if (index <= 0)
		{
			index = 0;
		}

		if (index >= size)
		{
			index = size;
		}

		for (int i = index; i < size; i++)
		{
			buffer[i] = buffer[i + 1];
		}

		this->size = GetSize() - 1;
	}

	//Метод очистки вектору(clear())
	void Clear()
	{
		Resize(0, 0);
	}

	//  інше
	//(індиксатор)
	T& operator [](int index)
	{
		T static errorFront = 0;
		if (index - 1 >= 0 && index - 1 < size)
		{
			return this->buffer[index - 1];
		}
		else
		{
			return errorFront;
		}
	}

	//оператор =
	T& operator=(T& other)
	{
		delete[] this->buffer;
		this->size = other.size;

		this->buffer = new T[other.size];
		this->capacity = other.capacity;

		for (int i = 0; i < size; i++)
		{
			this->buffer[i] = other.buffer[i];
		}

		return *this;
	}

	//ввід і вивід
	friend ostream& operator<<(ostream& out, const Vector<T>& obj)
	{
		obj.Print();
		return out;
	}

	friend istream& operator>>(istream& in, Vector<T>& other)
	{
		for (int i = 0; i < size; ++i)
		{
			cout << "Input element # " << i << " : ";
			in >> other.buffer[i];
		}
		return in;
	}

	//деструктор
	~Vector()
	{
		if (buffer != nullptr)
		{
			delete[] buffer;
			buffer = nullptr;
		}
	}
};
