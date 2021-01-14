#include "animal.h"

int main() {

	Bear bear(2, 4, "Yogi", "brown", MAMMAl);
	Wolf wolf(4, 4, "Jack", "grey", MAMMAl);
	Cat cat(1, 4, "Myrzik", "orange", MAMMAl, "Vasya");
	Dog dog(3, 4, "Jessi", "black", MAMMAl, "Tumyr");

	Animal * animals[] = { new Bear, new Wolf, new Cat,new Dog };
	Animal * animals2[] = { &bear,&wolf,&cat,&dog };

	cout << "   ---- ANIMALS ------\n";
	for (int i = 0; i < 4; i++)
	{
		animals[i]->print();
	}

	system("pause");
	system("cls");

	cout << "   ---- ANIMALS ------\n";
	for (int i = 0; i < 4; i++)
	{
		animals2[i]->print();
	}

	system("pause");
	system("cls");

	for (int i = 0; i < 4; i++)
	{
		delete[]animals[i];
		delete[]animals2[i];
	}

	system("pause");
	return 0;
}