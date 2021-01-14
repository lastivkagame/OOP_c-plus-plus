#include <iostream>
#include <ctime>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
using namespace std;

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
	int score = 0;  //рахунок
	int bestscore = 0;  // найкращий результат одного гравця
	int color = 12;

	void FirstLoader() //просто вивід першої картинки
	{
		int b = 4, w = 12, temp;

		for (int c = 0; c < 3; c++)
		{
			system("cls");
			cout << endl;
			SetColor(b, 0);

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

		Name();

		cout << endl;

		bool exit = false;
		int ch;
		int el = 1, max = 4;
		vector<string> strmenu{ " Start Game ","Table Resalt","  Settings  ", "    Exit    " };

		SpecialPrint(strmenu, el);

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

	void InGame() // виводить назву і рахунок очок під час гри
	{
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
		cout << " " << lr << "  " << s << " " << s << " " << s << " " << s << "  " << s << " " << s << " " << s << " " << s << "  " << s << "     " << s << "  " << s << " " << s << " " << s << " " << s << "  " << lr << setfill(' ') << setw(10) << lr << "-Your Score-" << lr << endl;
		cout << " " << lr << "       " << s << "   " << s << "     " << s << "  " << s << "     " << s << "  " << s << "     " << s << "  " << lr << setfill(' ') << setw(10) << lr << " " << setw(11) << score << lr << endl;
		cout << " " << lr << "      " << s << "    " << s << "     " << s << "  " << s << " " << s << " " << s << " " << s << "  " << s << " " << s << " " << s << " " << s << "  " << lr << setfill(' ') << setw(10) << lr << setfill(u) << setw(13) << lr << endl;
		cout << " " << lr << "    " << s << "      " << s << "     " << s << "        " << s << "  " << s << "     " << s << "  " << lr << setfill(' ') << setw(10) << lr << "-Best Score-" << lr << endl;
		cout << " " << lr << "  " << s << " " << s << " " << s << " " << s << "  " << s << " " << s << " " << s << " " << s << "        " << s << "  " << s << " " << s << " " << s << " " << s << "  " << lr << setfill(' ') << setw(10) << lr << " " << setw(11) << bestscore << lr << endl;
		cout << " " << rd << setfill(u) << setw(38) << u << ld << setfill(' ') << setw(10) << rd << setfill(u) << setw(13) << ld << endl;

		cout << setfill(' ') << setw(64) << " " << endl;

		SetColor(15, 0);
	}

	void SpecialPrint(vector<string> temp, int el)  // щоб зробити вибір стрілками
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
				SetColor(12, 0);
				cout << " < " << setw(23) << setfill('=') << " ";
			}

			cout << setfill(' ') << setw(1) << endl;
			t++;
		}
	}
};

class Logic :public Dessign
{
private:
	int board[4][4]; // поле, дошка гри 
	int dirLine[4] = { 1, 0, -1, 0 };
	int dirColumn[4] = { 0, 1 ,0, -1 };
public:
	int lose = 0;

	pair<int, int>generateUnocccupiedPosition()  // для того щоб генерувати і по горизонталі і по вертикалі
	{
		int occupied = 1, line, column;
		while (occupied)
		{
			line = rand() % 4;
			column = rand() % 4;

			if (board[line][column] == 0)
			{
				occupied = 0;
			}
		}

		return make_pair(line, column);
	}

	void addPiace() // додає під час гри рандомно нову 2 на екрані
	{
		pair<int, int>pos = generateUnocccupiedPosition();
		board[pos.first][pos.second] = 2;
	}

