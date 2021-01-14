#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Pet
{
private:
	string name;
	int age;
public:
	Pet() :Pet("none", 0) {};
	Pet(string name, int age) :name(name), age(age) {};

	virtual void Sound()const = 0;  //издает звук животного (пишем текстом в консоль)
	virtual void Show()const = 0;  //отображает имя животного
	virtual void Type()const = 0;   //отображает название его подвида
	virtual ~Pet() {};

	void SetName(string name)
	{
		this->name = name;
	}

	void SetAge(int age)
	{
		this->age = age;
	}

	string GetName()const
	{
		return this->name;
	}

	int GetAge()const
	{
		return this->age;
	}
};

class Dog : public Pet
{
public:
	Dog() :Pet() {};
	Dog(string name, int age) :Pet(name, age) {};

	void Sound()const
	{
		cout << " Gav! Gav! Gav!\n";
	}

	void Show()const
	{
		cout << " --- ";
		Type();
		cout << " --- \n";
		cout << " Name: " << GetName() << endl;
		cout << " Age: " << GetAge() << endl;
	}

	void Type()const
	{
		cout << typeid(*this).name();
	}

	~Dog() {};
};

class Cat : public Pet
{
public:
	Cat() :Pet() {};
	Cat(string name, int age) :Pet(name, age) {};

	void Sound()const
	{
		cout << " Meuv! Meuv! Meuv!\n";
	}

	void Show()const
	{
		cout << " --- ";
		Type();
		cout << " --- \n";
		cout << " Name: " << GetName() << endl;
		cout << " Age: " << GetAge() << endl;
	}

	void Type()const
	{
		cout << typeid(*this).name();
	}

	~Cat() {};
};

class Parrot : public Pet
{
public:
	Parrot() :Pet() {};
	Parrot(string name, int age) :Pet(name, age) {};

	void Sound()const
	{
		cout << " Aaa! Aaa! Aaa!\n";
	}

	void Show()const
	{
		cout << " --- ";
		Type();
		cout << " --- \n";
		cout << " Name: " << GetName() << endl;
		cout << " Age: " << GetAge() << endl;
	}

	void Type()const
	{
		cout << typeid(*this).name();
	}

	~Parrot() {};
};

class Hamster : public Pet
{
public:
	Hamster() :Pet() {};
	Hamster(string name, int age) :Pet(name, age) {};

	void Sound()const
	{
		cout << " Shhh! Shhh! Shhh!\n";
	}

	void Show()const
	{
		cout << " --- ";
		Type();
		cout << " --- \n";
		cout << " Name: " << GetName() << endl;
		cout << " Age: " << GetAge() << endl;
	}

	void Type()const
	{
		cout << typeid(*this).name();
	}

	~Hamster() {};
};

class HomeZoo
{
private:
	vector<Pet*>zoo;
public:
	HomeZoo() {}; //- конструктор(зоопарк  пустий)

	~HomeZoo()  // - деструктор(вилучити всі тваринки з вектору)
	{
		DelPets();
	}

	void AddPet() // - додавання певної тваринки у Зоопарк на замовлення користувача
	{
		string name;
		int age, choose;

		cout << " - enter name: ";
		cin >> name;

		cout << " - enter age: ";
		cin >> age;

		cout << " - enter type: \n";
		cout << " 1 - Dog\n 2 - Cat\n 3 - Parrot\n 4 - Hamster\nAnswer: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			zoo.push_back(new Dog(name, age));
			break;
		case 2:
			zoo.push_back(new Cat(name, age));
			break;
		case 3:
			zoo.push_back(new Parrot(name, age));
			break;
		case 4:
			zoo.push_back(new Hamster(name, age));
			break;
		default:
			zoo.push_back(new Dog(name, age));
			break;
		}
	}

	void AddRandomPets(int num) // - метод автоматичного додавання кількох "випадкових" тваринок у зоопарк
	{
		srand(time(nullptr));

		for (int i = 0; i < num; i++)
		{
			string name;
			int age, choose;

			cout << " - enter name: ";
			cin >> name;

			cout << " - enter age: ";
			cin >> age;

			choose = rand() % 5;

			switch (choose)
			{
			case 1:
				zoo.push_back(new Dog(name, age));
				break;
			case 2:
				zoo.push_back(new Cat(name, age));
				break;
			case 3:
				zoo.push_back(new Parrot(name, age));
				break;
			case 4:
				zoo.push_back(new Hamster(name, age));
				break;
			default:
				zoo.push_back(new Dog(name, age));
				break;
			}
		}
	}

	void Print()const //  - метод перегдяду списку тваринок
	{
		cout << " --- Zoo --- \n";
		for (int i = 0; i < zoo.size(); i++)
		{
			cout << " - " << i << " - \n";
			zoo[i]->Show();
		}
	}

	void SetName(string name, int index)  // - метод редагування тваринки(редагується назва чи вік, не тип тваринки)
	{
		zoo[index]->SetName(name);
	}

	void SetAge(int age, int index)  // - метод редагування тваринки(редагується назва чи вік, не тип тваринки)
	{
		zoo[index]->SetAge(age);
	}

	void DelPet(int index)  // - метод вилучення(продажу) тваринки з зоопарку
	{
		vector<Pet*> temp;
		int k = 0;

		for (int i = index + 1; i < zoo.size(); i++)
		{
			temp[i] = zoo[k++];
		}

		k = 0;

		for (int i = index; i < zoo.size(); i++)
		{
			temp[i] = zoo[k++];
		}
	}

	void DelPets()  // - метод вилучення(продажу) всіх тваринок
	{
		if (zoo.size() != 0)
		{
			for (int i = 0; i < zoo.size(); i++)
			{
				delete[] zoo[i];
			}

			zoo.resize(0);
		}
	}
};