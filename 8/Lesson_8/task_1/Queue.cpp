#include "Queue.h"
#include "iostream"
using namespace std;


Queue::Queue(int size)
{
	wait = new int[size];
	CurrentQueueLength = 0;
	MaxQueueLength = size;
}

Queue::~Queue()
{
	if (wait != nullptr) {
		delete[]wait;
		wait = nullptr;
	}
}

void Queue::enqueue(int el)
{
	if (!isFull())
	{
		wait[CurrentQueueLength++] = el;
	}
}

int Queue::dequeue()
{
	if (!isEmpty())
	{
		int temp = wait[0];

		for (int i = 0; i < CurrentQueueLength; i++)
		{
			wait[i] = wait[i + 1];
		}


		CurrentQueueLength--;

		return temp;
	}
	
	return INT_MIN;
}

bool Queue::isEmpty() const
{
	return CurrentQueueLength == 0;
}

bool Queue::isFull() const
{
	return CurrentQueueLength == MaxQueueLength;
}

int Queue::getCount() const
{
	return CurrentQueueLength;
}

void Queue::show() const
{
	if (!isEmpty()) {
		for (int i = 0; i < CurrentQueueLength; i++) {
			cout << wait[i] << "\t";
		}
	}
	else 
	{
		cout << "It's empty!\n";
	}
}

void Queue::clear()
{
	CurrentQueueLength = 0;
}
