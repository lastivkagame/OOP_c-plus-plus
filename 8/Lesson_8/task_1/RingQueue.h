#pragma once
class RingQueue
{
private:
	int * wait;
	int MaxQueueLength;
	int CurrentQueueLength;
public:
	RingQueue(int size);
	~RingQueue();
	void enqueue(int el);
	int dequeue();
	bool isEmpty()const;
	bool isFull()const;
	int getCount()const;
	void show()const;
	void clear();
};

