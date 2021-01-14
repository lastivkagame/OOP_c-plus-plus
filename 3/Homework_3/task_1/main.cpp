/*Написати програму роботи з поїздами, на основі класів Car(Вагон) та Train (Поїзд).
Програма пропонує ввести з клавіатури:
	 Кількість поїздів;
	 Кількість вагонів для кожного поїзда.
На основі уведених даних створюються поїзди, виводиться загальна інформація про них та набір наступних звітів:
	 Поїзд в якому їхала найбільша кількість пасажирів.
	 Поїзд в якому їхала найменша кількість пасажирів.
Клас Car повинен містити:
	 поля:
		o тип вагона(купе, плацкарт, спальний);
		o кількість пасажирів у вагоні
	 методи:
		o конструктори
		o методи доступу до полів
		o виводу інформації про вагон
Клас Train повинен містити:
	 поля:
		o номер поїзда;
		o назва поїзда (сполучення, наприклад “Львів – Київ”);
		o поле “вагони” - вказівник на тип Car, якому буде виділятися динамічна пам`ять
		o розміром в кількість вагонів, де індекс даного масиву вказує на номер вагону;
		o кількість вагонів(може бути полем - константою).
	 методи:
		o Конструктори: по замовчуванню, з параметрами та копіювання;
		o Стандартні методи доступу до полів класу;
		o Метод для знаходження вагона з максимальною кількість пасажирів;
		o Метод для знаходження вагона з мінімальною кількість пасажирів;
		o Метод для знаходження загальної кількості пасажирів в поїзді;
		o Метод для виведення інформації про поїзд:
		o загальна кількість пасажирів.
		o загальна кількість вагонів.*/

#include "classes.h"

int main()
{
	srand(time(nullptr));

	int x;

	cout << " You're Welcome!\n";

	//  1) Визначимо к-сть поїздів це буде перший масив (масив поїздів)
	cout << "Enter digits of trains: ";
	cin >> x;

	Train* trains = new Train[x];

	int size2 = 50;  //розмір поля у яке вводимо назву поїзда (сполучення, наприклад “Львів – Київ”);
	int size, number, y;  // size - це к-сь вагонів у поїзді; number - це номер поїзду 
	char* arr = new char[size2];   //полe у яке вводимо назву поїзда(сполучення, наприклад “Львів – Київ”);

	typeCar type;   // для вводу типу вагона (один з 3-ох)

	for (int j = 0; j < x; j++)
	{
		system("cls");

		cout << "Enter name: ";
		cin.ignore();
		cin.getline(arr, size2);

		cout << "Enter number of train: ";
		cin >> number;

		do {
			cout << " Please input number of cars.\n";
			cout << "Answer: ";
			cin >> size;
		} while (size <= 0);

		Car* tempCar = new Car[size];

		for (int i = 0; i < size; i++)
		{
			system("cls");

			cout << "Enter type of car: \n";
			cout << " 1 - COMPARTMENT  - (Max: 36 passengers)\n";
			cout << " 2 - SLEEPING     - (Max: 10 passengers)\n";
			cout << " 3 - SEATPOST     - (Max: 54 passengers)\n";
			cout << "Answer: ";
			cin >> y;

			switch (y)
			{
			case 1:
				type = COMPARTMENT;
				break;
			case 2:
				type = SLEEPING;
				break;
			case 3:
				type = SEATPOST;
				break;
			default:
				type = COMPARTMENT;
				break;
			}

			tempCar[i].SetTypeCar(type);
			tempCar[i].SetPassengers();
		}

		Train tempTrain(size, number, tempCar, arr);

		trains[j] = tempTrain;
	}

	system("cls");
	cout << "\t ALL TRAINS\n";
	for (int i = 0; i < x; i++)
	{
		cout << "Train #" << i << endl;
		trains[i].print();
		cout << endl;
	}

	system("pause");
	system("cls");

	cout << "The train with the largest number of passengers: \n";
	trains[trains[0].FindTrainMaxPass(trains, x)].print();
	cout << endl;

	cout << "The train with the smallest number of passengers: \n";
	trains[trains[0].FindTrainMinPass(trains, x)].print();
	cout << endl;

	delete[]trains;
	delete[]arr;

	system("pause");
	return 0;
}