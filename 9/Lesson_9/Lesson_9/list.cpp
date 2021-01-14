#include "list.h"

list::list()
{
	pHead = pTail = nullptr;
}


list::~list()
{
	Clear();
}

void list::Print() const
{
	Node*temp = pHead;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->pNext;
	}
	cout << endl;
}

void list::AddHead(int el)
{
	Node*temp = new Node(el);
	//Node temp(el); або 

	if (pHead != nullptr)
	{
		temp->pNext = pHead;
		pHead = temp;
	}
	else
	{
		pHead = pTail = temp;
	}
}

void list::AddTail(int el)
{
	Node*temp = new Node(el);
	//Node temp(el); або 

	if (pHead != nullptr)
	{
		pTail->pNext = temp;
		pTail = temp;
	}
	else
	{
		pHead = pTail = temp;
	}
}

void list::InsertAfter(int after, int what)
{
	if (SearchElement(after))
	{
		Node*temp = pHead;

		while (temp->data != after)
		{
			temp = temp->pNext;
		}

		Node*forInsert = new Node(what);
		forInsert->pNext = temp->pNext;
		temp->pNext = forInsert;
	}
}

void list::DelElement(int el)
{
	if (SearchElement(el))
	{
		Node*temp = pHead;

		if (temp->data == el)
		{
			DelHead();
			return;
		}

		while (temp->pNext->data != el)
		{
			temp = temp->pNext;
		}

		if (temp->pNext == pTail) 
		{
			DelTail();
			return;
		}

		Node *forDel = temp->pNext;

		temp->pNext = forDel->pNext;
		delete forDel;
	}
}

bool list::SearchElement(int el) const
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

void list::Clear()
{
	while (pHead)
	{
		DelHead();
	}
}

void list::DelHead()
{
	if (pHead)
	{
		Node*temp = pHead;
		pHead = pHead->pNext;
		delete temp;
	}
}

void list::DelTail()
{
	if (pTail)
	{
		Node*temp = pHead;

		while (temp->pNext != pTail) 
		{
			temp = temp->pNext;
		}

		Node *forDel = pTail;
		temp->pNext = nullptr;
		pTail = temp;

		delete forDel;
	}
}