	void newGame() // дозволяє почати нову гру
	{
		score = 0;
		lose = 0;

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				board[i][j] = 0;
			}
		}

		addPiace();
	}

	void printUI()  // виводить на екран ігрове поле 
	{
		InGame();
		char s = 254;
		for (int i = 0; i < 4; ++i)
		{
			SetColor(7, 8);
			cout << "       ";

			SetColor(8, 7);
			cout << setfill(' ') << setw(45) << " ";

			SetColor(7, 8);
			cout << "            " << endl;

			SetColor(7, 8);
			cout << "       ";
			for (int j = 0; j < 4; ++j)
			{
				if (board[i][j] == 0)
				{
					SetColor(15, 0);
					cout << setw(9);
					SetColor(15, 7);
					cout << s;
					SetColor(15, 0);
				}
				else
				{
					SetColor(15, 0);
					cout << setw(9);
					SetColor(15, 7);
					cout << board[i][j];
					SetColor(15, 0);
				}
			}
			SetColor(15, 7);
			cout << "         ";
			SetColor(7, 8);
			cout << "            ";
			SetColor(15, 0);
			cout << endl;

			SetColor(7, 8);
			cout << "       ";

			SetColor(8, 7);
			cout << setfill(' ') << setw(45) << " ";

			SetColor(7, 8);
			cout << "            " << endl;
		}
		SetColor(7, 8);
		cout << setfill(' ') << setw(64) << " " << endl;
		SetColor(14, 8);
		cout << " HOW TO PLAY: Use your arrow keys to move the tiles." << setw(12) << " " << endl;
		cout << " When two tiles with the same number touch, they merge into one!\n";
		cout << setfill(' ') << setw(64) << " " << endl;
		cout << setfill(' ') << setw(38) << " --- Also Use ---" << setfill(' ') << setw(26) << " " << endl;
		cout << setfill(' ') << setw(37) << " -n: new game- " << setfill(' ') << setw(27) << " " << endl;
		cout << setfill(' ') << setw(35) << "-q: quit- " << setfill(' ') << setw(29) << " " << endl;
		cout << setfill(' ') << setw(64) << " " << endl;
		SetColor(15, 0);
	}

	bool canDoMove(int line, int column, int nextLine, int nextColumn) // перевіряє чи можна змінити положення цифрі
	{
		if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 ||
			(board[line][column] != board[nextLine][nextColumn] && board[nextLine][nextColumn] != 0))
		{
			return false;
		}
		return true;
	}

	void applyMove(int direction)  // змінює положення деяких чисел які можна 
	{
		int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;
		lose = 0;

		if (direction == 0)
		{
			startLine = 3;
			lineStep = -1;
		}

		if (direction == 1)
		{
			startColumn = 3;
			columnStep = -1;
		}

		int movePossible = 0, canAddPiace = 0;
		do
		{
			movePossible = 0;

			for (int i = startLine; i >= 0 && i < 4; i += lineStep)
			{
				for (int j = startColumn; j >= 0 && j < 4; j += columnStep)
				{
					int nextI = i + dirLine[direction], nextJ = j + dirColumn[direction];
					if (board[i][j] && canDoMove(i, j, nextI, nextJ))
					{
						board[nextI][nextJ] += board[i][j];

						board[i][j] = 0;
						movePossible = canAddPiace = 1;
					}

					if (!(canDoMove(i, j, nextI, nextJ)))
					{
						lose++;
					}
				}
			}

			score = -2;

			for (int i = startLine; i >= 0 && i < 4; i += lineStep)
			{
				for (int j = startColumn; j >= 0 && j < 4; j += columnStep)
				{
					score += board[i][j];
					if (score > bestscore)
					{
						bestscore = score;
					}
				}
			}

			system("cls");
			printUI();  // для покрокового баччення переміщення цифр
		} while (movePossible);

		if (canAddPiace)  // оскільки здійснили рух то треба згенерувати нову 2
		{
			addPiace();
		}
	}

	void GameProsses() // обєднує все для самої гри лиш(не відповідає за меню ти решту виключно сам процес гри)
	{
		char commandToDir[248];
		commandToDir['s'] = 0;
		commandToDir['d'] = 1;
		commandToDir['w'] = 2;
		commandToDir['a'] = 3;
		newGame();

		while (true)
		{
			system("cls");
			printUI();
			char command;
			char ch = _getch();

			switch (ch)
			{
			case 72:
				// нажата клавиша вверх
				command = 'w';
				break;

			case 'w':
				// нажата клавиша вверх
				command = 'w';
				break;
			case 75:
				// нажата клавиша вниз
				command = 'a';
				break;

			case 's':
				// нажата клавиша вниз
				command = 's';
				break;

			case 77:
				// нажата клавиша вправо
				command = 'd';
				break;

			case 'd':
				// нажата клавиша вправо
				command = 'd';
				break;

			case 80:
				// нажата клавиша влево
				command = 's';
				break;

			case 'a':
				// нажата клавиша влево
				command = 'a';
				break;

			case 'n':
				// нажата клавиша влево
				newGame();
				command = ' ';
				break;

			case 'q':
				// нажата клавиша влево
				command = 'q';
				break;

			default:
				command = ' ';
				break;
			}

			if (command == 'q')
			{
				break;
			}
			else if (command == ' ')
			{

			}
			else
			{
				int currentDirection = commandToDir[command];
				applyMove(currentDirection);
			}
		}
	}
};

