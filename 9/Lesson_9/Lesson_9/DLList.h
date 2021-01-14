#pragma once
#include <iostream>
using namespace std;
class DLList  //DoubleLinkedList
{
	class Node
	{
	public:
		int data;
		Node *pPrev;
		Node *pNext;

		Node() = default;
		Node(int el) :data(el), pNext(nullptr) {};
	};

	Node * pHead;
	Node *pTail;

public:
	DLList() = default;
	~DLList();

	void Print()const;
	void AddHead(int el);
	void InsertAfter(int after, int what);
	void DelTail();

	bool SearchElement(int el)const;
};

