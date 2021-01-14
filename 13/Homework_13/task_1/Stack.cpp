#include "Stack.h"

void Stack::push(int el)
{
	if (!isFull())
	{
		stack[++top] = el;
	}
	else 
	{
		throw "Error! Steak is Full!\n";  // generating error
	}
}

bool Stack::pop(int& el)  //���� � ���� � ��������, �� ��������� �� �� ������ ���� �������� �������
{
	if (!isEmpty()) {
		el = stack[top--];
		return true;
	}

	throw "Error! Steak is Empty!\n";
	return false;
}

void Stack::clear()
{
	top = EMPTY; //��������� ������� �����(����� �������) - 
	//(��� � ����� �������, ��� ������� ���� �� ������ ����� �������� � top)
}

bool Stack::isEmpty() const
{
	return top == EMPTY;
}

bool Stack::isFull() const
{
	return top == (MAX_SIZE - 1);
}

int Stack::GetCount() const
{
	return top + 1;
}