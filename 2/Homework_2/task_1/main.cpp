/*Разработать класс String, который в дальнейшем будет
использоваться для работы со строками. Класс должен
содержать:
-	 Конструктор по умолчанию, позволяющий создать
строку длиной 80 символов;
-	 Конструктор, позволяющий создавать строку произвольного размера;
-	 Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.
-	 Необходимо создать деструктор, а также использовать механизмы делегирования конструкторов, если это
возможно.
-	 Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран.*/

#include "class.h"

int main() {

	int size = 1, choose = 0;

	cout << " Object 1(default constructor): \n";
	String object1;
	object1.print();
	cout << endl;

	cout << " Object 2(size(for array)): \n";
	size = 30;
	String object2(size);
	object2.print();
	cout << endl;

	cout << " Object 3: \n";
	size = 60;
	char* arr = new char[size];
	strcpy_s(arr, 16, "Have a nice day");
	String object3(size, arr);
	object3.print();
	cout << endl;

	system("pause");

	String ourArr[]{ object1, object2, object3 };

	int choose2, choose3;

	do
	{
		system("cls");
		cout << "	Menu\n";
		cout << "1 - change some object or print some object\n";
		cout << "2 - print all object\n";
		cout << "3 - exit\n";
		cout << "Answer: ";
		cin >> choose;
		system("cls");

		switch (choose)
		{
		case 1:
			cout << " Choose object, pls: \n";
			cout << " 0 - object 1\n";
			cout << " 1 - object 2\n";
			cout << " 2 - object 3\n";
			cout << "Answer: ";
			cin >> choose2;
			system("cls");

			if ((choose2 < 4) && (choose2 > 0))
			{
				cout << "What you want edit or print?\n";
				cout << " 1 - Edit\n";
				cout << " 2 - Print\n";
				cout << "Answer: ";
				cin >> choose3;

				if (choose3 == 1)
				{
					cout << " What you want edit?\n";
					cout << " 1 - string\n";
					cout << " 2 - size\n";
					cout << "Answer: ";
					cin >> choose3;

					if (choose3 == 1)
					{
						cout << "Enter string, pls: ";
						cin.ignore();
						cin.getline(arr, ourArr[choose2].GetSize());
						//cin.ignore();
						ourArr[choose2].SetSomeString(arr);
					}
					else
					{
						cout << " Size: ";
						cin >> size;
						ourArr[choose2].SetSize(size);
					}
				}
				else
				{
					system("cls");
					ourArr[choose2].print();
					cout << endl;
				}
				break;
			}
		case 2:

			for (int i = 0; i < 3; i++)
			{
				cout << "Object #" << i << endl;
				ourArr[i].print();
				cout << endl;
			}
			break;
		case 3:
			break;
		default:
			break;
		}

		system("pause");

	} while (choose != 3);

	delete[]arr;

	return 0;
}