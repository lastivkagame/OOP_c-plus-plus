/*Переробити виконане завдання 1 на багатофайловий проект
	Int.h - містить визначення класу   
	Int.cpp - містить реалізації функцій-елементів додавання, множення та інш.
	main.cpp - містить головну функцію main()*/

#include "Int.h"

int main() {

	Int a(20);
	Int b(10);


	cout << "a = ";
	a.print();
	cout << endl;
	cout << "b = ";
	b.print();
	cout << endl;

	Int sum = a.Sum(b);
	cout << "Sum = a + b = ";
	sum.print();
	cout << endl;

	Int sub = a.Sub(b);
	cout << "Sub = a - b = ";
	sub.print();
	cout << endl;

	Int mnz = a.Mnz(b);
	cout << "Mnz = a * b = ";
	mnz.print();
	cout << endl;

	Int del = a.Del(b);
	cout << "Del = a / b =";
	del.print();
	cout << endl;

	int choose, choose2, number;

	do
	{
		system("pause");
		system("cls");
		cout << " Menu:\n";
		cout << " 0 - change number\n";
		cout << " 1 - + numbers\n";
		cout << " 2 - - numbers\n";
		cout << " 3 - * numbers\n";
		cout << " 4 - / numbers\n";
		cout << " 5 - all\n";
		cout << " 6 - exit\n";
		cout << "Answer: ";
		cin >> choose;
		system("cls");

		switch (choose)
		{
		case 0:
			cout << " a = ";
			a.print();
			cout << " b = ";
			b.print();
			cout << endl;
			cout << "You want change:\n";
			cout << " 1 - a\n";
			cout << " 2 - b\n";
			cout << "Answer: ";
			cin >> choose2;

			if (choose2 == 1)
			{
				cout << "Enter number a\n";
				cin >> number;
				a.SetNumber(number);
			}
			else if (choose2 == 2)
			{
				cout << "Enter number a\n";
				cin >> number;
				b.SetNumber(number);
			}
			else
			{
				cout << "Inccorect direction!\n";
			}
			break;
		case 1:
			sum = a.Sum(b);
			cout << " Sum: a + b = ";
			sum.print();
			cout << endl;
			break;
		case 2:
			sub = a.Sub(b);
			cout << " Sub: a - b = ";
			sub.print();
			cout << endl;
			break;
		case 3:
			mnz = a.Mnz(b);
			cout << " Mnz: a * b = ";
			mnz.print();
			cout << endl;
			break;
		case 4:
			del = a.Del(b);
			cout << " Del: a / b = ";
			del.print();
			cout << endl;
			break;
		case 5:
			sum = a.Sum(b);
			cout << "Sum = a + b = ";
			sum.print();
			cout << endl;

			sub = a.Sub(b);
			cout << "Sub = a - b = ";
			sub.print();
			cout << endl;

			mnz = a.Mnz(b);
			cout << "Mnz = a * b = ";
			mnz.print();
			cout << endl;

			del = a.Del(b);
			cout << "Del = a / b = ";
			del.print();
			cout << endl;
			break;
		default:
			break;
		}
	} while (choose != 6);

	return 0;
}