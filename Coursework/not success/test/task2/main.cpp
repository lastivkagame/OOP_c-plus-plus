#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <map>
using namespace std;

int pressEnter;
int randomIndex(int);

// кольори
enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

// встановлює колір текста і фона в консолі
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

class Dessign //клас у якому будуть картинки тобто перше завантаження, меню та інше 
{
public:
	int color = 12; //змінна для зміни кольору

	void FirstLoader() //просто вивід першої картинки
	{
		int b = 4, w = 12, temp;

		for (int c = 0; c < 3; c++)
		{
			system("cls");
			cout << endl;
			SetColor(b, 0); //змінюємо колір

			char s = 254;

			cout << endl;
			cout << endl;

			cout << setw(5) << "   " << s << " 2 0 4 8 " << s << "    " << s << " 2 0 4 8 " << s << "    " << s << "         " << s << "    " << s << " 2 0 4 8 " << s << "\n";
			cout << setw(5) << "   " << s << "         " << s << "    " << s << "         " << s << "    " << s << "         " << s << "    " << s << "         " << s << "\n";
			cout << setw(5) << "               " << s << "    " << s << "         " << s << "    " << s << "         " << s << "    " << s << "         " << s << "\n";
			cout << setw(5) << "               " << s << "    " << s << "         " << s << "    " << s << "         " << s << "    " << s << "         " << s << "\n";
			cout << setw(5) << "   " << s << " 2 0 4 8 " << s << "    " << s << "         " << s << "    " << s << " 2 0 4 8 " << s << "    " << s << " 2 0 4 8 " << s << "\n";
			cout << setw(5) << "   " << s << "              " << s << "         " << s << "              " << s << "    " << s << "         " << s << "\n";
			cout << setw(5) << "   " << s << "              " << s << "         " << s << "              " << s << "    " << s << "         " << s << "\n";
			cout << setw(5) << "   " << s << "              " << s << "         " << s << "              " << s << "    " << s << "         " << s << "\n";
			cout << setw(5) << "   " << s << " 2 0 4 8 " << s << "    " << s << " 2 0 4 8 " << s << "              " << s << "    " << s << " 2 0 4 8 " << s << "\n";

			cout << endl;
			cout << endl;

			if (c == 0)
			{
				cout << setw(46) << "   __________________   \n";
				cout << setw(45) << "  /                  \\ \n";
				cout << setw(46) << " |                  |  \n";
				cout << setw(46) << "  \\__________________/  \n";
				SetColor(14, 0);
				cout << setw(42) << " Loading ...  0 %\n";
			}

			if (c == 1)
			{
				cout << setw(46) << "   __________________   \n";
				cout << setw(24) << "  /";

				SetColor(14, 0);
				cout << "##########        ";
				SetColor(12, 0);
				cout << "\\ \n";
				cout << setw(24) << " |";
				SetColor(14, 0);
				cout << "##########        ";
				SetColor(12, 0);
				cout << "|  \n";
				cout << setw(24) << "  \\";
				SetColor(14, 0);
				cout << "##########";
				SetColor(12, 0);
				cout << "________/  \n";
				SetColor(14, 0);
				cout << setw(43) << " Loading ...  50 %\n";
			}

			if (c == 2)
			{
				cout << setw(46) << "   __________________   \n";
				cout << setw(24) << "  /";
				SetColor(14, 0);
				cout << "##################";
				SetColor(12, 0);
				cout << "\\ \n";
				cout << setw(24) << " |";
				SetColor(14, 0);
				cout << "##################";
				SetColor(12, 0);
				cout << "| \n";
				cout << setw(24) << "  \\";
				SetColor(14, 0);
				cout << "##################";
				SetColor(12, 0);
				cout << "/ \n";
				SetColor(14, 0);
				cout << setw(44) << " Loading ...  100 % \n";
			}

			if (c == 0)
			{
				temp = b;
				b = w;
				w = temp;
			}

			Sleep(2000);
		}
		SetColor(15, 0);
		system("cls");
		SetColor(15, 0);
	}

