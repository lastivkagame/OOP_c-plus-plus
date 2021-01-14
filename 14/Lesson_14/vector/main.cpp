#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <functional>
#include <algorithm>  //для sort
using namespace std;

template <typename T>
void PrintVector(vector<T> arr) 
{
	string line(30, '_');
	cout << line << endl;
	//for (auto &elem : arr) можна й так
	for (T &elem : arr) 
	{
		cout << elem << " ";
	}
	cout << endl << " Size: " << arr.size() << endl;
	cout << endl << " Capacity: " << arr.capacity() << endl;
	cout << line << endl;
}

bool notPairFunc(int el) 
{
	return el % 2 != 0; //11- true, 22-false
}

int main() {

	//vector - послідовний контейнер
	//konteyner - набір елементів. в контейнері може зберігатись довільна кількість елементів
	// кількість формується динамічно
	//STL - standart template library
	//предикат - функція у алгоритмі

	vector<int>A(3);  // 0 0 0
	
	PrintVector(A);
	vector<int>B({ 10,30,50,45 });
	PrintVector(B);
	B.push_back(100);
	B.push_back(67);

	vector<int>C(B.begin() + 2, B.end() - 1);
	PrintVector(C);

	//method
	B.front() = 1000;
	A.assign(B.begin(), B.begin() + 2);

	A.back() = -345;
	PrintVector(A);
	PrintVector(B);

	try 
	{
		B.at(10) = 100;
	}
	catch(out_of_range ex)
	{
		cout << ex.what() << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	cout << "Print via iterators\n";
	//for (auto it = B.begin(); it != B.end(); it++)  //в правильному порядку
	for (auto it = B.rbegin(); it != B.rend(); it++)	//задом наперед
	{
		cout << *it << "\t";
	}
	cout << endl;

	A.emplace(A.begin(), B.front());  //вставка
	PrintVector(A);
	PrintVector(B);

	system("cls");
	A.insert(A.begin() + 1, { 1,78,99 });
	A.insert(A.end(), B.begin() + 1, B.begin() + 3);
	PrintVector(A);
	PrintVector(B);

	A.insert(A.end(), 7, B.front());  //вставить 7 раз переший елемент вектора B

	PrintVector(A);
	PrintVector(B);

	vector<int>copyVector(A.size());

	copy(A.begin() + A.size() / 2, A.end(), copyVector.begin()); //алгоритм копії
	PrintVector(copyVector);

	system("cls");

	cout << " Vector B " << endl;
	PrintVector(B);

	auto result = count(B.begin(), B.end(), 1000);
	cout << "resalt: " << result << endl;
	cout << endl;
	cout << endl;

	cout << " Vector A " << endl;
	PrintVector(A);

	auto result2 = count(A.begin(), A.end(), 1000);
	cout << "resalt: " << result2 << endl;

	result = count_if(A.begin(), A.end(), notPairFunc);
	//system("pause");

	vector<int>notPair(result);
	copy_if(A.begin(), A.end(), notPair.begin(), notPairFunc);	//алгоритм  //notPairFunc - предикат
	//copy_if(A.begin(), A.end(), notPair.begin(), !notPairFunc);//алгоритм //notPairFunc - предикат - так не можна
	PrintVector(notPair);

	system("cls");

	int size = A.size() - result;	//кількість парних
	vector<int>pair(size);
	copy_if(A.begin(), A.end(), pair.begin(), [](int el) {return el % 2 == 0; });	//лямда функція
	PrintVector(pair);

	auto it = find(A.begin(), A.end(), 1000);
	if (it != A.end()) 
	{
		cout << "Found: "<< *it << endl;
	}

	//auto it2 = find_if(A.begin(), A.end(), [](int x) {return x < 0; });
	auto it2 = find_if(pair.begin(), pair.end(), [](int x) {return x < 0; });

	if (it2 != pair.end())
	{
		cout << "Found: " << *it2 << endl;
	}
	else
	{
		cout << "Element not found\n";
	}

	sort(A.begin(), A.end());
	cout << "After sort: " << endl;
	PrintVector(A);

	vector<string>rows({ "watermelon","applee","cherry","banana" });
	cout << " Begin sort string: \n";
	sort(rows.begin(), rows.end(), greater<string>());	 //greater - предикат (шаблонна фунуція)
	cout << " After sort string: \n";
	PrintVector(rows);
	cout << "sort size: ";
	sort(rows.begin(), rows.end(), [](string first, string second) {return first.size() < second.size(); });
	PrintVector(rows);


	system("pause");
	return 0;
}