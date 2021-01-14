#include "Train.h"

bool SearchByNumber(Train & tr)
{
	return tr
}

int main()
{
	bool flag = true;
	int number;
	string time, station;

	vector<Train> trains(
		{
			Train(1,"02.09.20 in 14.00","at a1")
		});

	while (flag)
	{
		system("cls");

		cout << " -> Automatic informatic system by trains stage <-\n";

		cout << " 1 - Add train\n";
		cout << " 2 - Del train\n";
		cout << " 3 - Del all train\n";
		cout << " 4 - Correct train\n";
		cout << " 5 - Print by number\n";
		cout << " 6 - Print by time\n";
		cout << " 7 - Print by ststion\n";
		cout << " 8 - Exit";

		int choose, temp;
		cin >> choose;

		switch (choose)
		{
		case 1:
			cout << "Enter number: ";
			cin >> number;

			cout << "Enter time: ";
			cin >> time;

			cout << "Enter station: ";
			cin >> station;

			trains.push_back(Train(number, time, station));

			break;
		case 2:

			cout << " How you want find train: \n";
			cout << " 1 - by number\n";
			cout << " 2 - by time\n";
			cout << " 3 - by station\n";
			cin >> temp;

			switch (temp)
			{
			case 1:
				cout << "Enter number: ";
				cin >> number;
				break;
			case 2:
				cout << "Enter time: ";
				cin >> time;
				break;
			default:case 3:
				cout << "Enter station: ";
				cin >> station;
				break;
			}

			//trains.erase()

			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			flag = false;
			break;
		default:
			cout << "Inccorect direction\n";
			break;

			system("pause");
		}
	}

	system("pause");
	return 0;
}