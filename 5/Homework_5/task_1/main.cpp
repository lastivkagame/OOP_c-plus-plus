/*Розробити клас String для роботи з рядками. Клас повинен містити:
▪ конструктор по замовчуванню, який дозволяє створити рядок довжиною 80
символів, вміст рядка “”(пустий рядок);
▪ конструктор, який дозволяє створити рядок довільного розміру, вміст рядка
“”(пустий рядок);
▪ конструктор, який створює рядок та ініціалізує його рядком, отриманим від
користувача;
▪ конструктор копій:

Додати до класу статичне приватне поле – лічильник існуючих на даний момент
екземплярів класу String та статичний метод доступу(для читання) до цього поля,

Доповнити клас String операціями(операторними функціями)
o Операція *: повинна повертати новий рядок, який утворюється шляхом
перетину двох рядків, тобто їх спільні символи. Наприклад, результатом
перетину рядків "Microsoft" та "Windows" буде рядок "ioso".
o Операція +, що дозволяє додати два рядки (конкатенація рядків). Наприклад,
результатом додавання двох рядків "Microsoft" та "Windows" буде рядок
"MicrosoftWindows".Причому цю операцію треба перевантажити, щоби вона
могла конкатенувати не лише два String'и, але і String з const char *, тобто, щоб
можна було написати: obj + "asdfg" і "asgfd" + obj -- в обох випадках отримуємо
різні String.
o Операція ++ : повинна збільшувати код кожного символу рядка на 1(визначити
префіксну та постфіксну форми). Наприклад, результатом ++ для рядка "Abcd"
буде "Bcde"
o Оператори порівняння: <, >, <=, >=, ==, != для можливості порівняння двох
рядків
o Оператор ! (NOT), що дозволить здійснити реверс рядка. Наприклад,
результатом реверсу String'а "Windows" буде новий String "swodniW".

Доповнити клас String операціями

o Оператор [], що дозволить індексувати рядок за цілим індексом.
o Оператор (), що дозволить повертати фрагмент рядка, починаючи з певної
позиції певної довжини у вигляді екземпляру String. Довжина фрагмента –
необов’язковий параметр. При упущенні довжини фрагмента – повертати
фрагмент від вказаної позиції до кінця рядка. Якщо початкова позиція
некоректна – повертати порожній рядок, якщо довжина фрагмента завелика –
повертати фрагмент до кінця рядка. Наприклад, для рядка String s(“My
program”), s(3) – операція повинна повертати “program ”( як String), s(3, 4) –
повинна повертати “prog”( як String).
o Оператор присвоєння.
o Оператор складних присвоєнь += (використати визначені раніше операції +).
o Потокові операції для введення та виведення рядка*/


#include "String.h"
#define LINE cout << "------------------\n"
#define ENDL cout << endl;

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