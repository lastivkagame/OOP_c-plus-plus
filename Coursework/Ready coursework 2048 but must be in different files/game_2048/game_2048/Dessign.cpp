#include "Dessign.h"

void Dessign::FirstLoader() //������ ���� ����� ��������
{
	int b = 4, w = 12, temp;  //��� ������ �������

	for (int c = 0; c < 3; c++)
	{
		system("cls"); // ������� �����
		cout << endl;
		SetColor(b, 0); //������� ����

		char s = 254; // �� ��� �������� ����������(� ��� ���������� �����) 

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

		// ��� ���� ������ ��� ������� ��� ��� �������������
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

		// ����� �������
		if (c == 0) 
		{
			temp = b;
			b = w;
			w = temp;
		}

		Sleep(2000);
	}
	SetColor(15, 0);
	system("cls"); // ������� �����
	SetColor(15, 0);
}

int Dessign::Menu()
{
	system("cls");  // ������� �����
	cout << endl;
	SetColor(color, 0);

	Name();  //����� �� ������ �������� ��������(���)

	cout << endl;

	bool exit = false;  // ��� ������ � ���
	int ch;  //��� ���������� ���������
	int el = 1, maximum = 4; // �������� �������; �-��� �������� � ����  
	vector<string> strmenu{ " Start Game ","Table Resalt","  Settings  ", "    Exit    " };  //menu

	SpecialPrint(strmenu, el);  // ��� ������ ��������� ������� �����

	//��� ����
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
			{// ������ ������� �����

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
			{// ������ ������� ����

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
			system("cls"); // ������� �����
			Name();  // �������� �����
			SpecialPrint(strmenu, el);  // �������� �������� �������
			break;
		}
		case 13:  // ��� ������
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

void Dessign::Name() // ������ �������� ����� ���
{
	char s = 254;  // ��� ����������

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

void Dessign::SpecialPrint(vector<string> temp, int el, int color)  // ����� �� �������� �������� ������ �����(��� ������� ���� ��������) 
{
	int t = 1;

	for (int i = 0; i < temp.size(); i++)
	{
		if (t == el) // �������� ���� ������� �������
		{
			if (color == -1)  // �������� �� ������� ���� �� ������� ���� ������� ��������� ���������
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
			if (color == -1) // �������� �� ������� ���� �� ������� ���� ������� ��������� ���������
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
			if (color == -1) // �������� �� ������� ���� �� ������� ���� ������� ��������� ���������
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