	int Menu()
	{
		system("cls");
		cout << endl;
		SetColor(color, 0);

		Name();  //метод що просто аиводить картинку

		cout << endl;

		bool exit = false;
		int ch;  //для зчитування введеного
		int el = 1, maximum = 4;
		vector<string> strmenu{ " Start Game ","Table Resalt","  Settings  ", "    Exit    " };

		SpecialPrint(strmenu, el);  // для виводу виділеного певного рядку

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

					if (el == maximum)
					{
						el--;
					}
					else if (el == 0)
					{
						el = maximum;
					}
					else
					{
						el--;

						if (el == 0)
						{
							el = maximum;
						}
					}
					break;
				}
				case 80:
				{// нажата клавиша вниз

					if (el == maximum)
					{
						el = 1;
					}
					else if (el == 0)
					{
						el = maximum;
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
				Name();
				SpecialPrint(strmenu, el);
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

		SetColor(12, 0);
		SetColor(15, 0);
		return el;
	}

	void Name() // просто відображає назву гри
	{
		char s = 254;

		cout << endl;
		cout << endl;
		SetColor(color, 0);
		cout << setw(5) << "   " << s << " 2 0 4 8 " << s << "    " << s << " 2 0 4 8 " << s << "    " << s << "         " << s << "    " << s << " 2 0 4 8 " << s << "\n";
		cout << setw(5) << "   " << s << "         " << s << "    " << s << "         " << s << "    " << s << "         " << s << "    " << s << "         " << s << "\n";
		cout << setw(5) << "               " << s << "    " << s << "         " << s << "    " << s << "         " << s << "    " << s << "         " << s << "\n";
		cout << setw(5) << "               " << s << "    " << s << "         " << s << "    " << s << "         " << s << "    " << s << "         " << s << "\n";
		cout << setw(5) << "   " << s << " 2 0 4 8 " << s << "    " << s << "         " << s << "    " << s << " 2 0 4 8 " << s << "    " << s << " 2 0 4 8 " << s << "\n";
		cout << setw(5) << "   " << s << "              " << s << "         " << s << "              " << s << "    " << s << "         " << s << "\n";
		cout << setw(5) << "   " << s << "              " << s << "         " << s << "              " << s << "    " << s << "         " << s << "\n";
		cout << setw(5) << "   " << s << "              " << s << "         " << s << "              " << s << "    " << s << "         " << s << "\n";
		cout << setw(5) << "   " << s << " 2 0 4 8 " << s << "    " << s << " 2 0 4 8 " << s << "              " << s << "    " << s << " 2 0 4 8 " << s << "\n";

		cout << endl;
		cout << endl;
		cout << endl;
	}

	void SpecialPrint(vector<string> temp, int el)  // метод що виводить виділеним певний рядок(щоб зробити вибір стрілками) 
	{
		int t = 1;

		for (int i = 0; i < temp.size(); i++)
		{
			if (t == el)
			{
				SetColor(color, 0);
				cout << setw(23) << setfill('=') << " >" << temp[i];
			}
			else
			{
				SetColor(4, 0);
				cout << setw(35) << temp[i];
			}

			if (t == el)
			{
				SetColor(color, 0);
				cout << " < " << setw(23) << setfill('=') << " ";
			}

			cout << setfill(' ') << setw(1) << endl;
			t++;
		}
	}
};

class Game;

class Game_AI
{
private:
	int response;  //відповідь
	int apocal;
	char control; // для зчитування певного сиволу
public:
	int maximum;
	int win;  
	int plus;   // те що додається до рахунку за останній хід
	int score;  
	int grid[4][4];   // сітка(поле)
	int bgrid[4][4];

	Game_AI() : score(0), plus(0), win(2048), maximum(0), response(0), apocal(1) {}

	//названі так що відображають те що роблять
	void logicFlow(Game*);
	void gameEndCheck(Game*);
	void keyPress();  
	void startGrid();
	void updateGrid();
	void fillSpace();
	void spawn();
	void findGreatestTile();
	void backupGrid();

