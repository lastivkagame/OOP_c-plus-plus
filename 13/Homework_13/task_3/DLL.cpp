#include "DLL.h"

DLList::DLList()
{
	pHead = pTail = nullptr;
}


DLList::~DLList()
{
	Clear();
}

void DLList::Print() const
{
	Node* temp = pHead;

	if (pHead != nullptr && pTail != nullptr)
	{

		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->pNext;
		}
		cout << endl;
		cout << endl;
	}
	else 
	{
		throw "It`s empty!\n";
	}
}

void DLList::AddHead(int el)
{
	Node* temp = new Node(el);

	if (pHead != nullptr)
	{
		temp->pPrev = nullptr;
		temp->pNext = pHead;
		pHead->pPrev = temp;
		pHead = temp;
	}
	else
	{
		pHead = pTail = temp;
	}
}

void DLList::AddTail(int el)
{
	Node* temp = new Node(el);

	if (pTail != nullptr)
	{
		temp->pNext = nullptr;
		temp->pPrev = pTail;
		pTail->pNext = temp;
		pTail = temp;
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
		Node* temp = pHead;
		Node* forInsert = new Node(what);

		while (temp->data != after)
		{
			temp = temp->pNext;
		}

		forInsert->pNext = temp->pNext;
		temp->pNext = forInsert;
		forInsert->pPrev = temp;
		forInsert->pNext->pPrev = forInsert;

	}
	else 
	{
		throw "Element not found!\n";
	}
}

void DLList::DelHead()
{
	if (pHead)
	{
		if (pHead == pTail) 
		{
			pHead = pTail = nullptr;
		}
		else
		{
			Node* temp = pHead->pNext;
			temp->pPrev = nullptr;
			pHead = temp;
		}
	}
	else 
	{
		throw " Head is not exist!\n";
	}
}

void DLList::DelTail()
{
	if (pTail)
	{
		if (pHead == pTail)
		{
			pHead = pTail = nullptr;
		}
		else
		{
			Node* temp = pTail->pPrev;
			temp->pNext = nullptr;
			pTail = temp;
		}
	}
	else
	{
		throw " Tail is not exist!\n";
	}
}


bool DLList::SearchElement(int el) const
{
	Node* temp = pHead;

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

void DLList::Clear()
{
	while (pHead)
	{
		DelHead();
	}
}