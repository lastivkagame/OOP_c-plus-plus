#include "Dessign.h"

void Dessign::FirstLoader() //просто вивід першої картинки
{
	int b = 4, w = 12, temp;  //для певних кольорів

	for (int c = 0; c < 3; c++)
	{
		system("cls"); // очищаємо екран
		cout << endl;
		SetColor(b, 0); //змінюємо колір

		char s = 254; // це код простого квадратика(з них складається назва) 

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

		// для того просто щоб зробити ніби гра завантажується
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

		// змінює кольори
		if (c == 0) 
		{
			temp = b;
			b = w;
			w = temp;
		}

		Sleep(2000);
	}
	SetColor(15, 0);
	system("cls"); // очищаємо екран
	SetColor(15, 0);
}

int Dessign::Menu()
{
	system("cls");  // очищаємо екран
	cout << endl;
	SetColor(color, 0);

	Name();  //метод що просто виводить картинку(імя)

	cout << endl;

	bool exit = false;  // для виходу з гри
	int ch;  //для зчитування введеного
	int el = 1, maximum = 4; // вибраний елемент; к-сть елементів в меню  
	vector<string> strmenu{ " Start Game ","Table Resalt","  Settings  ", "    Exit    " };  //menu

	SpecialPrint(strmenu, el);  // для виводу виділеного певного рядку

	//сам вибір
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
			system("cls"); // ощищаємо екран
			Name();  // виводимо назву
			SpecialPrint(strmenu, el);  // виділяємо вибраний елемент
			break;
		}
		case 13:  // для виходу
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
	char s = 254;  // код квадратика

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

void Dessign::SpecialPrint(vector<string> temp, int el, int color)  // метод що виводить виділеним певний рядок(щоб зробити вибір стрілками) 
{
	int t = 1;

	for (int i = 0; i < temp.size(); i++)
	{
		if (t == el) // перевірка який елемент виділяти
		{
			if (color == -1)  // перевірка чи вказали колір чи зробити його певного початково значчення
			{
				SetColor(12, 0);
			}
			else
			{
				SetColor(color, 0);
			}
			cout << setw(23) << setfill('=') << " >" << temp[i];
		}
		else
		{
			if (color == -1) // перевірка чи вказали колір чи зробити його певного початково значчення
			{
				SetColor(4, 0);
			}
			else
			{
				SetColor(color, 0);
			}
			cout << setw(35) << temp[i];
		}

		if (t == el)
		{
			if (color == -1) // перевірка чи вказали колір чи зробити його певного початково значчення
			{
				SetColor(12, 0);
			}
			else
			{
				SetColor(color, 0);
			}

			cout << " < " << setw(23) << setfill('=') << " ";
		}

		cout << setfill(' ') << setw(1) << endl;
		t++;
	}
}
