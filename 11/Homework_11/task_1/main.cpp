/*1. Створити абстрактний базовий клас Shape, що містить:
o        чисті віртуальні функції print(), printShapeName() – без реалізації
o        віртуальні функції аrea(),volume(), що повертають нульове значення.


***printShapeName() – можна реалізувати за допомогою typeid()

Клас Point успадковує реалізації аrea(),volume() від класу Shape(точка має нульову площу та об’єм).
Клас Circle  успадковує реалізацію volume() від класу Point,  але має власну реалізацію аrea().
Клас  Cylinder має власні реалізації функцій аrea()  та volume().

Створити масив фігур(масив вказівників на базовий клас).
Викликати методи обчислення площі, об’єму та виведення для кожної фігури з масиву.
*/

#include <iostream>
#include "Circle.h"
#include "Cylinder.h"
#include "Point.h"
using namespace std;

int main()
{
	Circle circle(3);
	Cylinder cylinder(2, 4);

	Shape* figures[] = { &circle,&cylinder, new Point };

	for (int i = 0; i < 3; i++)
	{
		figures[i]->Print();
		cout << endl;
	}

	return 0;
}