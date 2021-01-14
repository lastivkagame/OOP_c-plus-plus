/*------- 2 ----------------------------------------------------------------------------------------------------
Создайте класс employee.Класс должен включать поле типа int для хранения номера сотрудника и поле типа float
для хранения величины его оклада.Методы класса должны позволять пользователю вводить и отображать данные класса.
Напишите функцию main(), которая запросит пользователя ввести данные для трех сотрудников и выведет
полученную информацию на экран.*/

#include "classes.h"

int main() {

	employee empl, empl2, empl3;
	employee emplArray[] = { empl, empl2, empl3 };
	int number;
	double salary;
	int size = 3;

	for (int i = 0; i < size; i++)
	{
		cout << "\tAdd new employee #" << i << endl;

		//коректність вводу (як завжди)
		do
		{
			cout << " Hello! Glad to see you! Enter your employee number: ";
			cin >> number;
		} while (number <= 0);

		//присвоєння
		emplArray[i].SetNumber(number);

		//коректність вводу
		do
		{
			cout << " Good! And now emloyee # " << number << " enter your salary, pls: ";
			cin >> salary;
		} while (salary <= 0);

		//присвоєння
		emplArray[i].SetSalary(salary);

		cout << "Thanks for your time! Have a nice day! Goodbue!\n\n";

		system("pause");
		system("cls");
	}

	int choose3, choose4, choose5;

	do {
		system("cls");

		cout << " Menu 2(task 2)\n";
		cout << " 1 - Print employee 1\n";
		cout << " 2 - Print employee 2\n";
		cout << " 3 - Print employee 3\n";
		cout << " 4 - Print all (3 employee and their data)\n";
		cout << " 5 - Edit emloye 1 or emloye 2 or emloye 3\n";
		cout << " 6 - exit\n";
		cout << "Answer:";
		cin >> choose3;
		system("cls");

		switch (choose3)
		{
		case 1:
			emplArray[0].print();
			break;
		case 2:
			emplArray[1].print();
			break;
		case 3:
			emplArray[2].print();
			break;
		case 4:
			for (int i = 0; i < size; i++)
			{
				emplArray[i].print();
				cout << endl;
			}
			break;
		case 5:
			system("cls");
			cout << "How player you want edit ?\n";
			cout << " 0 - Employee 1\n";
			cout << " 1 - Employee 2\n";
			cout << " 2 - Employee 3\n";
			cout << " 3 - exit\n";
			cout << "Answer: ";
			cin >> choose4;

			cout << "What you want edit ?\n";
			cout << " 1 - number\n";
			cout << " 2 - salary\n";
			cout << " 3 - exit\n";
			cout << "Answer: ";
			cin >> choose5;

			system("cls");

			switch (choose5)
			{
			case 1:
				cout << "Please enter new number: ";
				cin >> number;

				emplArray[choose4].SetNumber(number);
				break;
			case 2:
				cout << "Please enter new salary: ";
				cin >> salary;

				emplArray[choose4].SetSalary(salary);
				break;
			case 3:
				break;
			default:
				cout << "Inccorect direction!\n";
				break;
			}
			break;
		case 6:
			break;
		default:
			cout << "Inccorect direct!\n";
			break;
		}
		system("pause");

	} while (choose3 != 6);

	return 0;
}