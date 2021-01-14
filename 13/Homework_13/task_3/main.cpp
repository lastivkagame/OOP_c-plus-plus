/*3. Добавьте в класс двусвязного списка механизм обработки исключений.
На ваш выбор генерируйте исключения в случае ошибок.
Например, нехватка памяти, попытка удаления из пустого списка и т.д.*/

#include "DLL.h"
#include <exception>

int main() {

	DLList dllist;
	dllist.AddHead(1);
	dllist.AddHead(2);
	dllist.AddTail(3);

	cout << " --- dllist --- \n";
	dllist.Print();

	try
	{
		cout << " --- insert after --- \n";
		dllist.InsertAfter(2, 7);
		dllist.Print();

		cout << " --- insert after --- \n";
		dllist.InsertAfter(12, 7);
		dllist.Print();
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

	cout << " --- del head --- \n";
	dllist.DelHead();
	dllist.Print();

	cout << " --- add tail ---\n";
	dllist.AddTail(9);
	dllist.Print();

	try
	{
		cout << " --- clear ---\n";
		dllist.Clear();

		cout << " --- del tail ---\n";
		dllist.DelTail();
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

	try
	{
		cout << " --- print ---\n";
		dllist.Print();
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

	return 0;
}