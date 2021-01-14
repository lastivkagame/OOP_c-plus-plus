#include "Person.h"
#include "Programmer.h"
#include "Singer.h"
#include "SingerProggramer.h"

int main() {

	Person max("Max", 16, "male"), andrew("Andrew", 17, "male");
	max.Print();
	andrew.Print();

	Programmer andrew2("Andrew", 18, "male");
	andrew2.Print(); //person
	andrew2.addSkill("C#");
	andrew2.addSkill("Phyton");
	andrew2.showSkills();

	Singer kolia("Kolia", 20);
	kolia.Print();

	SingerProggramer sasha("sasha", 25, "female", "soprano");
	sasha.Singer::show();
	sasha.Programmer::showSkills();
	cout << "Singing Programmer name = " << sasha.GetName() << endl;


	system("pause");
	return 0;
}