	int full();
	int blockMoves();
};

class Game : public Game_AI, public Dessign  // має вже більш конкретні методи  
{					//фактично там є метод який і відповідає за гру тобто без початку і меню тільки поле + ігровий процес
private:
	char option;
	string name;
public:
	void displayGrid();
	void displayHelpScreen();
	void displayWinScreen();
	void displayLoserScreen();
	char displayTryAgainScreen(int);
};

class Game_Assemblage //фінальний клас який містить лише одну статичний метод )  
{				//який і починає збірку всієї гри тобто це дає повністю готову гру 
public:				//лише викликаєш і початок + меню + гра + (запис результатів та все інше ...

	static void StartProgram()
	{
		Game exec;
		exec.FirstLoader();

		// для зчитування та запису
		ifstream read;  
		ofstream write;

		// для ввиводу результатів
		string nameuser;  
		map<string, int> userready;

		int menu;
		bool exit = true;

		do
		{
			menu = exec.Menu();

			if (menu == 1)
			{
				exec.startGrid();

				while (true)
				{
					exec.displayGrid();
					exec.keyPress();
					exec.logicFlow(&exec);
					exec.gameEndCheck(&exec);
				};
			}
			else if (menu == 2)
			{
				system("cls");

				string temp;
				int temp2;

				read.open("Board_champ.txt");  //відкриваємо файл для запису
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
							userready.insert({ temp, temp2 });   //зчитуємо
						}
						flag = true;
					}
					else
					{
						read >> temp;
					}
				}

				//сортуємо для нормального виводу на екран
				vector<pair<string, int>> vec;
				// copy key-value pairs from the map to the vector
				// дивилась звідси -https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp
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
				read.close();  //обовязково закриваємо
			}
			else if (menu == 3)
			{
				system("cls");
				SetColor(14, 0);
				cout << "\n \t\t-Settings-\n";
				SetColor(15, 0);

				bool choose = true, exit = true;
				char ch1;
				int tempcolor = 0;

				tempcolor = exec.color;
				cout << "\t Do you want change color of Menu?\n";
				cout << "\t           >  Yes < \n";
				cout << "\t               No\n";

				do
				{
					ch1 = _getch();

					switch (ch1)
					{
					case 72:
					{// нажата клавиша вверх
						system("cls");
						SetColor(14, 0);
						cout << "\n \t\t-Settings-\n";
						SetColor(15, 0);
						cout << "\t Do you want change color of Menu?\n";
						cout << "\t           >  Yes < \n";
						cout << "\t               No\n";

						choose = true;
						break;
					}
					case 80:
					{// нажата клавиша вниз
						system("cls");
						SetColor(14, 0);
						cout << "\n \t\t-Settings-\n";
						SetColor(15, 0);
						cout << "\t Do you want change color of Menu?\n";
						cout << "\t              Yes  \n";
						cout << "\t             > No <\n";
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

					cout << "\n \t\t     -CHOOSE COLOR- \n";
					exec.SpecialPrint(strmenu, el);

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
							cout << "\n \t     -CHOOSE COLOR- \n";
							exec.SpecialPrint(strmenu, el);
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
			else  // 1v - кінець гри
			{
				exit = false;
				system("cls");
				SetColor(0, 14);
				cout << "\t\t Goodbye! Have a nice day ;)\n\n";
				SetColor(15, 0);
			}

		} while (exit);
	}
};

int main()
{
	srand(time(NULL));

	Game_Assemblage::StartProgram();

	return 0;
}

void Game_AI::keyPress()
{
	control = _getch();
}

void Game_AI::logicFlow(Game* execute)
{

	switch (control)
	{
	case 'w':
	case 'a':
	case 's':
	case 'd':
	case 72:
	case 75:
	case 77:
	case 80:
		execute->backupGrid();
		execute->fillSpace();
		execute->updateGrid();
		execute->fillSpace();
		execute->findGreatestTile();
		execute->displayGrid();

		if (execute->full() && apocal)
		{
			response = -1;
			break;
		}
		else if (execute->blockMoves())
		{
			execute->spawn();
			break;
		}
		else
		{
			response = 0;
			break;
		}

	case 'r':
		execute->startGrid();
		score = 0;
		plus = 0;
		break;

	case 'q':
		response = -1;
		break;

	case 'h':
		execute->displayHelpScreen();
		pressEnter = getchar();
		execute->displayGrid();
		break;
	}
}

void Game_AI::gameEndCheck(Game* screen)
{
	if (maximum == win)
	{
		screen->displayWinScreen();

		if (screen->displayTryAgainScreen(0) == 'n')
		{
			response = -1;
		}
		else
		{
			win *= 2;
		}
	}

	else if (response == -1)
	{
		screen->displayLoserScreen();

		if (screen->displayTryAgainScreen(1) == 'y')
		{
			screen->startGrid();
			response = 0;
		}
	}

	// 2d - кінця гри
	if (response == -1)
	{
		SetColor(0, 14);
		cout << "\n\n\t\t            > Thank you for playing. \n";
		SetColor(15, 0);
		system("pause");
		exit(0);
	}
}

void Game_AI::startGrid()
{
	int i, j;

	plus = 0;
	score = 0;
	maximum = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			grid[i][j] = 0;
		}
	}

