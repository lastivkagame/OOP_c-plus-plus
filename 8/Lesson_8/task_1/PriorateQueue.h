#pragma once
#include "iostream"
using namespace std;
class PriorateQueue
{
private:
	int * wait;
	int * priorateWaiters;
	int MaxQueueLength;
	int CurrentQueueLength;
public:
	PriorateQueue(int maxQueue);
	~PriorateQueue();
	void enqueue(int el, int priv);
	int dequeue();
	bool isEmpty()const;
	bool isFull()const;
	int getCount()const;
	void show()const;
	void clear();
};

