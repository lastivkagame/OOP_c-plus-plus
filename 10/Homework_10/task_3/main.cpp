/*3. Описати клас Fortress (Фортеця).
 Для початку, напишіть клас Shooter (Стрілець), який буде містити два поля:
	o назва амуніції
	o кількість амуніції.
 Стрілець може
	o виконати дію &quot;постріл&quot; і витратити для цього одиницю амуніції, повідомляючи в
		консоль, як вона називалась;
	o здійснити дію &quot;дати амуніцію&quot;, яка встановлюватиме назву і кількість амуніції,
		отримуючи ці дані через параметри.

Стрілець має три дочірні класи: Archer (Лучник), Range (Рейнджер) та Catapult(Катапульта),
які заміщають дію &quot;постріл&quot;, доповнюючи повідомлення в консоль
інформацією про те, хто саме з них вистрілив.

Перші два повинні стріляти стрілами, а катапульта - каменями.
Від перших двох породжується клас ArcherTower(Cтрілецька вежа), у якої запас амуніції
має бути один (спільний) для обох: лучника і рейнджера (подумайте, який механізм
множинного успадкування тут варто застосувати).

Від класів Стрілкова Вежа і Катапульта має походити клас Fortress.
Лише в її конструкторі мають поставлятись стріли для стрілкової вежі і камені для
катапульти.

Додайте до фортеці ще кілька полів - товщина стін, стан воріт у відсотках, і т. д. - на
Ваше бажання та фантазію.

В кожного з полів чи методів у цій ієрархії має бути встановлений максимальний рівень
захисту, і успадкування має відбуватись по найвище допустимому по захисту
специфікаторові доступу.

Але таким, щоб в main() можна було виконати наступне:
	створити об'єкт фортеці
	вистрілити лучником(н-д 3 рази), рейнджером(н-д, 2 рази) і з катапульти

Отже, всього має бути 6 класів, фінальним класом серед них є клас Фортеця, лише один
об'єкт якої буде створено.

Зверніть на це увагу - 6 класів описано, всі використовуються. Але об'єкт у всій програмі один(фортеця)

	ПРИМІТКИ! Коли створюватиметься фортеця, доставте в стрілкову вежу лише 4 стріли,
тоді буде явно видно, що на другий постріл рейнджеру стріл не вистачить, оскільки
лучник перед тим витратив 3 із 4-х стріл.*/

#include "Fortress.h"
#include <ctime>

int main()
{
	srand(time(nullptr));

	Fortress fortress("pule", 4);
	fortress.Archertower("archer");
	fortress.Archertower("archer");
	fortress.Archertower("archer");
	fortress.Archertower("range");
	fortress.Archertower("range");

	system("pause");
	system("cls");

	Fortress fortress2("pule", 300);
	Fortress myfortress("pule", 300);
	cout << " --- Welcome --- \n";
	cout << " You have a fortress, you can choose who must shoot.\nThey fired my fortress. I fire your fortress. \nIf you first destroyed my fortress  -  you win, else I win\n\n";
	int choose;

	while (fortress2.IsFortrees())
	{
		cout << " Choose who you want that fire:\n";
		cout << " 1 - archer\n";
		cout << " 2 - ranger\n";
		cout << " 3 - catapulta\n";
		cout << "Answer: ";
		cin >> choose;

		if (choose == 1)
		{
			cout << " --- Your attac ---- \n";
			fortress2.Archertower("archer");  //гравець аттакує
			cout << endl;
			cout << " --- Enemy attac ---- \n";
			myfortress.Archertower("catapult");  //я аттакую

			// отримуємо пошкождення
			fortress2.ConsistentWound((rand() % 20));
			myfortress.ConsistentWound((rand() % 20));
		}
		else if (choose == 2)
		{
			cout << " --- Your attac ---- \n";
			fortress2.Archertower("range");  //гравець аттакує
			cout << endl;
			cout << " --- Enemy attac ---- \n";
			myfortress.Archertower("archer");  //я аттакую

			// отримуємо пошкождення
			fortress2.ConsistentWound((rand() % 20));  //гравець аттакує
			myfortress.ConsistentWound((rand() % 20));  //я аттакую
		}
		else
		{
			cout << " --- Your attac ---- \n";
			fortress2.Archertower("catapult");  //гравець аттакує
			cout << endl;
			cout << " --- Enemy attac ---- \n";
			myfortress.Archertower("range");   //я аттакую

			// отримуємо пошкождення
			fortress2.ConsistentWound((rand() % 20));
			myfortress.ConsistentWound((rand() % 20));
		}

		if (!myfortress.IsFortrees())
		{
			break;
		}
		system("pause");
		system("cls");
		cout << " --- Your fortress ---\n";
		fortress2.Print();
		system("pause");
		system("cls");
		cout << " --- Enemies fortress ---\n";
		myfortress.Print();
		system("pause");
		system("cls");
	}

	if (fortress2.IsFortrees())
	{
		cout << " \nYou Win!\n";
	}
	else
	{
		cout << " \nYou Lose!\n";
	}

	cout << " --- Your fortress ---\n";
	fortress2.Print();
	cout << endl << endl;
	cout << " --- Enemies fortress ---\n";
	myfortress.Print();
	cout << endl << endl;

	return 0;
}