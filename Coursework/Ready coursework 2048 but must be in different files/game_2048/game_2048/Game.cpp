#include "Game.h"

// встановлюЇ кол≥р текста ≥ фона в консол≥
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

// просто зчитуЇ
void Game_AI::keyPress()
{
	control = _getch();
}

//перев≥р€Ї зчитане та викликаЇ в≥дпов≥дн≥ методи
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
		execute->fillSpace();
		execute->updateGrid();
		execute->fillSpace();
		execute->findGreatestTile();
		execute->displayGrid();

		//програш
		if (execute->full() && apocal)
		{
			response = -1;
			break;
		}
		else if (execute->blockMoves())
		{
			execute->spawn(); //генеруЇмо нов≥ блоки
			break;
		}
		else
		{
			response = 0;
			break;
		}

	case 'r':
		execute->startGrid();  // нова гра
		score = 0;
		plus = 0;
		break;

	case 'q':  // вих≥д з гри
		response = -1;
		break;

	case 'h': // в≥дображеннф дов≥дки
		execute->displayHelpScreen();
		execute->displayGrid();
		break;
	case 'm': // перех≥д в меню
		response = -2;  
		break;
	}
}

//перев≥р€Ї чи виграв чи програв гравець + пропонуЇ зберегти результат + чи продовжити гру
bool Game_AI::gameEndCheck(Game* screen)  
{
	char answer = 'n';

	if (maximum == win) //перев≥рка на виграш
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

		char option = screen->displayTryAgainScreen(true);
		if (option == 'n')
		{
			cout << "\n\n\n\t    > Would you like go to menu(if you exit from game) ? (enter y if yes or n if no) ?  __";
			cin >> answer;

			if (answer == 'y')
			{
				response = -2;
			}
		}

		if (option == 'y')
		{
			screen->startGrid();
			response = 0;
		}
	}

	if (response == -2) //поверненн€ в меню
	{
		if (answer == 'n')
		{
			screen->displayLoserScreen();
		}
		response = 0;
		return true;
	}

	// 2v - к≥нц€ гри(≥ програми)
	if (response == -1)
	{
		SetColor(0, 14);
		cout << "\n\n\t\t            > Thank you for playing. \n";
		SetColor(15, 0);
		system("pause");
		exit(0);   //в stdlib завершуЇ повн≥стю виконанн€ програми
	}

	return false;
}

// готуЇ початкове поле(рандомить випадков≥ числа та заповнюЇ масив пол≥в)
//+ задаЇ зм≥ним рахунку та ≥ншим початков≥ значченн€
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

//в≥дображаЇ ф≥нальне поле що ми бачимо п≥д час гри (тобто поле гри, рахунок, назва та ≥нше)
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
	cout << "\n \t\tControls \t\tq - quit   r - restart\n\n\tW\t\t     ^\t\th - help   m - menu\n\t\t\t\t\t\t\t\t"
		<< " \n   A    S    D\t\t<    v    >\t\t\t     ."
		<< " \n\t\t\t\t                             ";
	SetColor(15, 0);
}

//рандомить ≥ повертаЇ число
int randomIndex(int x)
{
	int index;
	index = rand() % x + 0;

	return index;
}

// що теж очевидно з назви заповнюЇ прост≥р(поле)
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

// що очевидно з назви оновлюЇ поле, дивитьс€ чим заповненн€ control(тобто те що введенно з клав≥атури)
//та виконуЇ в≥дпов≥дн≥ д≥њ
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

// генеруЇ певн≥ випадков≥ числа та заповнюЇ ними
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

//знаходить значенн€ б≥льш≥ за максимум(зм≥нна публ≥чна класу)  та прир≥внюЇ до максимум
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

//перев≥р€Ї чи повне ≥ повертаЇ 1 або 0 взалежност≥ в≥д результату
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

// в≥дображаЇ справку €к необх≥дно грати тобто правила та п≥дказки
void Game::displayHelpScreen()
{
	system("cls");

	cout << endl << "  -  THE 2048  -\t\t\t\t\n";

	string text = "> The game starts with 1 or 2 randomly placed numbers in a 4x4 grid (16 cells).> Use the controls to move the cells. ( Press W/A/S/D or </^ and other.> 2 cells of the same number will merge and add up.> New 2s and 4s will appear randomly on an empty cell with each move you make.> Your objective is to make 2048 in a cell!> ";

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == '>')
		{
			cout << "\n\n\n";
		}

		cout << text[i];
	}
	system("pause");
}

// просто в≥дображаЇ екран перемоги та записуЇ результат гравц€
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

// аналог≥чно екрану перемоги просто в≥дображаЇ екран проте програшу та питаЇ записуЇ результат гравц€ за його бажанн€
void Game::displayLoserScreen()
{
	system("cls");
	char temp;

	cout << "\n\n\n\t\t\t  --- [ G A M E  O V E R ] --- " << "\n\n\n\n\t\t  Do you want save your resalt?(enter y if yes or n if no) ? __ ";
	cin >> temp;

	system("cls");
	if (temp == 'y')
	{
		cout << "\n\n\n\t\t\t  --- [ G A M E  O V E R ] --- " << "\n\n\n\n\t\t TILE\t     SCORE\t    NAME";
		cout << "\n\n\t\t\t " << maximum << "\t    " << score << "\t      ";
		cin >> name;
	}
	else
	{
		name = "anonym";
	}

	SetColor(15, 10);
	cout << "\n\n\t\t> You can more! I believe in you! ";
	SetColor(15, 0);
}

// питаЇ чи хоче гравець спробувати знову + тут записуЇ у файл ! результат гравц€
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
	//зразу п≥сл€ гри запис гравц€ ≥ його результату у текстовий файл
	write.open("Board_champ.txt", ios::app);  //в≥дкриваЇмо файл дл€ запису
	write << " " << name;
	write << " " << score << endl;
	write.close();  //закриваЇмо файл

	cin >> option;

	system("pause");
	system("cls");

	return option;
}

// (теж зрозум≥ло з назви) метод зм≥нюЇ позиц≥њ певних 'блок≥в'(значеннь)
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