#include "Game_Assemblage.h"

void Game_Assemblage::StartProgram()
{
	Game exec;
	exec.FirstLoader();

	// дл€ зчитуванн€ та запису
	ifstream read;
	ofstream write;

	// дл€ ввиводу результат≥в
	string nameuser;
	map<string, int> userready;

	int menu;
	bool exit = true;

	do
	{
		menu = exec.Menu();  //викликаЇ меню

		if (menu == 1)  // початок гри
		{
			exec.startGrid();

			while (true)
			{
				exec.displayGrid();
				exec.keyPress();
				exec.logicFlow(&exec);

				if (exec.gameEndCheck(&exec)) 
				{
					break;
				}
			};
		}
		else if (menu == 2)  // таблиц€ результат≥в
		{
			system("cls");

			string temp;
			int temp2;

			read.open("Board_champ.txt");  //в≥дкриваЇмо файл дл€ запису
			SetColor(14, 0);
			cout << "  --- Board of Champions --- \n";
			SetColor(10, 0);
			cout << "    -User-    ";
			cout << "     -Rezalt- \n";
			SetColor(15, 0);

			int k = 0;
			bool flag = true;

			while (!read.eof())
			{
				k++;
				if (k % 2 == 0)
				{
					read >> temp2;

					for (auto el : userready)
					{
						if (el.first == temp)
						{
							flag = false;

							if (el.second < temp2)
							{
								userready.at(temp) = temp2;
							}
						}
					}

					if (flag)
					{
						userready.insert({ temp, temp2 });   //зчитуЇмо
					}
					flag = true;
				}
				else
				{
					read >> temp;
				}
			}

			//сортуЇмо дл€ нормального виводу на екран
			vector<pair<string, int>> vec;
			// copy key-value pairs from the map to the vector
			// дивилась зв≥дси -https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp
			map<string, int> ::iterator it2;
			for (it2 = userready.begin(); it2 != userready.end(); it2++)
			{
				vec.push_back(make_pair(it2->first, it2->second));
			}

			// sort the vector by increasing order of its pair's second value
			sort(vec.begin(), vec.end(), [](const pair<string, int>& a,
				const pair<string, int>& b)
				{
					return (a.second > b.second);
				});

			for (auto el : vec)
			{
				cout << setw(10) << el.first << "     -     " << el.second << endl;
			}
			cout << endl;
			cout << endl;

			system("pause");
			read.close();  //обов€зково закриваЇмо
		}
		else if (menu == 3) // просто зм≥нна кольору
		{
			system("cls");
			SetColor(14, 0);
			cout << "\n \t         -Settings-\n";
			SetColor(15, 0);

			bool choose = true, exit = true;
			char ch1;
			int tempcolor = 0;

			tempcolor = exec.color;
			cout << "\t Do you want change color of Menu?\n";
			cout << "\t           >  Yes < \n";
			cout << "\t              No\n";

			do
			{
				ch1 = _getch();

				switch (ch1)
				{
				case 72:
				{// нажата клавиша вверх
					system("cls");
					SetColor(14, 0);
					cout << "\n \t         -Settings-\n";
					SetColor(15, 0);
					cout << "\t Do you want change color of Menu?\n";
					cout << "\t           >  Yes < \n";
					cout << "\t              No\n";

					choose = true;
					break;
				}
				case 80:
				{// нажата клавиша вниз
					system("cls");
					SetColor(14, 0);
					cout << "\n \t         -Settings-\n";
					SetColor(15, 0);
					cout << "\t Do you want change color of Menu?\n";
					cout << "\t              Yes  \n";
					cout << "\t            > No <\n";
					choose = false;
					break;
				}
				case 13:
					exit = false;
					break;
				default:
					break;
				}
			} while (exit);

			if (choose)
			{
				system("cls");

				bool exit = false;
				int ch;
				int el = 1, max = 15;

				vector<string> strmenu{ " Blue ","   Green ", " Cyan ", " Red ", " Magenta "," Brown ",
					" LightGray ", " DarkGray ", " LightBlue ", " LightGreen "," LightCyan ", " LightRed ",
					" LightMagenta ", " Yellow ", " White " };

				SetColor(14, 0);
				cout << "\n \t\t\t -CHOOSE COLOR- \n";
				exec.SpecialPrint(strmenu, el, el);

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
							break;
						}
						default:
							break;
						}
						system("cls");
						SetColor(14, 0);
						cout << "\n \t\t\t -CHOOSE COLOR- \n";
						exec.SpecialPrint(strmenu, el, el);
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

				exec.color = el;

				if (exec.color < 0 || exec.color >15)
				{
					exec.color = 12;
				}
			}
			else
			{

			}

		}
		else  // 1v - к≥нець гри
		{
			exit = false;
			system("cls");
			SetColor(0, 14);
			cout << "\t\t Goodbye! Have a nice day ;)\n\n";
			SetColor(15, 0);
		}

	} while (exit);
}