	i = randomIndex(4);
	j = randomIndex(4);

	grid[i][j] = 2;

	i = randomIndex(4);
	j = randomIndex(4);

	grid[i][j] = 2;
}

void Game::displayGrid()
{
	system("cls");

	SetColor(7, 8);
	char s = 254;
	char d = 178;

	char u = 205;
	char lr = 186;

	char ru = 201;
	char rd = 200;
	char lu = 187;
	char ld = 188;

	cout << " " << setfill(' ') << setw(63) << " " << endl;
	cout << " " << ru << setfill(u) << setw(38) << u << lu << setfill(' ') << setw(10) << ru << setfill(u) << setw(13) << lu << endl;
	cout << " " << lr << "  " << s << " " << s << " " << s << " " << s << "  " << s << " " << s << " " << s << " " << s << "  " << s << "     " << s << "  " << s << " " << s << " " << s << " " << s << "  " << lr << setfill(' ') << setw(10) << lr << setw(13) << lr << endl;
	cout << " " << lr << "       " << s << "   " << s << "     " << s << "  " << s << "     " << s << "  " << s << "     " << s << "  " << lr << setfill(' ') << setw(10) << lr << setw(9) << "-Your Score-" << lr << endl;
	cout << " " << lr << "      " << s << "    " << s << "     " << s << "  " << s << " " << s << " " << s << " " << s << "  " << s << " " << s << " " << s << " " << s << "  " << lr << setfill(' ') << setw(10) << lr << setw(12) << score << lr << endl;

	if (plus)
	{
		cout << " " << lr << "    " << s << "      " << s << "     " << s << "        " << s << "  " << s << "     " << s << "  " << lr << setfill(' ') << setw(10) << lr << setw(3) << "+" << setw(8) << plus << "!" << lr << endl;
	}
	else
	{
		cout << " " << lr << "    " << s << "      " << s << "     " << s << "        " << s << "  " << s << "     " << s << "  " << lr << setfill(' ') << setw(10) << lr << setw(13) << lr << endl;
	}

	cout << " " << lr << "  " << s << " " << s << " " << s << " " << s << "  " << s << " " << s << " " << s << " " << s << "        " << s << "  " << s << " " << s << " " << s << " " << s << "  " << lr << setfill(' ') << setw(10) << lr << " " << setw(12) << lr << endl;
	cout << " " << rd << setfill(u) << setw(38) << u << ld << setfill(' ') << setw(10) << rd << setfill(u) << setw(13) << ld << endl;

	cout << setfill(' ') << setw(64) << " " << endl;

	cout << setfill(' ') << setw(3) << " ";

	SetColor(15, 15);
	cout << setfill(' ') << setw(58) << " ";

	SetColor(7, 8);
	cout << "   " << endl;

	SetColor(15, 0);

	for (int i = 0; i < 4; i++)
	{
		SetColor(7, 8);
		cout << "   ";
		SetColor(15, 15);
		cout << " |";
		SetColor(15, 0);

		for (int j = 0; j < 4; j++)
		{
			if (grid[i][j])
			{
				SetColor(15, 7);
				cout << setw(10) << grid[i][j] << " | ";
				SetColor(15, 0);
			}
			else
			{
				SetColor(15, 7);
				cout << setw(10) << " " << " | ";
				SetColor(15, 0);
			}
		}

		SetColor(7, 7);
		cout << "  ";
		SetColor(15, 15);
		cout << "  ";
		SetColor(7, 8);
		cout << "   \n";

		for (int h = 0; h < 2; h++)
		{
			SetColor(7, 8);
			cout << "   ";

			SetColor(15, 15);
			cout << "  ";

			SetColor(15, 7);
			cout << setfill(' ') << setw(54) << " ";

			SetColor(15, 15);
			cout << "  ";

			SetColor(7, 8);
			cout << "   \n";

			SetColor(15, 0);
		}
	}

	SetColor(7, 8);
	cout << "   ";

	SetColor(15, 15);
	cout << setfill(' ') << setw(58) << " ";

	SetColor(7, 8);
	cout << "   " << endl;

	SetColor(15, 0);

	SetColor(15, 0);

	SetColor(14, 0);
	cout << "\n \t\tControls \t\tq - quit   r - restart\n\n\tW\t\t     ^\t\th - help           \n\t\t\t\t\t\t\t\t"
		<< " \n   A    S    D\t\t<    v    >\t\t\t     ."
		<< " \n\t\t\t\t                             ";
	SetColor(15, 0);
}

