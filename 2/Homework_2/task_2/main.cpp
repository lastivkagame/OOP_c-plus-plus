/*Разработать класс Person, который содержит соответствующие члены для хранения:
- имени,
- возраста,
- пола и
- телефонного номера.
Напишите функции-члены, которые смогут изменять эти члены данных индивидуально. Напишите
функцию-член Person::Print(), которая выводит отформатированные данные о человеке.*/

#include "class.h"

int main() {

	//тестуймо
	Person obj1("Sem", 23, "male", 954458789);

	cout << " Obj 1: \n";
	obj1.Print();

	system("pause");
	int choose, choose1, choose2;
	int number, size = 50;
	char* arr = new char[size];

	do
	{
		system("cls");
		cout << "    Menu\n";
		cout << "  1 - Edit or print some characteristic\n";
		cout << "  2 - Print all about obj1\n";
		cout << "  3 - Exit\n";
		cout << "Answer: ";
		cin >> choose;
		system("cls");

		switch (choose)
		{
		case 1:
			do {
				system("cls");
				cout << "Choose what you want?\n";
				cout << " 1 - Print some\n";
				cout << " 2 - Edit some\n";
				cin >> choose1;
			} while (choose1 < 0 || choose1 > 2);

			do {
				system("cls");
				cout << "What you want of this?\n";
				cout << " 1 - change name\n";
				cout << " 2 - change age\n";
				cout << " 3 - change gender\n";
				cout << " 4 - change number\n";
				cin >> choose2;
			} while (choose2 < 0 || choose2 > 4);

			system("cls");
			switch (choose2)
			{
			case 1:
				if (choose1 == 1)
				{
					cout << "Name: " << obj1.GetName() << endl;
				}
				else
				{
					cout << "Enter new name,pls: ";
					cin.ignore();
					cin.getline(arr, size);

					obj1.SetName(arr);
				}
				break;
			case 2:
				if (choose1 == 1)
				{
					cout << "Age: " << obj1.GetAge() << endl;
				}
				else
				{
					cout << "Enter new age,pls: ";
					cin >> number;

					obj1.SetAge(number);
				}
				break;
			case 3:
				if (choose1 == 1)
				{
					cout << "Gender: " << obj1.GetGender() << endl;
				}
				else
				{
					cout << "Enter new gender,pls: ";
					cin.ignore();
					cin.getline(arr, size);

					obj1.SetGender(arr);
				}
				break;
			case 4:
				if (choose1 == 1)
				{
					cout << "Number: " << obj1.GetNumber() << endl;
				}
				else
				{
					cout << "Enter new number,pls: ";
					cin >> number;

					obj1.SetNumber(number);
				}
				break;
			default:
				break;
			}
			system("pause");
			break;
		case 2:
			system("cls");
			cout << " Obj1: \n";
			obj1.Print();
			system("pause");
			break;
		default:
			break;
		}
	} while (choose != 3);

	delete[]arr;

	return 0;
}