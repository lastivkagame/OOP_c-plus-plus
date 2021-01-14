#include "Number.h"
int Int::count = 0;
void main()
{
	Number a(45);
	Number b{ 20 };

	Number c = a + b;
	cout << "operator + " << endl;
	c.Print();
	Number d = a - b;
	cout << "operator - " << endl;
	d.Print();
	if (a > b)
	{
		cout << "object a > object b" << endl;
	}
	else
		cout << "object a < object b" << endl;

	cout << "\n\noperator int()\n";
	int test = d;
	cout << "test = " << test << endl;
	char testChar = b + a;
	cout << "test char = " << testChar << endl;
	Int aa = 55;
	Int testInt = a;
	cout << "\n\nTest Number to Int" << endl;
	testInt.print();
	system("cls");

	Number num1(12);
	Number demoSum = num1 + 10;

	demoSum.Print();
	int res = num1 + a;
	system("pause");
}