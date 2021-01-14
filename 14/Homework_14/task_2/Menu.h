#pragma once
#include "Train.h"
#include <windows.h>
#include <conio.h>
#include <exception>

class Menu
{
public:
	void Start()
	{
		vector<Train> trains
		({
			Train(2,"03.05.20 at 12:00", "a3"),
			Train(3,"15.07.20 at 17:50", "b1"),
			Train(1,"09.03.20 at 09:10", "a1")
			});

		bool exit = true;
		while (exit)
		{
			int choose = 0, number, index, choose4;
			string time, station;

			vector<string> str({
				"\t       - Add train - ",
				"\t       - Del train - ",
				"\t     - Del all train - ",
				"\t   - Change some train - ",
				"\t - Print trains by number - ",
				"\t  - Print trains by time - ",
				"\t - Print train by station - ",
				"\t          - exit - "
				});

			vector<string> str1({  //case 4
					" -Please choose- ",
					"  change number ",
					"   change time ",
					"  change station ",
					"    change all "
				});

			choose = MoveChoose(str);

			switch (choose)
			{
			case 1:
				cout << " Enter number: ";
				cin >> number;

				cout << " Enter time: ";
				//cin.ignore();
				getline(cin, time);
				cin.ignore();
				//cin.clear();
				cout << " Enter station: ";
				//cin.ignore();
				getline(cin, station);
				cin.ignore();

				trains.push_back(Train(number, time, station));
				break;
			case 2:
				index = Choose(trains) - 1;

				if (index<0 || index > trains.size())
				{
					cout << " Inccorect!\n";
				}
				else
				{
					trains.erase(trains.begin() + index);
				}
				break;
			case 3:
				trains.clear();
				break;
			case 4:
				index = Choose(trains);
				do
				{
					choose4 = MoveChoose(str1);
				} while (choose4 == 1);

				system("cls");

				switch (choose4)
				{
				case 2:
					cout << " Enter number: ";
					cin >> number;

					trains[index].SetNumber(number);
					break;
				case 3:
					cout << " Enter time: ";
					cin >> time;

					trains[index].SetTime(time);
					break;
				case 4:
					cout << " Enter station: ";
					cin >> station;

					trains[index].SetStation(station);
					break;
				case 5:
					cout << " Enter number: ";
					cin >> number;

					cout << " Enter time: ";
					cin >> time;

					cout << " Enter station: ";
					cin >> station;

					trains[index].SetNumber(number);
					trains[index].SetTime(time);
					trains[index].SetStation(station);
					break;
				default:
					cout << " Inccorect direction!\n";
					break;
				}
				break;
			case 5:
				cout << " How you want: \n";
				cout << " 1 - >\n";
				cout << " 2 - < \n";
				cout << "Answer: ";
				cin >> choose4;

				system("cls");

				if (choose4 == 1)
				{
					sort(trains.begin(), trains.end(), [](Train trains1, Train trains2)
						{
							return trains1.GetNumber() > trains2.GetNumber();
						});
				}
				else
				{
					sort(trains.begin(), trains.end(), [](Train trains1, Train trains2)
						{
							return trains1.GetNumber() < trains2.GetNumber();
						});
				}
				PrintVector(trains);
				break;
			case 6:
				cout << " How you want: \n";
				cout << " 1 - >\n";
				cout << " 2 - < \n";
				cout << "Answer: ";
				cin >> choose4;

				system("cls");

				if (choose4 == 1)
				{
					sort(trains.begin(), trains.end(), [](Train trains1, Train trains2)
						{
							return trains1.GetTime() > trains2.GetTime();
						});
				}
				else
				{
					sort(trains.begin(), trains.end(), [](Train trains1, Train trains2)
						{
							return trains1.GetTime() < trains2.GetTime();
						});
				}
				PrintVector(trains);
				break;
			case 7:
				cout << " How you want: \n";
				cout << " 1 - >\n";
				cout << " 2 - < \n";
				cout << "Answer: ";
				cin >> choose4;

				system("cls");

				if (choose4 == 1)
				{
					sort(trains.begin(), trains.end(), [](Train trains1, Train trains2)
						{
							return trains1.GetStation() > trains2.GetStation();
						});
				}
				else
				{
					sort(trains.begin(), trains.end(), [](Train trains1, Train trains2)
						{
							return trains1.GetStation() < trains2.GetStation();
						});
				}
				PrintVector(trains);
				break;
			case 8:
				cout << " \n Have a nice day! Bye.\n";
				exit = false;
				break;
			default:
				cout << " Inccorect direction!\n";
				break;
			}

			system("pause");
			system("cls");
		}
	}

	int Choose(vector<Train> train)
	{
		int choose, number;
		string time, station;
		vector<string> str({
			"  How you want find train ?",
			"      I want choose of list ",
			"           By number ",
			"           By time ",
			"          By station "
			});
		do
		{
			choose = MoveChoose(str);
		} while (choose == 1);

		switch (choose)
		{
		case 2:
			return MoveChoose(train);
			break;
		case 3:
			cout << " Enter number: ";
			cin >> number;

			for (int i = 0; i < train.size(); i++)
			{
				if (train[i].GetNumber() == number)
				{
					return i;
				}
			}
			break;
		case 4:
			cout << " Enter time: ";
			cin >> time;

			for (int i = 0; i < train.size(); i++)
			{
				if (train[i].GetTime() == time)
				{
					return i;
				}
			}
			break;
		case 5:
			cout << " Enter station: ";
			cin >> station;

			for (int i = 0; i < train.size(); i++)
			{
				if (train[i].GetStation() == station)
				{
					return i;
				}
			}
			break;
		default:
			cout << " Inccorect direction!\n";
			return -1;
			break;
		}
		return -1;
	};

	template<typename T>
	void SpecialPrint(vector<T> temp, int el)
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		int t = 1;

		system("cls");

		cout << "  <<Automated railway station information system>> \n";
		for (int i = 0; i < temp.size(); i++)
		{
			if (t == el)
			{
				SetConsoleTextAttribute(hOUTPUT, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << " ->";
			}

			cout << temp[i];

			if (t == el)
			{
				cout << "      <-";
				SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			cout << endl;
			t++;
		}
		cout << endl;
		cout << endl;
	}

	template<typename T>
	int MoveChoose(vector<T> temp)
	{
		bool exit = false;
		int ch;
		int el = 1, max = temp.size();

		SpecialPrint(temp, el);

		while (!exit)
		{
			ch = _getch();
			switch (ch)
			{
			case 224:
			{
				switch (_getch())
				{
				case 72:
				{// нажата клавиша вверх

					if (el == max)
					{
						el--;
					}
					else if (el == 0)
					{
						el = max;
					}
					else
					{
						el--;

						if (el == 0)
						{
							el = max;
						}
					}

					SpecialPrint(temp, el);
					break;
				}
				case 80:
				{// нажата клавиша вниз

					if (el == max)
					{
						el = 1;
					}
					else if (el == 0)
					{
						el = max;
					}
					else
					{
						el++;
					}

					SpecialPrint(temp, el);

					break;
				}
				default:
					break;
				}
				break;
			}
			case 13:
			{
				exit = true;
				break;
			}
			default:
				break;
			}
		}

		return (el--);
	}

	template <typename T>
	void PrintVector(vector<T> arr)
	{
		string line(30, '_');
		cout << line << endl;
		for (T& elem : arr)
		{
			cout << elem << endl;
		}
		cout << line << endl;
	}

};