#include "BusList.h"
#include <windows.h>
#include <conio.h>

BusList::BusList()
{
	pHead = pTail = nullptr;
}

//     + elements
void BusList::AddHead(string number, string driver, int numRoute)
{
	Bus* temp = new Bus(number, driver, numRoute);

	if (pHead != nullptr)
	{
		temp->pNext = pHead;
		temp->pPrev = nullptr;
		temp->pNext->pPrev = temp;
		pHead = temp;
	}
	else
	{
		pHead = pTail = temp;
	}
}

void BusList::AddTail(string number, string driver, int numRoute)
{
	Bus* temp = new Bus(number, driver, numRoute);

	if (pHead != nullptr)
	{
		temp->pPrev = pTail;
		temp->pNext = nullptr;
		temp->pNext->pPrev = temp;
		pTail = temp;
	}
	else
	{
		pHead = pTail = temp;
	}
}

void BusList::Insert(string after, string number, string driver, int numRoute)
{
	if (SearchElement(after))
	{
		Bus* temp = pHead;
		Bus* forInsert = new Bus(number, driver, numRoute);

		while (temp->number != after)
		{
			temp = temp->pNext;
		}

		forInsert->pNext = temp->pNext;
		temp->pNext = forInsert;
		forInsert->pPrev = temp;
		forInsert->pNext->pPrev = forInsert;
	}
}


//   - elements
void BusList::DelTail()
{
	if (pTail != nullptr)
	{
		if (pTail->pPrev == nullptr)
		{
			pTail = nullptr;
		}
		else
		{
			Bus* temp = pTail->pPrev;
			temp->pNext = nullptr;
			pTail = temp;
		}
	}
}

void BusList::DelHead()
{
	if (pHead != nullptr)
	{
		if (pHead != pTail)
		{
			Bus* temp = pHead;
			pHead = pHead->pNext;
			pHead->pPrev = nullptr;
			delete temp;
		}
		pHead = pTail = nullptr;
	}
}

void BusList::DelCurrent(int el)
{
	Bus* temp = pHead;

	for (int i = 1; i < el; i++)
	{
		temp = temp->pNext;
	}

	if (temp == pHead)
	{
		DelHead();
	}
	else if (temp == pTail)
	{
		DelTail();
	}
	else
	{
		temp->pPrev->pNext = temp->pNext;
		temp->pNext->pPrev = temp->pPrev;
	}
}

string BusList::GetNumber(int el)
{
	Bus* temp = pHead;
	int i = 1;

	while (temp != nullptr)
	{
		if (i == el)
		{
			return (temp->number);
		}
		i++;
		temp = temp->pNext;
	}

	return "? - something went wrong\n";
}

//  get '(rs)
string BusList::GetDriver(int el)
{
	Bus* temp = pHead;
	int i = 1;

	while (temp != nullptr)
	{
		if (i == el)
		{
			return (temp->driver);
		}
		i++;
		temp = temp->pNext;
	}

	return "? - something went wrong\n";
}

int BusList::GetnumRoute(int el)
{
	Bus* temp = pHead;
	int i = 1;

	while (temp != nullptr)
	{
		if (i == el)
		{
			return temp->numRoute;
		}
		i++;

		temp = temp->pNext;
	}
	return -1;
}


// others
bool BusList::SearchElement(string el) const
{
	Bus* temp = pHead;

	while (temp != nullptr)
	{
		if (temp->number == el)
		{
			return true;
		}

		temp = temp->pNext;
	}
}

void BusList::Clear()
{
	while (pTail != nullptr)
	{
		DelTail();
	}
}

void BusList::Print() const
{
	Bus* temp = pHead;
	int i = 1;

	while (temp != nullptr)
	{
		cout << " " << i++ << " Bus # " << temp->number << "; driver: " << temp->driver << "; numRoute: " << temp->numRoute << "\n";
		temp = temp->pNext;
	}
	cout << endl;
}

void BusList::SpesPrint(int el)
{
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	Bus* temp = pHead;
	int t = 1;

	system("cls");

	while (temp != nullptr)
	{
		if (t == el)
		{
			SetConsoleTextAttribute(hOUTPUT, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << " > ";
		}

		cout << " Bus # " << temp->number << "; driver: " << temp->driver << "; numRoute: " << temp->numRoute << "\n";
		temp = temp->pNext;

		if (t == el)
		{
			SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}

		t++;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << " You can use:\n";
	cout << "   strilku \n";
	cout << "  ^(up)   and  (down)   \n";
	cout << endl;
}

int BusList::choose()
{
	bool exit = false;
	int ch;
	int el = 1, max = 0;

	Bus* temp = pHead;
	while (temp != nullptr)
	{
		temp = temp->pNext;
		max++;
	}

	int tchoose;
	cout << " How you want to choose bus: \n";
	cout << " 1 - enter number\n";
	cout << " 2 - choose (strilkamu)\n";
	cin >> tchoose;

	if (tchoose == 1)
	{
		system("cls");
		Print();
		cout << endl;
		cout << "Answer: ";
		cin >> el;
	}
	else
	{
		SpesPrint(el);

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

					SpesPrint(el);
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

					SpesPrint(el);

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
	}

	return (el--);
}
