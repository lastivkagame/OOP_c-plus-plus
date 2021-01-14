/*--------3------------------------------------------------------------------------------------------------------
Разработать класс Reservoir (водоем). Класс должен обязательно иметь поле «название». Класс должен содержать:
конструктор по умолчанию, конструктор с параметрами,деструктор. Добавить методы для:
1. Определения приблизительного объема (ширина* длина * максимальная глубина);
2. Определения площади водной поверхности(ширина* длина)
3. Метод для проверки относятся ли водоемы к одному типу (море-море; бассейн-пруд);
4. Остальные методы на усмотрение разработчика (методы set и get). Написать интерфейс для работы с классом.
(продемонструвати роботу в мейні - можна через меню)
ПРИМІТКА: ви сказали щоб я не робила масивом, бo те що я пробувала то нічого не вийшло і ми до цього ще не
дійшли і не розбирали*/

#include "classes.h"

int main() {

	int i = 0;
	Reservoir reserv, reserv2;
	int size = 50;
	char* userArr = new char[size];
	double userNumber;

	cout << "Dear user! We offer you fill 2 reservoirs.\n";

	cout << "\tResrvois #" << i << endl;

	cout << "Enter name, pls: ";
	cin >> userArr;
	reserv.SetName(userArr);

	cout << "Enter Width, pls: ";
	cin >> userNumber;
	reserv.SetWidth(userNumber);

	cout << "Enter Depth, pls: ";
	cin >> userNumber;
	reserv.SetDepth(userNumber);

	cout << "Enter Length, pls: ";
	cin >> userNumber;
	reserv.SetLength(userNumber);

	cout << "Enter type, pls: ";
	cin >> userArr;
	reserv.SetType(userArr);

	system("cls");
	i++;
	delete[]userArr;
	userArr = new char[size];

	cout << "\tResrvois #" << i << endl;

	cout << "Enter name, pls: ";
	cin >> userArr;
	reserv2.SetName(userArr);

	cout << "Enter Width, pls: ";
	cin >> userNumber;
	reserv2.SetWidth(userNumber);

	cout << "Enter Depth, pls: ";
	cin >> userNumber;
	reserv2.SetDepth(userNumber);

	cout << "Enter Length, pls: ";
	cin >> userNumber;
	reserv2.SetLength(userNumber);

	cout << "Enter type, pls: ";
	cin >> userArr;
	reserv2.SetType(userArr);
	system("cls");

	system("cls");
	cout << "Thanks for your time!\n";
	system("pause");
	system("cls");

	int choose7, choose8, j;

	do {
		cout << "\tMenu 3(task 3):\n";
		cout << " 1 - See and edit all characteristics of first OR second objects\n";
		cout << " 2 - See all characteristics of 2 objects\n";
		cout << " 3 - Exit\n";
		cout << "Answer: ";
		cin >> choose7;
		system("cls");

		switch (choose7)
		{
		case 1:
			system("cls");

			cout << "Please choose: \n";
			cout << " 0 - First reservion\n";
			cout << " 1 - Second reservion\n";
			cout << "Answer: ";
			cin >> j;

			cout << "What you want ?\n";
			cout << " 1 - see all characteristics\n";
			cout << " 2 - edit something\n";
			cout << " 3 - find some characteristics\n";
			cout << " 4 - exit\n";
			cout << "Answer: ";
			cin >> choose8;
			system("cls");

			switch (choose8)
			{
			case 1:
				if (j == 0)
				{
					cout << "\tReservoir #1\n";
					reserv.print();
					cout << "Volume Water: " << reserv.volumeWater(reserv.GetWidth(), reserv.GetLength(), reserv.GetDepth()) << endl;
					cout << "Area Water: " << reserv.areaWater(reserv.GetWidth(), reserv.GetLength()) << endl;
				}
				else
				{
					cout << "\tReservoir #2\n";
					reserv2.print();
					cout << "Volume Water: " << reserv2.volumeWater(reserv.GetWidth(), reserv2.GetLength(), reserv2.GetDepth()) << endl;
					cout << "Area Water: " << reserv2.areaWater(reserv.GetWidth(), reserv2.GetLength()) << endl;
				}
				break;
			case 2:
				cout << "What you want edit ?\n";
				cout << " 1 - Name\n";
				cout << " 2 - Width\n";
				cout << " 3 - Depth\n";
				cout << " 4 - Length\n";
				cout << " 5 - Type\n";
				cout << " 6 - exit\n";
				cout << "Answer: ";
				cin >> choose8;
				system("cls");

				switch (choose8)
				{
				case 1:
					if (j == 0)
					{
						cout << "Enter name, pls: ";
						cin >> userArr;
						reserv.SetName(userArr);
					}
					else
					{
						cout << "Enter name, pls: ";
						cin >> userArr;
						reserv2.SetName(userArr);
					}
					break;
				case 2:
					if (j == 0)
					{
						cout << "Enter Width, pls: ";
						cin >> userNumber;
						reserv.SetWidth(userNumber);
					}
					else
					{
						cout << "Enter Width, pls: ";
						cin >> userNumber;
						reserv2.SetWidth(userNumber);
					}
					break;
				case 3:
					if (j == 0)
					{
						cout << "Enter Depth, pls: ";
						cin >> userNumber;
						reserv.SetDepth(userNumber);
					}
					else
					{
						cout << "Enter Depth, pls: ";
						cin >> userNumber;
						reserv2.SetDepth(userNumber);
					}
					break;
				case 4:
					if (j == 0)
					{
						cout << "Enter Length, pls: ";
						cin >> userNumber;
						reserv.SetLength(userNumber);
					}
					else
					{
						cout << "Enter Length, pls: ";
						cin >> userNumber;
						reserv2.SetLength(userNumber);
					}
					break;
				case 5:
					if (j == 0)
					{
						cout << "Enter type, pls: ";
						cin >> userArr;
						reserv.SetType(userArr);
					}
					else
					{
						cout << "Enter type, pls: ";
						cin >> userArr;
						reserv2.SetType(userArr);
					}
					break;
				case 6:
					break;
				default:
					cout << "Inccorect direction!\n";
					break;
				}
				break;
			case 3:
				cout << "What you want see ?\n";
				cout << " 1 - Name\n";
				cout << " 2 - Width\n";
				cout << " 3 - Depth\n";
				cout << " 4 - Length\n";
				cout << " 5 - Type\n";
				cout << " 6 - exit\n";
				cout << "Answer: ";
				cin >> choose8;
				system("cls");

				switch (choose8)
				{
				case 1:
					if (j == 0)
					{
						cout << " Name: " << reserv.GetName() << endl;
					}
					else
					{
						cout << " Name: " << reserv2.GetName() << endl;
					}
					break;
				case 2:
					if (j == 0)
					{
						cout << " Width: " << reserv.GetWidth() << endl;
					}
					else
					{
						cout << " Width: " << reserv2.GetWidth() << endl;
					}
					break;
				case 3:
					if (j == 0)
					{
						cout << " Depth: " << reserv.GetDepth() << endl;
					}
					else
					{
						cout << " Depth: " << reserv2.GetDepth() << endl;
					}
					break;
				case 4:
					if (j == 0)
					{
						cout << " Length: " << reserv.GetLength() << endl;
					}
					else
					{
						cout << " Length: " << reserv2.GetLength() << endl;
					}
					break;
				case 5:
					if (j == 0)
					{
						cout << " Type: " << reserv.GetType() << endl;
					}
					else
					{
						cout << " Type: " << reserv2.GetType() << endl;
					}
					break;
				case 6:
					break;
				default:
					cout << "Inccorect direction!\n";
					break;
				}
				break;
			case 4:
				break;
			default:
				cout << "Inccorect direction!\n";
				break;
			}

			delete[]userArr;
			userArr = new char[size];

			break;
		case 2:
			i = 0;
			cout << "Reservoir #" << i++ << endl;
			reserv.print();
			cout << "Volume Water: " << reserv.volumeWater(reserv.GetWidth(), reserv.GetLength(), reserv.GetDepth()) << endl;
			cout << "Area Water: " << reserv.areaWater(reserv.GetWidth(), reserv.GetLength()) << endl;
			cout << endl;
			cout << "Reservoir #" << i << endl;
			reserv2.print();
			cout << "Volume Water: " << reserv2.volumeWater(reserv2.GetWidth(), reserv2.GetLength(), reserv2.GetDepth()) << endl;
			cout << "Area Water: " << reserv2.areaWater(reserv2.GetWidth(), reserv2.GetLength()) << endl;
			cout << endl;
			cout << "Are this reservion are have the same type: " << boolalpha << reserv.isOneType(reserv.GetType(), reserv2.GetType()) << endl;
			break;
		case 3:

			break;
		default:
			cout << "Inccorect direction!\n";
			break;
		}

		system("pause");
		system("cls");

	} while (choose7 != 3);

	delete[]userArr;

	return 0;
}