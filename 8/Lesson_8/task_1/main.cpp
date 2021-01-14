#include "Stack.h"
#include "Queue.h"
#include "RingQueue.h"
#include "PriorateQueue.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {

#pragma region Stack
	//srand(time(nullptr));

	//Stack st; //5 el, top = -1;
	//int el = 0;
	//cout << "Push elements: \n\n";
	//while (!st.isFull())
	//{
	//	el = rand() % 25;
	//	st.push(el);
	//	cout << "Element = " << el << endl;
	//	//st.push(rand() % 20);
	//}
	//cout << endl;

	///*while (!st.isEmpty())
	//{
	//	st.pop(el);
	//	cout << "el = " << el << endl;
	//}*/
	//st.clear();

	//cout << "pop: " << boolalpha << st.pop(el) << endl;
	//cout << "el = " << el << endl;

	//if (st.pop(el))
	//{
	//	cout << "el = " << el << endl;
	//}
	//else
	//{
	//	cout << "Stack is empty!\n" << endl;
	//}
#pragma endregion



#pragma region Queue

	/*int size;
	cout << "Enter size: ";
	cin >> size;

	Queue wait1(size);

	for (int i = 0; i < size; i++)
	{
		wait1.enqueue(i);
	}

	cout << " dequeue from wait: ";
	wait1.dequeue();
	wait1.show();
	cout << endl;

	cout << "GetCount: " << wait1.getCount() << endl << endl;

	cout << "Wait1.clear(): ";
	wait1.clear();
	wait1.show();

	cout << endl;

	Queue q(5);

	while (!q.isFull()) {
		q.enqueue(rand() % 25);
	}
	q.show();

	while (!q.isEmpty()) {
		cout << q.dequeue() << " ";
	}
	cout << endl;*/

#pragma endregion

#pragma region RingQueue
	/*
			RingQueue q4(5);

			while (!q4.isFull()) {
				q4.enqueue(rand() % 25);
			}

			q4.show();
			cout << endl;

			cout << "q4.dequeue(): " << q4.dequeue() << endl << endl;
			cout << "q4.dequeue(): " << q4.dequeue() << endl << endl;
			q4.show();*/
#pragma endregion



	PriorateQueue q(5);

	while (!q.isFull()) {
		q.enqueue((rand() % 25), (rand() % 100));
	}
	q.show();

	cout << endl;
	cout << endl;

	//while (!q.isEmpty()) {
	cout << "q = " << q.dequeue() << " " << endl;
	cout << "q = " << q.dequeue() << " " << endl;
	//}
	q.show();
	cout << endl;


	system("pause");
	return 0;
}