/*	Обробка виключень
1.Доповнити шаблон класу Стек
- Метод вилучення елемента зі стеку повинен викидати виключення, якщо стек порожній
- Метод додавання елементу в стек повинен викидати виключення, якщо стек повний*/

#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

	Stack stack;  // max 5

	try
	{
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);
		stack.push(5);
		stack.push(6);
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

	int x;

	try
	{
		stack.pop(x);
		stack.pop(x);
		stack.pop(x);
		stack.pop(x);
		stack.pop(x);
		stack.pop(x);
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

	system("pause");
	return 0;
}