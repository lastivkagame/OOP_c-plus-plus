#include "Number.h"

int Int::count = 0;

int main() {
	
	Number a(46);
	Number b{ 20 };  //юніформ ініціалізація

	Number c = a + b;
	Number d = a - b;
	Number f = a * b;
	Number h = a / b;


	c.print();
	d.print();
	f.print();
	h.print();

	if (a > b)
	{
		cout << "object a > object b" << endl;
	}
	else 
	{
		cout << "object a < object b" << endl;
	}

	cout << "operator int()\n";
	int test = d;
	cout << "Test : " << test << endl;
	char testChar = b + a;
	cout << "test char = " << testChar << endl;
	
	Number t(10);
	Int p = t;

	cout << "p = ";
	p.print();
	cout << endl;

	system("cls");

	Number num1(12);
	Number demoSum = num1 + 10;
	demoSum.print();

	int rezalt = num1 + a;
	cout << "Rezalt: " << rezalt << endl;



	system("pause");
	return 0;
}