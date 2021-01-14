/*Самостійно розібрати приклади по контейнерах stack, queue, priority_queue.*/
#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <queue>
using namespace std;
#define LINE cout << "_________________\n";

int main()
{
#pragma region Stack
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.emplace(4);
	st.pop();

	cout << " -Stack- \n";
	while (!st.empty())
	{
		cout << " " << st.top() << " ";
		st.pop();
	}
	cout << endl;
	LINE;

	stack<int, list<int>> st2;

	st2.push(4);
	st2.push(5);
	st2.push(6);
	st2.emplace(7);
	st2.pop();

	cout << " -Stack(list)- \n";
	while (!st2.empty())
	{
		cout << " " << st2.top() << " ";
		st2.pop();
	}
	cout << endl;
	LINE;

	stack<int, vector<int>> st3;
	st3.push(6);
	st3.push(7);
	st3.push(8);
	st3.emplace(9);
	st3.pop();

	cout << " -Stack(vector)- \n";
	while (!st3.empty())
	{
		cout << " " << st3.top() << " ";
		st3.pop();
	}
	cout << endl;
	LINE;
#pragma endregion

#pragma region Queue
	queue <int> q;
	q.push(30);
	q.push(31);
	q.push(32);
	q.push(33);
	q.push(34);

	cout << endl << endl;
	cout << "Front el: " << q.front() << endl;
	cout << "Back el: " << q.back() << endl;
	cout << " size: " << q.size() << endl;

	cout << "\n -Queue- \n";
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}

	queue <int, list<int>> q2;
	cout << "\n\n -Queue(list)- \n";
	q2.push(4);
	q2.push(5);
	cout << "Front: " << q2.front() << endl;

	queue <int, vector<int>> q3;
	cout << "\n -Queue(vector)- \n";
	q3.push(7);
	q3.push(8);
	cout << "End: " << q3.back() << endl;

#pragma endregion

#pragma region PriorateQueue
	priority_queue<int> pq;

	pq.push(20);
	pq.push(30);
	pq.push(24);

	cout << "\n -Priorate Queue- \n";
	cout << " Size: " << pq.size() << endl;
	while (!pq.empty())
	{
		cout << " " << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

#pragma endregion

	return 0;
}