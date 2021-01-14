#pragma once
class Queue
{
private: 
	int * wait;
	int MaxQueueLength;
	int CurrentQueueLength;
public:
	Queue(int size);
	~Queue();
	void enqueue(int el);
	int dequeue();
	bool isEmpty()const;
	bool isFull()const;
	int getCount()const;
	void show()const;
	void clear();
};

