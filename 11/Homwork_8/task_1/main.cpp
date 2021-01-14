/*  ---Завдання 1---
Створити шаблон класу PriorityQueue(Черга з пріоритетами, динамічно розширювана).
Вважати, що більший елемент має більший пріоритет. Протестувати на типах int, string, Fractions.*/

#include "PriorateQueue.h"
#include "Fractions.h"
#include <string>
#include <ctime>

int main() {

	srand(time(nullptr));

	PriorateQueue <int> i(5);
	PriorateQueue <string> s(3);
	PriorateQueue <Fractins> f(2);

	cout << "Count: " << i.getCount();

#pragma region INT

	cout << " ---1 - INT ---\n";

	while (!i.isFull())
	{
		i.enqueue((rand() % 25), (rand() % 100));
	}
	i.show();

	cout << endl;
	cout << endl;

	cout << "i = " << i.dequeue() << " " << endl;
	cout << "i = " << i.dequeue() << " " << endl;

	i.show();
	cout << endl;
#pragma endregion

#pragma region STRING

	cout << " ---2 - STRING ---\n";

	string c;

	while (!s.isFull())
	{
		cout << "Enter symbol that stay a wait(priorate was be random number): ";
		cin >> c;
		s.enqueue(c, (rand() % 100));
	}

	s.show();

	cout << endl;
	cout << endl;

	cout << "s = " << s.dequeue() << " " << endl;
	cout << "s = " << s.dequeue() << " " << endl;

	s.show();
	cout << endl;
#pragma endregion

#pragma region FRACTINS

	cout << " ---3 - FRACTINS ---\n";

	Fractins d(5, 10), b(4, 12);

	f.enqueue(d, (rand() % 100));
	f.enqueue(b, (rand() % 100));


	f.show();

	cout << endl;
	cout << endl;

	cout << "(priorate element that be del)f = " << f.dequeue() << " " << endl;

	f.show();
	cout << endl;
#pragma endregion

	return 0;
}