/*Доповнити клас String конструктором копії з переміщенням та оператором присвоєння з переміщенням*/

#include "String.h"
#define LINE cout << "------------------\n"

int String::count = 0;

int main()
{
	//тепер просто тестуємо 

	String stroka(10, "Microsoft");

	int number;

	cout << "enter size: ";
	cin >> number;

	char* st = new char[number];

	cout << "enter string: ";
	cin.ignore();
	cin.getline(st, number);

	String stroka2(number, st);

	cout << stroka;
	cout << stroka2;

	LINE;

	cout << "Count: " << String::GetCount() << endl;

	String arr[2] = { stroka, stroka2 };

	system("pause");
	system("cls");

	cout << " MOVE:\n";
	String o1(10, "some str");
	cout << "String o2 = o1:\n";
	String o2 = o1;
	cout << "o1: " << o1 << endl;
	cout << "o2: " << o2 << endl;

	LINE;

	cout << "String o3 = move(o1)\n";
	String o3 = move(o1);
	cout << "o3: " << o3;

	LINE;

	cout << "o3 = o3\n";
	o3 = o3;
	cout << "o3: " << o3 << endl;

	LINE;

	system("pause");
	system("cls");

	int choose, choose2, k;

	do {
		cout << " MENU #1\n";
		cout << " 1 - work with BOTH 2 string\n";
		cout << " 2 - work with ONLY one string\n";
		cout << " 3 - Exit\n";
		cout << "Answer: ";
		cin >> choose;
		system("cls");

		String rez;

		switch (choose)
		{
		case 1:
			cout << " MENU #2\n";
			cout << " 0 - * (it cut one string to other(remain only their common symbols))\n";
			cout << " 1 - + (it add one string to other string and create thirdly string with it)\n";
			cout << " 2 - operator <\n";
			cout << " 3 - operator >\n";
			cout << " 4 - operator <=\n";
			cout << " 5 - operator >=\n";
			cout << " 6 - operator ==\n";
			cout << " 7 - operator !=\n";
			cout << "Answer: ";
			cin >> choose2;
			system("cls");

			switch (choose2)
			{
			case 0:
				rez = stroka * stroka2;
				cout << " stroka * stroka2 = " << rez << endl;
				break;
			case 1:
				cout << " stroka + stroka2 = " << stroka + stroka2 << endl;
				cout << "(Only for trying char* + String): 'its sasha's text ' + stroka2 = " << "its sasha's text" + stroka2 << endl;
				break;
			case 2:
				cout << " stroka < stroka2 is: " << boolalpha << (stroka < stroka2) << endl;
				break;
			case 3:
				cout << " stroka > stroka2 is: " << boolalpha << (stroka > stroka2) << endl;
				break;
			case 4:
				cout << " stroka <= stroka2 is: " << boolalpha << (stroka <= stroka2) << endl;
				break;
			case 5:
				cout << " stroka >= stroka2 is: " << boolalpha << (stroka >= stroka2) << endl;
				break;
			case 6:
				cout << " stroka == stroka2 is: " << boolalpha << (stroka == stroka2) << endl;
				break;
			case 7:
				cout << " stroka != stroka2 is: " << boolalpha << (stroka != stroka2) << endl;
				break;
			default:
				cout << "Inccorect direction!\n";
				break;
			}
			break;

		case 2:
			cout << " MENU #2\n";
			cout << " 0 - change string\n";
			cout << " 1 - change size of string\n";
			cout << " 2 - print string\n";
			cout << " 3 - ++(each symbol in the string will be next on alhabet(ABC))\n";
			cout << " 4 - += - (add to current string)\n";
			cout << " 5 - ! - (reversion( Sun -> nuS))\n";
			cout << " 6 - () - (return fragment of string)\n";
			cout << "Answer: ";
			cin >> choose2;

			cout << " Please choose string: \n";
			cout << "0 - string 1\n";
			cout << "1 - string 2\n";
			cout << "Answer: ";
			cin >> k;
			system("cls");

			switch (choose2)
			{
			case 0:
				cout << "enter size: ";
				cin >> number;

				delete[]st;
				st = new char[number];

				cout << "enter string: ";
				cin.ignore();
				cin.getline(st, number);

				arr[k].SetStr(st);
				arr[k].SetSize(number);
				break;
			case 1:
				cout << "enter size: ";
				cin >> number;
				arr[k].SetSize(number);
				break;
			case 2:
				cout << arr[k];
				break;
			case 3:
				cout << "arr[k]++:  ";
				cout << arr[k]++;
				cout << "arr[k]: " << arr[k];
				cout << "++arr[k]: " << ++arr[k];
				break;
			case 4:
				if (k == 0)
				{
					arr[k] += arr[1];
				}
				else
				{
					arr[k] += arr[0];
				}
				cout << arr[k];
				break;
			case 5:
				!arr[k];
				cout << "Rezalt: ";
				cout << arr[k];
				break;
			case 6:
				int x, x2;
				cout << "Enter begin and end: ";
				cin >> x >> x2;

				cout << arr[k](x, x2) << endl;
				break;
			default:
				cout << "Inccorect direction!\n";
				break;
			}
			break;
		case 3:
			break;
		default:
			cout << "Inccorect direction!\n";
			break;
		}
		system("pause");
		system("cls");

	} while (choose != 3);

	system("pause");
	return 0;
}