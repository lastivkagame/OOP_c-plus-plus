#pragma once
#include <iostream>
using namespace std;

class list
{
	class Node 
	{
	public:
		int data;
		Node *pNext;

		Node() = default;
		Node(int el) :data(el), pNext(nullptr) {};
	};

	Node * pHead;
	Node *pTail;

public:
	list();
	~list();
	void Print()const;

	void AddHead(int el);
	void AddTail(int el);
	void InsertAfter(int after, int what);

	void DelElement(int el);
	bool SearchElement(int el)const;
	void Clear();
	void DelHead();
	void DelTail();
};

