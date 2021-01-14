#include "DLList.h"

DLList::DLList()
{
	pHead = pTail = nullptr;
}


DLList::~DLList()
{
}

void DLList::Print() const
{
	Node*temp = pHead;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->pNext;
	}
	cout << endl;
}

void DLList::AddHead(int el)
{
	Node*temp = new Node(el);
	//Node temp(el); або 

	if (pHead != nullptr)
	{
		temp->pNext = pHead;
		temp->pPrev = nullptr;
		pHead = temp;
	}
	else
	{
		pHead = pTail = temp;
	}
}

void DLList::InsertAfter(int after, int what)
{
	if (SearchElement(after))
	{
		Node*temp = pHead;
		Node*forInsert = new Node(what);

		while (temp->data != after)
		{
			temp = temp->pNext;
		}

		forInsert->pNext = temp->pNext;
		temp->pNext = forInsert;
		forInsert->pPrev = temp;
		forInsert->pNext->pPrev = forInsert;

	}
}

void DLList::DelTail()
{
	if (pTail)
	{
		Node*temp = pTail->pPrev;
		temp->pNext = nullptr;
	}
}


bool DLList::SearchElement(int el) const
{
	Node*temp = pHead;

	while (temp != nullptr)
	{
		if (temp->data == el)
		{
			return true;
		}

		temp = temp->pNext;
	}

	return false;
}