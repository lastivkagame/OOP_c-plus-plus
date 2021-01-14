#include "Array.h"

int main() {

	srand(time(nullptr));

	Array arr, arr2, rez;
	arr.fillArr();
	arr2.fillArr();
	cout << "----------------\n";
	arr.print();
	cout << "----------------\n";
	arr2.print();
	cout << "----------------\n";

	//rez = move(arr);
	//cout << "rez = move(arr);\n";
	//rez.print();
	//cout << endl;

	cout << arr[3] << endl;
	//cout << arr[-1] << endl;

	arr.Add(100);
	arr.print();

	system("cls");
	arr.print();
	arr.remove(2);
	arr.print();
	system("cls");
	arr.print();
	cout << endl;
	cout << "Arr++\n";
	arr++;
	arr.print();

	cout << endl;


	arr2.fillArr();
	arr2.print();
	cout << endl;
	cout << "Arr+arr2 = rez\n";
	rez = arr + arr2;
	rez.print();
	cout << endl;

	system("cls");

	rez.print();
	cout << endl;
	Array temp = 100 + rez;
	temp.print();

	system("cls");

	cout << temp << endl;

	system("cls");

	/*Array littleArr(5);

	cout << "Input: " << endl;
	cin >> littleArr;
	cout << littleArr;

	system("cls");*/

	/*cout << arr2;
	arr2(3, 300);
	cout << arr2;*/

	//Array copy = arr;

	system("pause");
	return 0;
}