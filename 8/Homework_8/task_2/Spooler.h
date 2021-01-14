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
	Spooler(int maxQueue);
	~Spooler();

	Spooler(const Spooler& obj);
	Spooler& operator=(const Spooler& obj);
	Spooler& operator=(Spooler&& obj);
	Spooler(Spooler&& obj);

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

