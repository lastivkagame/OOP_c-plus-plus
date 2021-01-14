/*Завдання 1. Створити програму з використанням патерну Спостерігач(Observer).
Предмет спостереження – курс долару(чи євро). Спостерігачі – клієнти(банк, брокер).
При збільшенні(зменшенні) курсу спостерігачі продають(купляють) валюту.*/

#include "observer.h"

int main()
{
	srand(time(nullptr));

	CourseDollar* cd = new CourseDollar(24.47);
	CourseEuro* ce = new CourseEuro(26.55);

	Bank* bank1 = new Bank("Bank #1", 30000, 30000);
	Bank* alfabank = new Bank("Alfa Bank", 40000, 40000);
	Bank* ukrgasbank = new Bank("Ukr Gas Bank", 35000, 35000);
	Broker* ira = new Broker("Ira", 12000);
	Broker* vlad = new Broker("Vlad", 10000);

	bank1->setProduct(cd);
	alfabank->setProduct(ce);
	ukrgasbank->setProduct(cd);
	ukrgasbank->setProduct(ce);
	ira->setProduct(cd);
	vlad->setProduct(ce);

	cd->Attach(bank1);
	ce->Attach(alfabank);
	cd->Attach(ukrgasbank);
	ce->Attach(ukrgasbank);
	cd->Attach(ira);
	ce->Attach(vlad);

	cd->setPrice(23.30);
	system("pause");
	system("cls");

	ce->setPrice(27.20);
	system("pause");
	system("cls");

	cd->setPrice(25.30);
	system("pause");
	system("cls");

	ce->setPrice(24.20);
	system("pause");
	system("cls");

	cout << " \nWithout Vlad(Vlad is detach) \n\n";
	ce->Detach(vlad);
	ce->setPrice(28.20);
	cout << endl << endl;
	cout << " Ira submit on " << ira->GetProduct()->GetName() << endl;

	system("pause");
	return 0;
}