int randomIndex(int x)
{
	int index;
	index = rand() % x + 0;

	return index;
}

void Game_AI::backupGrid()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			bgrid[i][j] = grid[i][j];
		}
	}
}

void Game_AI::fillSpace()
{
	switch (control)
	{
	case 'w':
	case 72:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (!grid[j][i])
				{
					for (int k = j + 1; k < 4; k++)
					{
						if (grid[k][i])
						{
							grid[j][i] = grid[k][i];
							grid[k][i] = 0;
							break;
						}
					}
				}
			}
		}
		break;
	case 's':
	case 80:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j >= 0; j--)
			{
				if (!grid[j][i])
				{
					for (int k = j - 1; k >= 0; k--)
					{
						if (grid[k][i])
						{
							grid[j][i] = grid[k][i];
							grid[k][i] = 0;
							break;
						}
					}
				}
			}
		}
		break;
	case 'a':
	case 75:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (!grid[i][j])
				{
					for (int k = j + 1; k < 4; k++)
					{
						if (grid[i][k])
						{
							grid[i][j] = grid[i][k];
							grid[i][k] = 0;
							break;
						}
					}
				}
			}
		}
		break;
	case 'd':
	case 77:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j >= 0; j--)
			{
				if (!grid[i][j])
				{
					for (int k = j - 1; k >= 0; k--)
					{
						if (grid[i][k])
						{
							grid[i][j] = grid[i][k];
							grid[i][k] = 0;
							break;
						}
					}
				}
			}
		}
		break;
	}
}

void Game_AI::updateGrid()
{
	plus = 0;
	apocal = 1;

	switch (control)
	{
	case 'w':
	case 72:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[j][i] && grid[j][i] == grid[j + 1][i])
				{
					apocal = 0;
					grid[j][i] += grid[j + 1][i];
					grid[j + 1][i] = 0;
					plus += (((log2(grid[j][i])) - 1) * grid[j][i]);
					score += (((log2(grid[j][i])) - 1) * grid[j][i]);

				}
			}
		}
		break;
	case 's':
	case 80:
		for (int i = 0; i < 4; i++)
			for (int j = 3; j > 0; j--)
			{
				if (grid[j][i] && grid[j][i] == grid[j - 1][i])
				{
					apocal = 0;
					grid[j][i] += grid[j - 1][i];
					grid[j - 1][i] = 0;
					plus += (((log2(grid[j][i])) - 1) * grid[j][i]);
					score += (((log2(grid[j][i])) - 1) * grid[j][i]);
				}
			}break;

	case 'a':
	case 75:
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j] && grid[i][j] == grid[i][j + 1])
				{
					apocal = 0;
					grid[i][j] += grid[i][j + 1];
					grid[i][j + 1] = 0;
					plus += ((log2(grid[i][j])) - 1) * grid[i][j];
					score += ((log2(grid[i][j])) - 1) * grid[i][j];
				}
			}break;

	case 'd':
	case 77:
		for (int i = 0; i < 4; i++)
			for (int j = 3; j > 0; j--)
			{
				if (grid[i][j] && grid[i][j] == grid[i][j - 1])
				{
					apocal = 0;
					grid[i][j] += grid[i][j - 1];
					grid[i][j - 1] = 0;
					plus += ((log2(grid[i][j])) - 1) * grid[i][j];
					score += (((log2(grid[i][j])) - 1) * grid[i][j]);
				}
			}
		break;
	}
}

