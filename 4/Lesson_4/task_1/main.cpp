#include "Array.h"

int main() {

	Array arr;
	arr.print();
	//cout << "arr[5]: " << arr[5] << endl;
	cout << "arr 1: ";
	arr[5] = 100;
	arr.print();
	cout << endl;
	
	Array arr2;
	cout << "arr 2: ";
	arr2.print();
	arr2 = arr;
	cout << endl;

	cout << "arr 2: ";
	arr2.print();
	cout << "++size2 =     ----------------------------------\n";
	cout << (++arr2).GetSize() << endl;
	cout << "-size= -----------------------------------\n";
	cout << (--arr2).GetSize() << endl;

	cout << "size++ =  -----------------------------------\n";
	cout << (arr2++).GetSize() << endl;

	system("cls");

	cout << "Arr = ";
	arr.print();

	cout << "Arr++ = ";
	arr++;
	arr.print();

	cout << "size-- = ";
	arr--;
	arr.print();


	cout << "++Arr = ";
	++arr;
	arr.print();

	cout << "--size = ";
	--arr;
	arr.print();

	system("pause");
	return 0;
}