#include "Int.h"

int  Int::count = 0;

int main() {

	Int a = 8; //копіююча ініціалізація
	a.print();

	/*
	int a;
	a = 7;
	int b(10);
	*/

	Int b(10);
	b.print();

	Int sum = a.Sum(b);
	sum.print();

	Int sub = a.Sub(b);
	sub.print();

	a.Sub(sum).print();

	a.SumEqual(sum).print();

	cout << "Count = " << Int::GetCount() << endl;

	system("pause");
	return 0;
}