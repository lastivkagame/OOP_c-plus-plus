#include "logic.h"

void Logic::addPiace() // додає під час гри рандомно нову 2 на екрані
{
	pair<int, int>pos = generateUnocccupiedPosition();
	board[pos.first][pos.second] = 2;
}

void Logic::newGame() // дозволяє почати нову гру
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

void Logic::printUI()  // виводить на екран ігрове поле 
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

bool Logic::canDoMove(int line, int column, int nextLine, int nextColumn) // перевіряє чи можна змінити положення цифрі
{
	if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 ||
		(board[line][column] != board[nextLine][nextColumn] && board[nextLine][nextColumn] != 0))
	{
		return false;
	}
	return true;
}

void Logic::applyMove(int direction)  // змінює положення деяких чисел які можна 
{
	int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;

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

					if (movePossible == 1)
					{
						score += board[i][j];
						if (score > bestscore)
						{
							bestscore = score;
						}
					}

					board[i][j] = 0;
					movePossible = canAddPiace = 1;
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

void Logic::GameProsses() // обєднує все для самої гри лиш(не відповідає за меню ти решту виключно сам процес гри)
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