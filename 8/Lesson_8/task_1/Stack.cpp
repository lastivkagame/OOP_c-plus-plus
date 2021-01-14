#include "Stack.h"

void Stack::push(int el)
{
	if (!isFull()) 
	{
		stack[++top] = el;
	}
}

bool Stack::pop(int & el)  //якщо в стек є елементи, то повертаємо ел на вершині потім зменшуємо вершину
{
	if (!isEmpty()) {
		el = stack[top--];
		return true;
	}
	return false;
}

void Stack::clear()
{
	top = EMPTY; //ефективна очистка стеку(лінива очистка) - 
	//(дані в масиві існують, але доступу немає бо методи класу працюють з top)
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
