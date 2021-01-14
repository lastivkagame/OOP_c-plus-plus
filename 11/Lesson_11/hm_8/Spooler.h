#pragma once
#include <string>
#include <iostream>
#include "Document.h"
using namespace std;

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

	void enqueue(string el, int priv, Document doc);
	void dequeue(string el, int priv, Document doc);
	void Del();

	bool isEmpty()const;
	bool isFull()const;

	int getCount()const;

	Document* getDocuments()const;
	Document getDocument(int el)const;

	void show()const;
	void clear();
};