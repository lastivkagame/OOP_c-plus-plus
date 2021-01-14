#pragma once
#include "Document.h"

class Spooler
{
private:
	string* wait;
	int* priorateWaiters;
	int MaxQueueLength;
	int CurrentQueueLength;
	Document* documents;
public:
	Spooler();
	Spooler(const Spooler & obj);
	Spooler(int maxQueue);
	~Spooler();

	void enqueue(string el, int priv, Document doc);
	void dequeue(string el, int priv, Document doc);
	void Del();
	bool isEmpty()const;
	bool isFull()const;
	int getCount()const;
	Document* getDocuments()const;
	Document getDocument(int el)const;
	void show()const;
	void showEl(int index)const;
	void clear();
};