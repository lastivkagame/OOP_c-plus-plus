/*2. ������� ������� ����� ��������� �������� � ����������� ������ �������, ������, ��������, ������.
� ������� ������������ ���������� ��� ������� ��������� � ��� ��������������.
���������� ��� ������� �� ������� �������
Sound - ������ ���� ��������� (����� ������� � �������)
Show - ���������� ��� ���������
Type - ���������� �������� ��� �������

������� ������ ������ �������� �������� ��������.


�������� �����( ��� ������) ����� ����� ����� ���. ��������.
��������� ������ Sound(), Show(), Type() ���  ������� ����� ��������.


(Pet)Animal *arr [] = { new Cat,.... }
vector<Animal * > vect { new Cat,.... }

������� ������ Sound, Show,  Type ��� ������� ������� �������.

 ������ ���� �������� �������, �� ������
	����
	 -  ������ ���. ��������(vector<Animal *>)

	������
	 - �����������(�������  ������)
	 - ����������(�������� �� �������� � �������)

	 - ��������� ����� �������� � ������� �� ���������� �����������
	 - ����� ������������� ��������� ������ "����������" �������� � �������
	 - ����� ��������� ������ ��������
	 - ����� ����������� ��������(���������� ����� �� ��, �� ��� ��������)
	 - ����� ���������(�������) �������� � ��������
	 - ����� ���������(�������) ��� ��������

class HomeZoo
{
	vector <Animal *> zoo  ;

};*/

#include "Pet.h"

int main()
{
	// - 1 -
	Pet* arr[] = { new Dog,new Cat,new Parrot,new Hamster };

	for (int i = 0; i < 4; i++)
	{
		arr[i]->Sound();
		arr[i]->Show();
		cout << endl;

	}
	system("pause");
	system("cls");

	// - 2 -
	HomeZoo zoo;

	zoo.AddPet();
	cout << endl;
	zoo.AddPet();
	cout << endl;
	cout << " ----- random animals (types) -----\n";
	zoo.AddRandomPets(2);
	system("cls");
	zoo.Print();
	zoo.DelPets();
	cout << endl << "After sold all animal\n";
	zoo.Print();

	return 0;
}