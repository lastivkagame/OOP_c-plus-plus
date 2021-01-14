/*  ---Завдання 2---
 Визначити клас Дріб(чисельник та знаменник - цілі).
  - Визначити для класу:
	o конструктор за замовчуванням( дріб 0/1)
	o конструктор з 1 параметром (знаменник у дробу == 1)
	o конструктор з 2 параметрами( передбачити валідацію для знаменника)
	o методи доступу до полів класу
	o метод виводу дробу на екран у вигляді чисельник / знаменник
	o метод скорочення дробу
 - Операції
	o порівняння дробів(< , >) (методи класу)
	o додавання(+) двох дробів
	o віднімання(-) двох дробів
	o множення(*) двох дробів
	o ділення(/) двох дробів
	o перетворення до типу int, що повертає цілу частину дробу, наприклад, для дробу 10/4 ціла частина рівна 2
	o перетворення до типу double, що повертає десятковий дріб, наприклад, звичайному дробу 10/4 відповідає десятковий дріб 2.5

Валідація: знаменник не повинен дорівнювати нулю, знаменник не повинен бути від’ємним(тобто дріб 1/ -2 перетворювати у -1/ 2)
Перевірити роботу класу
*/

#include "Fractin.h"

int main() {

	Fractins a(5, 10);
	a.print();

	//int numerator, denomerator;

	//cout << "Enter numerator,pls: ";
	//cin >> numerator;

	//cout << "Enter denumerator,pls: ";
	//cin >> denomerator;

	//Fractins b(numerator, denomerator);

	//Fractins arr[2] = { a,b };

	//int frac, choose;

	//do {
	//	cout << "Menu #1\n";
	//	cout << "0 - First farction\n";
	//	cout << "1 - Second farction\n";
	//	cout << "2 - No\n";
	//	cout << "3 - Exit from program\n";
	//	do
	//	{
	//		cin >> frac;
	//	} while (frac < 0 || frac > 3);

	//	system("cls");

	//	if (frac != 3) {
	//		cout << " Menu #2\n";
	//		cout << " 1 - change numerator\n";
	//		cout << " 2 - change denomerator\n";
	//		cout << " 3 - print\n";
	//		cout << " 4 - abreviation fractin\n";
	//		cout << " 5 - fraction to type int\n";
	//		cout << " 6 - fraction to type double\n";
	//		cout << "Answer: ";
	//		cin >> choose;

	//		switch (choose)
	//		{
	//		case 1:
	//			cout << "Enter numerator,pls: ";
	//			cin >> numerator;
	//			arr[frac].SetNumerator(numerator);
	//			break;
	//		case 2:
	//			cout << "Enter denumerator,pls: ";
	//			cin >> denomerator;
	//			arr[frac].SetDenominator(denomerator);
	//			break;
	//		case 3:
	//			cout << " Fractin \n";
	//			arr[frac].print();
	//			cout << endl;
	//			break;
	//		case 4:
	//			arr[frac].Abrev();
	//			cout << "Abtev fractin is succsess!\n";
	//			break;
	//		case 5:
	//			arr[frac].intNumber();
	//			cout << "succsess!\n";
	//			break;
	//		case 6:
	//			arr[frac].doubleNumber();
	//			cout << "succsess!\n";
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//	else
	//	{
	//		cout << " Menu #2\n";
	//		cout << " 1 - frac_1 + frac_2\n";
	//		cout << " 2 - frac_1 - frac_2\n";
	//		cout << " 3 - frac_1 * frac_2\n";
	//		cout << " 4 - frac_1 / frac_2\n";
	//		cout << " 5 - frac_1 (> = < - compare)  frac_2\n";
	//		cout << "Answer: ";
	//		cin >> choose;

	//		Fractins rez;

	//		switch (choose)
	//		{
	//		case 1:
	//			rez = a + b;
	//			cout << " a + b = ";
	//			rez.print();
	//			break;
	//		case 2:
	//			rez = a - b;
	//			cout << " a - b = ";
	//			rez.print();
	//			break;
	//		case 3:
	//			rez = a * b;
	//			cout << " a * b = ";
	//			rez.print();
	//			break;
	//		case 4:
	//			rez = a / b;
	//			cout << " a / b = ";
	//			rez.print();
	//			break;
	//		case 5:
	//			cout << " a " << a.comparison(b) << " b " << endl;
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//} while (frac != 3);

	system("cls");

	system("pause");
	return 0;
}