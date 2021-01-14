#include "dessign.h"

void Dessign::FirstLoader() //просто вивід першої картинки
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

int Dessign::Menu()
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

void Dessign::Name() // просто відображає назву гри
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

void Dessign::InGame() // виводить назву і рахунок очок під час гри
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

void Dessign::SpecialPrint(vector<string> temp, int el)  // щоб зробити вибір стрілками
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