void Game_AI::spawn()
{
	int i, j, k;

	do
	{
		i = randomIndex(4);
		j = randomIndex(4);
		k = randomIndex(10);

	} while (grid[i][j]);

	if (k < 2)
	{
		grid[i][j] = 4;
	}
	else
	{
		grid[i][j] = 2;
	}
}

void Game_AI::findGreatestTile()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (grid[i][j] > maximum)
			{
				maximum = grid[i][j];
			}
		}
	}
}

int Game_AI::full()
{
	int k = 1;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (!grid[i][j])
			{
				k = 0;
			}

		}
	}
	return k;
}

void Game::displayHelpScreen()
{
	system("cls");

	cout << endl << "  -  THE 2048  -\t\t\t\t\n";

	string text = "> The game starts with 1 or 2 randomly placed numbers in a 4x4 grid (16 cells).> Use the controls to move the cells. ( Press W/A/S/D or </^/v/>)> 2 cells of the same number will merge and add up.> New 2s and 4s will appear randomly on an empty cell with each move you make.> Your objective is to make 2048 in a cell!> ";

	for (int i = 0; text.size(); i++)
	{
		if (text[i] == '>')
		{
			cout << "\n\n\n";
		}

		cout << text[i];
	}
	system("pause");
}

void Game::displayWinScreen()
{
	system("cls");

	cout << endl << endl;
	cout << "\n\t\t\t  - [  YOU MADE " << win << "!  ] -" << "\n\n\t\t\t  - [ YOU WON THE GAME ] -" << "\n\n\n\n\t\t\t TILE\t     SCORE\t    NAME";
	cout << "\n\n\t\t\t " << maximum << "\t    " << score << "\t       ";
	cin >> name;

	SetColor(14, 15);
	cout << "\n\n\t\t\t> Good work! So go on :)";
	SetColor(15, 0);
}

void Game::displayLoserScreen()
{
	system("cls");

	cout << "\n\n\n\t\t\t  --- [ G A M E  O V E R ] --- " << "\n\n\n\n\t\t\t TILE\t     SCORE\t    NAME";
	cout << "\n\n\t\t\t " << maximum << "\t    " << score << "\t      ";
	cin >> name;

	SetColor(15, 10);
	cout << "\n\n\t\t> You can more! I believe in you! ";
	SetColor(15, 0);
}

char Game::displayTryAgainScreen(int lose)
{
	if (lose)
	{
		cout << "\n\n\n\t    > Would you like to try again " << name << " (enter y if yes or n if no) ? __";
	}
	else
	{
		cout << "\n\n\n\t    > Would you like to continue playing " << name << " (enter y if yes or n if no) ?  __";
	}

	ofstream write;
	//зразу після гри запис гравця і його результату у текстовий файл
	write.open("Board_champ.txt", ios::app);  //відкриваємо файл для запису
	write << " " << name;
	write << " " << score << endl;
	write.close();  //закриваємо файл

	cin >> option;
	system("pause");
	system("cls");

	return option;
}

int Game_AI::blockMoves()
{
	int k = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (bgrid[i][j] != grid[i][j])
			{
				k = 1;
				break;
			}
		}
	}
	return k;
}
