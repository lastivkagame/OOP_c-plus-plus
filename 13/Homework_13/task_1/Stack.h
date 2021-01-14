#pragma once
//FILO - first int last out
//FIFI - first int first out

class Stack  //динамічна структура
{
private:
	static const int MAX_SIZE = 5; //максимально можлива к-сть елементів
	int stack[MAX_SIZE];
	enum { EMPTY = -1 };
	int top = EMPTY; //індекс останього зайнятого елемента; індекс вершини;
public:
	Stack() = default;
	void push(int el);
	bool pop(int& el);
	void clear();
	bool isEmpty()const;
	bool isFull()const;
	int GetCount()const; //к-сть елементів в стеку
};