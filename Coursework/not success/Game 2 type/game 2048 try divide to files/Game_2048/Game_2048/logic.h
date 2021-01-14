#include "dessign.h"

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

	void addPiace(); // додає під час гри рандомно нову 2 на екрані

	void newGame(); // дозволяє почати нову гру
	
	void printUI();  // виводить на екран ігрове поле 
	
	bool canDoMove(int line, int column, int nextLine, int nextColumn); // перевіряє чи можна змінити положення цифрі
	
	void applyMove(int direction);  // змінює положення деяких чисел які можна 
	
	void GameProsses(); // обєднує все для самої гри лиш(не відповідає за меню ти решту виключно сам процес гри)
	
};