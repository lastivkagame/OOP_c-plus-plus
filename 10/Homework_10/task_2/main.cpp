/*	2. Создайте класс Passport (паспорт), который будет содержать паспортную информацию о гражданине Украины.
С помощью механизма наследования, реализуйте класс ForeignPassport (загран.паспорт) производный от Passport.
Напомним, что загран.паспорт содержит помимо паспортных данных, также данные о визах, номер загран.паспорта*/

#include <iostream>
#include "Passport.h"
#include "ForeignPassport.h"
#include "Visa.h"
using namespace std;

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