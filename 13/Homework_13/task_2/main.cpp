/*2. Реалізувати задачу Паспорт, Іноземний Паспорт(або Коло вписане у квадрат) як багато файловий проект.
При цьому кожен з класів розмістити у окремому просторі імен. Перевірити роботу класів.*/

#include "ForeignPassport.h"

int main() {

	cout << "  --- Passport Ukraine ---  \n";
	Passport passprt("PETRO", "PETROVIICH", "PETROVSKY", "male", "m.Rivne street XXX", 07, 01, 1980);
	passprt.Print();

	system("pause");
	system("cls");

	Visa visa1("USA", 389456, 2);
	Visa visa2("France", 982333, 1);
	Visa visas[2] = { visa1,visa2 };

	visas[0].Print();
	visas[1].Print();

	system("pause");
	system("cls");

	cout << " --- Foregin Passport --- \n";
	ForeignPassport foreginPsw("PETRO", "PETROVIICH", "PETROVSKY", "male", "m.Rivne street XXX", 07, 01, 1980, 3459, 2, visas);
	foreginPsw.Print();

	system("pause");
	system("cls");

	cout << " --- Foregin Passport --- \n";
	foreginPsw.addVisa("Germany", 6579, 2);
	foreginPsw.Print();

	return 0;
}