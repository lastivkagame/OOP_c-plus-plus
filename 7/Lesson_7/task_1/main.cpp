#include "Complex.h"
#define LINE cout << "--------------------\n";

int main()
{
	double num1, num2;
	cout << " Enter num1 and num2: ";
	cin >> num1 >> num2;

	Complex object1(num1, num2);
	Complex object2(2);
	Complex object3(1, -1);

	cout << "Object 1: ";
	cout << object1 << endl;

	cout << "Object 2: ";
	cout << object2 << endl;

	cout << "Object 3: ";
	cout << object3 << endl;

	LINE;

	cout << " ++Object1: ";
	++object1;
	cout << object1 << endl;

	cout << " Object2--: ";
	object1--;
	cout << object1 << endl;

	LINE;

	Complex rez;

	////дії над комплексними числами
	rez = object1 + object2;
	cout << " object 1 + object 2 = " << object1 << " + " << object2 << " = " << (object1 + object2) << endl;

	rez = object1 - object2;
	cout << " object 1 - object 2 = " << object1 << " - " << object2 << " = " << rez << endl;

	rez = object1 * object2;
	cout << " object 1 * object 2 = " << object1 << " * " << object2 << " = " << rez << endl;

	rez = object1 / object2;
	cout << " object 1 / object 2 = " << object1 << " / " << object2 << " = " << rez << endl;

	//cout << (object1 + object2) << endl; // спитати

	LINE;

	//порівняння комплексних чисел
	bool flag = (object1 == object2);
	cout << "object 1 == object 2: " << boolalpha << (object1 == object2) << endl;  // спитати
	cout << "object 1 == object 2: " << boolalpha << flag << endl;

	LINE;

	cout << " object 1: " << object1 << endl;
	cout << " object 2: " << object2 << endl;
	cout << "object 1 = object 3\n";
	cout << " object 1: " << object1 << endl;
	cout << " object 2: " << object2 << endl;

	LINE;

	cout << " object1 += object2";
	object1 += object2;
	cout << " object1 = " << object1 << endl;

	cout << " object1 -= object2";
	object1 -= object2;
	cout << " object1 = " << object1 << endl;

	LINE;

	cout << " modul of object 3: " << object3.modul() << endl;
	cout << " argument of object 3: " << object3.argument() << endl;

	system("pause");
	return 0;
}