class Game : public Logic // клас який збирає все і відповідає за весь процес(також викликаючи те що треба з інших класів)
{
private:
	ifstream read;
	ofstream write;
	string nameuser;
	map<string, int> userready;
	int score;
public:
	void StartField()
	{
		FirstLoader();
		int menu;
		bool exit = true;

		do
		{
			menu = Menu();

			if (menu == 1)
			{
				GameProsses();

				int ch = 0;
				system("cls");

				bool choose = true, exit = true;
				cout << "\n\t Do you want save your resalt?\n";
				cout << "\t          >  Yes < \n";
				cout << "\t             No\n";

				do
				{
					ch = _getch();

					switch (ch)
					{
					case 72:
					{// нажата клавиша вверх
						system("cls");
						cout << "\n\t Do you want save your resalt?\n";
						cout << "\t          >  Yes < \n";
						cout << "\t             No\n";

						choose = true;
						break;
					}
					case 80:
					{// нажата клавиша вниз
						system("cls");
						cout << "\n\t Do you want save your resalt?\n";
						cout << "\t             Yes\n";
						cout << "\t          >  No < \n";
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

					cout << "\n -Save resalts-\n";
					cout << " Enter your name: ";
					cin >> nameuser;

					system("cls");
					SetColor(10, 0);
					cout << "\n Congradulation! Your record save!\n";
					SetColor(15, 0);
					system("pause");

					//зразу після гри запис гравця і його результату у текстовий файл
					write.open("Board_champ.txt", ios::app);  //відкриваємо файл для запису
					write << " " << nameuser;
					write << " " << bestscore << endl;
					write.close();  //закриваємо файл

					system("cls");
				}
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
				while (!read.eof())
				{
					k++;
					if (k % 2 == 0)
					{
						read >> temp2;
						userready.insert({ temp, temp2 });   //зчитуємо
					}
					else
					{
						read >> temp;
					}
				}

				//сортуємо для нормального виводу на екран
				vector<pair<string, int>> vec;
				// copy key-value pairs from the map to the vector
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
				cout << "\t Do you want change color of Menu?\n";
				cout << "\t          >  Yes < \n";
				cout << "\t             No\n";

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
						cout << "\t          >  Yes < \n";
						cout << "\t             No\n";

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
						cout << "\t             Yes  \n";
						cout << "\t          >  No <\n";
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
					cout << "\n \t -CHOOSE COLOR- \n";
					cout << " Black = 0 \n Blue = 1 \n Green = 2 \n Cyan = 3 \n Red = 4 \n Magenta = 5 \n Brown = 6 ";
					cout << "\n LightGray = 7 \n DarkGray = 8 \n LightBlue = 9 \n LightGreen = 10 \n LightCyan = 11 ";
					cout << " \n LightRed = 12 \n LightMagenta = 13 \n Yellow = 14 \n White = 15\n";
					cout << " Answer: ";
					cin >> color;

					if (color < 0 || color >15)
					{
						color = 12;
					}

				}
				else
				{

				}

			}
			else  // кінець гри
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
	srand(time(nullptr));

	Game game;
	game.StartField();

	return 0;
}