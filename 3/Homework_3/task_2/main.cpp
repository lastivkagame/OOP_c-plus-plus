/*  ---�������� 2---
 ��������� ���� ���(��������� �� ��������� - ���).
  - ��������� ��� �����:
	o ����������� �� �������������( ��� 0/1)
	o ����������� � 1 ���������� (��������� � ����� == 1)
	o ����������� � 2 �����������( ����������� �������� ��� ����������)
	o ������ ������� �� ���� �����
	o ����� ������ ����� �� ����� � ������ ��������� / ���������
	o ����� ���������� �����
 - ��������
	o ��������� �����(< , >) (������ �����)
	o ���������(+) ���� �����
	o ���������(-) ���� �����
	o ��������(*) ���� �����
	o ������(/) ���� �����
	o ������������ �� ���� int, �� ������� ���� ������� �����, ���������, ��� ����� 10/4 ���� ������� ���� 2
	o ������������ �� ���� double, �� ������� ���������� ���, ���������, ���������� ����� 10/4 ������� ���������� ��� 2.5

��������: ��������� �� ������� ���������� ����, ��������� �� ������� ���� �䒺����(����� ��� 1/ -2 ������������� � -1/ 2)
��������� ������ �����
*/

#include "Fractins.h"

int main() {

	cout << "First abrev: \n";
	Fractins a(5, 10);
	a.print();

	cout << "Second abrev(user input): \n";
	int numerator, denomerator;

	cout << "Enter numerator,pls: ";
	cin >> numerator;

	cout << "Enter denumerator,pls: ";
	cin >> denomerator;

	Fractins b(numerator, denomerator);

	Fractins arr[2] = { a,b };

	int frac, choose;

	do {
		system("cls");

		cout << "Menu #1\n";
		cout << "0 - First farction\n";
		cout << "1 - Second farction\n";
		cout << "2 - No\n";
		cout << "3 - Exit from program\n";
		cout << "Answer: ";

		do
		{
			cin >> frac;
		} while (frac < 0 || frac > 3);

		system("cls");

		if (frac == 3)
		{
			break;
		}

		if (frac != 2) {
			cout << " Menu #2\n";
			cout << " 1 - change numerator\n";
			cout << " 2 - change denomerator\n";
			cout << " 3 - print\n";
			cout << " 4 - abreviation fractin\n";
			cout << " 5 - fraction to type int\n";
			cout << " 6 - fraction to type double\n";
			cout << "Answer: ";
			cin >> choose;

			switch (choose)
			{
			case 1:
				cout << "Enter numerator,pls: ";
				cin >> numerator;
				arr[frac].SetNumerator(numerator);
				break;
			case 2:
				cout << "Enter denumerator,pls: ";
				cin >> denomerator;
				arr[frac].SetDenominator(denomerator);
				break;
			case 3:
				cout << " Fractin \n";
				arr[frac].print();
				cout << endl;
				break;
			case 4:
				arr[frac].Abrev();
				cout << "Abtev fractin is succsess!\n";
				break;
			case 5:
				cout << "Rezalt: " << arr[frac].intNumber() << endl;
				break;
			case 6:
				cout << "Rezalt: " << arr[frac].doubleNumber() << endl;
				break;
			default:
				break;
			}
		}
		else
		{
			cout << " Menu #2\n";
			cout << " 1 - frac_1 + frac_2\n";
			cout << " 2 - frac_1 - frac_2\n";
			cout << " 3 - frac_1 * frac_2\n";
			cout << " 4 - frac_1 / frac_2\n";
			cout << " 5 - frac_1 (> = < - compare)  frac_2\n";
			cout << "Answer: ";
			cin >> choose;

			Fractins rez;

			switch (choose)
			{
			case 1:
				rez = a + b;
				cout << " a + b = ";
				rez.print();
				break;
			case 2:
				rez = a - b;
				cout << " a - b = ";
				rez.print();
				break;
			case 3:
				rez = a * b;
				cout << " a * b = ";
				rez.print();
				break;
			case 4:
				rez = a / b;
				cout << " a / b = ";
				rez.print();
				break;
			case 5:
				cout << " a = ";
				a.print();
				cout << " b = ";
				b.print();
				cout << endl;

				cout << " a " << a.comparison(b) << " b " << endl;
				break;
			default:
				break;
			}
		}
		system("pause");
	} while (frac != 3);

	system("cls");

	return 0;
}