#include "String.h"

int String::count = 0;

int main() {

	String stroka(10, "Microsoft");
	char* st;
	int number;

	cout << "enter size: ";
	cin >> number;

	cout << "enter string: ";
	cin.getline(st, number);

	String stroka2(numer, st);



	system("pause");
	return 0;
}