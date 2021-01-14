#pragma once
#include "iostream"
using namespace std;

template <typename T>
class PriorateQueue
{
private:
	T* wait;
	size_t* priorateWaiters;
	size_t MaxQueueLength;
	size_t CurrentQueueLength;
public:
	PriorateQueue(size_t maxQueue);
	PriorateQueue(const PriorateQueue& obj);    //к-тор копій

	void enqueue(T el, size_t priv);  //додає елемнт 
	size_t dequeue();   // видаляє елемнт з найбільшим приорітетом

	bool isEmpty()const;
	bool isFull()const;

	size_t getCount()const;
	void show()const;   // вивід
	void clear();       //видаляє всю чергу

	T& operator=(PriorateQueue<T>& other);   //оператор =

	friend ostream& operator<<(ostream& out, const PriorateQueue<T>& obj);   // вивід

	~PriorateQueue();
};

template<typename T>
inline PriorateQueue<T>::PriorateQueue(size_t maxQueue)
{
	CurrentQueueLength = 0;
	MaxQueueLength = maxQueue;
	wait = new T[maxQueue];
	priorateWaiters = new size_t[maxQueue];
}

template<typename T>
inline void PriorateQueue<T>::enqueue(T el, size_t priv)
{
	if (!isFull())
	{
		size_t temp = 0;
		for (size_t i = 0; i < CurrentQueueLength; i++)
		{
			if (priv > priorateWaiters[i])
			{
				temp = i;
			}
		}

		size_t temp2;

		for (size_t i = temp; i < CurrentQueueLength; i++)
		{
			temp2 = priorateWaiters[i];
			priorateWaiters[i] = temp2;
		}

		priorateWaiters[CurrentQueueLength] = priv;
		wait[CurrentQueueLength++] = el;
	}
}

template<typename T>
inline size_t PriorateQueue<T>::dequeue()
{
	if (!isEmpty())
	{
		size_t max = priorateWaiters[0];
		size_t v = 0;

		for (size_t i = 0; i < CurrentQueueLength; i++)
		{
			if (max < priorateWaiters[i])
			{
				max = priorateWaiters[i];
				v = i;
			}
		}

		size_t k = 0;

		for (size_t i = 0; i < CurrentQueueLength; i++)
		{
			if (i != v)
			{
				wait[k] = wait[i];
				priorateWaiters[k++] = priorateWaiters[i];
			}
		}
		CurrentQueueLength--;
		return max;
	}
	return INT_MIN;
}

template<typename T>
inline bool PriorateQueue<T>::isEmpty() const
{
	return CurrentQueueLength == 0;
}

template<typename T>
inline bool PriorateQueue<T>::isFull() const
{
	return CurrentQueueLength == MaxQueueLength;
}

template<typename T>
inline size_t PriorateQueue<T>::getCount() const
{
	return CurrentQueueLength;
}

template<typename T>
inline void PriorateQueue<T>::show() const
{
	if (!isEmpty()) {

		cout << "Wait:\t";
		for (int i = 0; i < CurrentQueueLength; i++)
		{
			cout << wait[i] << "\t";
		}
		cout << endl;
		cout << "Priorate: ";
		for (int i = 0; i < CurrentQueueLength; i++)
		{
			cout << priorateWaiters[i] << "\t";
		}
	}
	else
	{
		cout << "It's empty!\n";
	}
}

template<typename T>
inline void PriorateQueue<T>::clear()
{
	CurrentQueueLength = 0;
}

template<typename T>
inline PriorateQueue<T>::PriorateQueue(const PriorateQueue<T>& obj)
{
	this->MaxQueueLength = obj.MaxQueueLength;
	this->CurrentQueueLength = obj.CurrentQueueLength;

	this->wait = new T[MaxQueueLength];
	this->priorateWaiters = new T[MaxQueueLength];

	for (int i = 0; i < this->MaxQueueLength; i++)
	{
		this->priorateWaiters[i] = obj.priorateWaiterss[i];
		this->wait = obj.wait[i];
	}
}

template<typename T>
inline T& PriorateQueue<T>::operator=(PriorateQueue<T>& other)
{
	delete[] wait;
	delete[] priorateWaiters;

	MaxQueueLength = other.MaxQueueLength;
	CurrentQueueLength = other.CurrentQueueLength;

	this->wait = new T[MaxQueueLength];
	this->priorateWaiters = new T[MaxQueueLength];

	for (size_t i = 0; i < MaxQueueLength; i++)
	{
		MaxQueueLength[i] = other.MaxQueueLength[i];
		CurrentQueueLength[i] = other.CurrentQueueLength[i];
	}
	return *this;
}

template<typename T>
inline PriorateQueue<T>::~PriorateQueue()
{
	if (wait != nullptr)
	{
		delete[]wait;
		wait = nullptr;
	}

	if (priorateWaiters != nullptr)
	{
		delete[]priorateWaiters;
		priorateWaiters = nullptr;
	}
}

template<typename T>
ostream& operator<<(ostream& out, const PriorateQueue<T>& obj)
{
	obj.show();
	return out;
}