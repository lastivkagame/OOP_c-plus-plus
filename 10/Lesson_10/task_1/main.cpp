#include "Person.h"

int main() {

	srand(time(0));

	//Person p;
	//p1.Print();

	//p1.PutInfo();
	//p1.Print();
	//system("pause");
	////===========
	//Person p2(18, "Ivan", "male");
	//p2.Print();
	//system("pause");

	////======
	//Student st1;
	//st1.Print();
	//st1.PutInfo();
	//st1.Print();

	//system("pause");
	//Student st2("Programmer", "Pr1", p2);
	//st2.Print();

	Employee p1, p2, p3;
	p1.PutInfo();
	cout << endl;
	p2.PutInfo();
	cout << endl;
	//p3.PutInfo();
	cout << endl;

	Employee*arr = new Employee[2]{ p1,p2 };

	Manager m(2, arr);

	m.Print();
	m.AddEmpl(1);
	cout << " ---- m.AddEmpl(1) ---";
	m.Print();

	m.RemoveEmpl(1);
	cout << " ---- m.RemoveEmpl ---";
	m.Print();

	system("pause");
	return 0;
}