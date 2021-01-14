#include "RingQueue.h"
#include "iostream"
using namespace std;

RingQueue::RingQueue(int size)
{
	wait = new int[size];
	CurrentQueueLength = 0;
	MaxQueueLength = size;
}

RingQueue::~RingQueue()
{
	if (wait != nullptr) {
		delete[]wait;
		wait = nullptr;
	}
}

void RingQueue::enqueue(int el)
{
	if (!isFull())
	{
		wait[CurrentQueueLength++] = el;
	}
}

int RingQueue::dequeue()
{
	if (!isEmpty())
	{
		int temp = wait[0];

		for (int i = 0; i < CurrentQueueLength-1; i++)
		{
			wait[i] = wait[i + 1];
		}
		wait[CurrentQueueLength-1] = temp;

		return temp;
	}

	return INT_MIN;
}

bool RingQueue::isEmpty() const
{
	return CurrentQueueLength == 0;
}

bool RingQueue::isFull() const
{
	return CurrentQueueLength == MaxQueueLength;
}

int RingQueue::getCount() const
{
	return CurrentQueueLength;
}

void RingQueue::show() const
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
void RingQueue::clear()
{
	CurrentQueueLength = 0;
}


