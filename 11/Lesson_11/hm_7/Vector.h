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
	//������������
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

	//�-��� ����
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

	//����� ���� capacity(reserve(size_t newCapacity)��� �� ����������� ���
	//��������� capacity, �� ��������� ���������� capacity
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

	//����� ���� �������� ������� ������ void resize(size_t newSize, int value)
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

	//����� ��������� ������ ��������(pushBack(T elem)) � ����� ������
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

	//�������
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

	//����� �� �������� �� ������ ������
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

	//����� ������������(����) �������� �� ��������
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

	//����� �������(�������) �������� �� ��������
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

	//����� ��������� ���������� ��������(popBack()), ��������� �� ����� ��������
	void PopBack()
	{
		if (GetSize() > 0)
		{
			this->size = GetSize() - 1;
		}
	}

	//�����, �� ������� ��������� �� ������ ������� ������� T & front(), ����
	//������ ������ ��������� ��������� �� ����� �������� �������� ����� ������
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

	//�����, �� ������� ��������� �� ������� ������� ������� T & back(), ����
	//������ ������ ��������� ��������� �� ����� �������� �������� ����� ������
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

	//����� ������� ������ �������� �� �������� ��������(��������� ������)
	void SetNewValue(size_t index, const T& value)
	{
		index--;

		//�������� ������
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

	//����� ��������� �������� �� ��������(��������� ������)
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

	//����� ������� �������(clear())
	void Clear()
	{
		Resize(0, 0);
	}

	//  ����
	//(����������)
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

	//�������� =
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

	//��� � ����
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

	//����������
	~Vector()
	{
		if (buffer != nullptr)
		{
			delete[] buffer;
			buffer = nullptr;
		}
	}
};
