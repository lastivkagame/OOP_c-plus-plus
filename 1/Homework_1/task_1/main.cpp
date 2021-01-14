/* ---- 1 ------------------------------------------------------------------------------------------------------
Написати клас Автомобіль. Інкапсулювати необхідні поля з модифікатором доступу private, написати конструктори
для створення об'єктів, деструктор, методи доступу (сеттери та геттери).Продемонструвати роботу в мейні
ПРИМІТКА: ви сказали забрати з сеттерів  перевірку на !=nullptr то я просто їх закометувала (мені так простіше)*/

#include "classes.h"

int main() {

	const int size = 50;
	char* userArray = new char[size];
	double number = 0;
	int choose, choose1;

	//створюємо і не задаємо ніяких значень
	cout << "  ----- Simle create ----\n";
	Car standartCar1;
	standartCar1.print();  //виводимо на екран і бачимо стандартні параметри бо ми ніяких не задали
	system("pause");
	system("cls");

	//створюємо і задаємо значення
	cout << "  ----- Simle create (#2) + set the value ----\n";
	Car standartCar2("FIAT", "Panda", "black", 2017, "Epicyclic gearbox", "Automotive engine", 130000);
	standartCar2.print();  //виводимо на екран і бачимо те що зади при створенні
	system("pause");
	system("cls");

	//змінюємо і виводимо готові зачення
	do {
		system("cls");
		cout << " Menu_1(task 1)\n";
		cout << " 1 - change some \n";
		cout << " 2 - see some\n";
		cout << " 3 - exit\n";
		cout << "Answer: ";
		cin >> choose;
		system("cls");

		switch (choose)
		{
		case 1:
			cout << " Menu_2(task 1)\n";
			cout << " 1 - Brand  \n";
			cout << " 2 - Model  \n";
			cout << " 3 - Color  \n";
			cout << " 4 - Year   \n";
			cout << " 5 - Gearbox  \n";
			cout << " 6 - Engine Type  \n";
			cout << " 7 - Price  \n";
			cout << "Answer: ";
			cin >> choose1;
			system("cls");

			switch (choose1)
			{
			case 1:
				cout << "Enter brand: ";
				cin >> userArray;
				standartCar2.SetBrand(userArray);
				break;
			case 2:
				cout << "Enter model: ";
				cin >> userArray;
				standartCar2.SetModel(userArray);
				break;
			case 3:
				cout << "Enter color: ";
				cin >> userArray;
				standartCar2.SetColor(userArray);
				break;
			case 4:
				cout << "Enter year: ";
				cin >> number;
				standartCar2.SetYear(number);
				break;
			case 5:
				cout << "Enter Gearbox: ";
				cin >> userArray;
				standartCar2.SetGearbox(userArray);
				break;
			case 6:
				cout << "Enter Engine Type: ";
				cin >> userArray;
				standartCar2.SetEngineType(userArray);
				break;
			case 7:
				cout << "Enter price: ";
				cin >> number;
				standartCar2.SetPrice(number);
				break;
			default:
				cout << "Inccorect direction!\n";
				break;
			}

			delete[]userArray;
			userArray = new char[size];

			break;
		case 2:
			cout << " Menu_2(task 1)\n";
			cout << " 1 - Brand  \n";
			cout << " 2 - Model  \n";
			cout << " 3 - Color  \n";
			cout << " 4 - Year   \n";
			cout << " 5 - Gearbox  \n";
			cout << " 6 - Engine Type  \n";
			cout << " 7 - Price  \n";
			cout << " 8 - See all\n";
			cout << "Answer: ";
			cin >> choose1;
			system("cls");

			switch (choose1)
			{
			case 1:
				cout << " Brand: " << standartCar2.GetBrand() << endl;
				break;
			case 2:
				cout << " Model: " << standartCar2.GetModel() << endl;
				break;
			case 3:
				cout << " Color: " << standartCar2.GetColor() << endl;
				break;
			case 4:
				cout << " Year: " << standartCar2.GetYear() << endl;
				break;
			case 5:
				cout << " Gearbox: " << standartCar2.GetGearbox() << endl;
				break;
			case 6:
				cout << " Engine Type: " << standartCar2.GetEngineType() << endl;
				break;
			case 7:
				cout << " Price: " << standartCar2.GetPrice() << endl;
				break;
			case 8:
				system("cls");
				standartCar2.print();
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
	} while (choose != 3);

	delete[]userArray;

	return 0;
}