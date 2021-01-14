#include "PriorateQueue.h"

PriorateQueue::PriorateQueue(int maxQueue)
{
	wait = new int[maxQueue];
	CurrentQueueLength = 0;
	MaxQueueLength = maxQueue;

	priorateWaiters = new int[maxQueue];
}

PriorateQueue::~PriorateQueue()
{
	if (wait != nullptr) {
		delete[]wait;
		wait = nullptr;
	}

	if (priorateWaiters != nullptr) {
		delete[]priorateWaiters;
		priorateWaiters = nullptr;
	}
}

void PriorateQueue::enqueue(int el, int priv)
{
	if (!isFull())
	{
		int temp = 0;
		for (int i = 0; i < CurrentQueueLength; i++)
		{
			if (priv > priorateWaiters[i])
			{
				temp = i;

			}
		}


		int temp2;

		for (int i = temp; i < CurrentQueueLength; i++)
		{
			temp2 = priorateWaiters[i];
			priorateWaiters[i] = temp2;
		}

		priorateWaiters[CurrentQueueLength] = priv;
		wait[CurrentQueueLength++] = el;

	}
}

int PriorateQueue::dequeue()
{
	if (!isEmpty())
	{
		int max = priorateWaiters[0];
		int v = 0;

		for (int i = 0; i < CurrentQueueLength; i++)
		{
			if (max < priorateWaiters[i])
			{
				max = priorateWaiters[i];
				v = i;
			}
		}

		int k = 0;

		for (int i = 0; i < CurrentQueueLength; i++)
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

bool PriorateQueue::isEmpty() const
{
	return CurrentQueueLength == 0;
}

bool PriorateQueue::isFull() const
{
	return CurrentQueueLength == MaxQueueLength;
}

int PriorateQueue::getCount() const
{
	return CurrentQueueLength;
}

void PriorateQueue::show() const
{
	if (!isEmpty()) {
		for (int i = 0; i < CurrentQueueLength; i++)
		{
			cout << wait[i] << "\t";
		}

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

void PriorateQueue::clear()
{
	CurrentQueueLength = 0;
}

