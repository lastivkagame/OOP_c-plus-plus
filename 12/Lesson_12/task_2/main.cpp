#include "head.h"

void Print(Grandpa* arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << " ---- " << i << " -----\n";
		arr[i]->Print();
		arr[i]->Sleep();

		if (dynamic_cast<Daddy*>(arr[i]))  //check
		{
			dynamic_cast<Daddy*>(arr[i])->Walk();
		}

		if (dynamic_cast<Son*>(arr[i]))  //check
		{
			dynamic_cast<Son*>(arr[i])->Play();
		}
		cout << endl;
	}

}

void Print2(Grandpa* arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << " ---- " << i << " -----\n";
		arr[i]->Print();
		arr[i]->Sleep();

		if (typeid(*arr[i]) == typeid(Daddy))  //check
		{
			dynamic_cast<Daddy*>(arr[i])->Walk();
		}

		if (typeid(*arr[i]) == typeid(Son))  //check
		{
			dynamic_cast<Son*>(arr[i])->Play();
			dynamic_cast<Daddy*>(arr[i])->Walk();
		}
		cout << endl;
	}

}

int main() {

	Grandpa* arr[4] = { new Grandpa(70,"Jacob"), new Daddy(37,"Jack"), new Son(10,"Dan"), new Son(17,"Tima") };

	Print(arr, 4);

	system("pause");
	system("cls");

	Print2(arr, 4);

	system("pause");
	return 0;
}