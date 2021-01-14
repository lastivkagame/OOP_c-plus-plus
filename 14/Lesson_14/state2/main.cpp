#include <iostream>
#include <vector>
using namespace std;

void PrintState()
{
	cout << "bad: " << cin.bad() << endl;
	cout << "good: " << cin.good() << endl;
	cout << "fail: " << cin.fail() << endl;
}

void PrintVector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;
}

int main()
{
	vector<int>arr;

	int num;

	while (cin.good())
		//while (cin >> num) 
	{
		cin >> num;
		arr.push_back(num);
	}

	PrintVector(arr);
	PrintState();

	cout << "--------------------\n";
	cout << "enter new element: ";
	//cin.sync();
	cin.clear();  //clean potok vid error
	cin.ignore(3);	//we ignore symbol that leave in potok
	cin >> num;
	arr.push_back(num);
	cout << "--------------------\n";

	PrintVector(arr);
	PrintState();

	system("pause");
	return 0;
}