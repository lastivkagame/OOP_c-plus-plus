#include "Complex.h"
#define LINE cout << "--------------------\n\n";

int main()
{
	//тестимо
	double num1, num2;
	cout << " Enter num1 and num2: ";
	cin >> num1 >> num2;

	Complex object1(num1, num2);
	Complex object2(2);
	Complex object3(1, -1);

	cout << "-----------Show object------------\n";
	cout << " - Object 1: ";
	cout << object1 << endl;

	cout << " - Object 2: ";
	cout << object2 << endl;

	cout << " - Object 3: ";
	cout << object3 << endl;

	LINE;

	cout << "-----Show after some operation-----\n";
	cout << " ++Object1: ";
	++object1;
	cout << object1 << endl;

	cout << " Object2--: ";
	object1--;
	cout << object1 << endl;

	LINE;

	////дії над комплексними числами
	cout << "--------------Actions--------------\n";
	cout << " - object 1 + object 2 = " << object1 << " + " << object2 << " = " << (object1 + object2) << endl;
	cout << " - object 1 - object 2 = " << object1 << " - " << object2 << " = " << (object1 - object2) << endl;
	cout << " - object 1 * object 2 = " << object1 << " * " << object2 << " = " << (object1 * object2) << endl;
	cout << " - object 1 / object 2 = " << object1 << " / " << object2 << " = " << (object1 / object2) << endl;

	LINE;
	system("pause");
	system("cls");

	//порівняння комплексних чисел
	cout << "-------------Comparison-------------\n";
	cout << "object 1 == object 2: " << boolalpha << (object1 == object2) << endl;  // спитати

	LINE;

	cout << "-------------Comparison-------------\n";
	cout << "  - object 1: " << object1 << endl;
	cout << "  - object 2: " << object2 << endl;
	cout << "  object 1 = object 3\n";
	cout << "  - object 1: " << object1 << endl;
	cout << "  - object 2: " << object2 << endl;

	LINE;

	cout << "-----------------Other--------------\n";
	cout << " object1 += object2";
	object1 += object2;
	cout << " object1 = " << object1 << endl;

	cout << " object1 -= object2";
	object1 -= object2;
	cout << " object1 = " << object1 << endl;

	LINE;

	cout << " modul of object 3: " << object3.modul() << endl;
	cout << " argument of object 3: " << object3.argument() << endl;

	return 0;
}