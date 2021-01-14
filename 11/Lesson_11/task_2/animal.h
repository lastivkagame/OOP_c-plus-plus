#pragma once
#include <string>
#include <iostream>
using namespace std;

enum kind
{
	FiSH = 0,
	BIRD = 1,
	MAMMAl = 2,
	ERR = -1
};

class Animal
{
private:
	int age;
	int legs;

	string name;
	string color;

	kind k;

public:
	Animal() :Animal(0, 0, "none", "none", ERR) {};
	Animal(int age, int legs, string name, string color, kind k) :age(age), legs(legs), name(name), color(color), k(k) {};
	virtual ~Animal() {};

	virtual void eat() = 0;
	virtual void voice() = 0;
	virtual void type() = 0;
	virtual void print() = 0;

	string GetName()const
	{
		return this->name;
	}

	string GetColor()const
	{
		return this->color;
	}

	int GetAge()const
	{
		return this->age;
	}

	int GetLegs()const
	{
		return this->legs;
	}

	kind GetKind()const
	{
		return this->k;
	}
};

class WildAnimal : public Animal
{
public:
	WildAnimal() :Animal(0, 0, "none", "none", ERR) {};
	WildAnimal(int age, int legs, string name, string color, kind k) : Animal(age, legs, name, color, k) {};
	virtual ~WildAnimal() {};

	void PrintLive()const
	{
		cout << " I live at forest\n";
	}
};

class DomasticAnimal : public Animal
{
private:
	string owner;
public:
	DomasticAnimal() :Animal(0, 0, "none", "none", ERR) { this->owner = "none"; };
	DomasticAnimal(int age, int legs, string name, string color, kind k, string owner) : Animal(age, legs, name, color, k) { this->owner = owner; };
	virtual ~DomasticAnimal() {};

	string GetOwner()const
	{
		return this->owner;
	}
};

class Bear : public WildAnimal
{
public:
	Bear() :WildAnimal(0, 0, "none", "none", ERR) {};
	Bear(int age, int legs, string name, string color, kind k) : WildAnimal(age, legs, name, color, k) {};
	virtual ~Bear() {};

	void eat()
	{
		cout << " I eat honey. It's tasty!\n";
	}

	void voice()
	{
		cout << " Aaaa - Aaaa! \n";
	}

	void type()
	{
		cout << " This - " << typeid(*this).name() << endl;
	}

	void print()
	{
		cout << " I' m Bear \n";
		cout << " Name: " << this->GetName() << endl;
		cout << " Age: " << this->GetAge() << endl;
		cout << " Color: " << this->GetColor() << endl;
		cout << " Kind: " << this->GetKind() << endl;
		cout << " Legs: " << this->GetLegs() << endl;
		cout << " Live: ";
		this->PrintLive();
		
		/*MeatEater m;
		cout << " Type taste: ";
		m.print();
		cout << endl;*/

		this->type();
		cout << endl;
	}
};

class Wolf :public WildAnimal
{
public:
	Wolf() :WildAnimal(0, 0, "none", "none", ERR) {};
	Wolf(int age, int legs, string name, string color, kind k) : WildAnimal(age, legs, name, color, k) {};
	virtual ~Wolf() {};

	void eat()
	{
		cout << " I eat meat. It's tasty!\n";
	}

	void voice()
	{
		cout << " Ayyy - ayyy - aayyy! \n";
	}

	void type()
	{
		cout << " This - " << typeid(*this).name() << endl;
	}

	void print()
	{
		cout << " I' m Wolf \n";
		cout << " Name: " << this->GetName() << endl;
		cout << " Age: " << this->GetAge() << endl;
		cout << " Color: " << this->GetColor() << endl;
		cout << " Kind: " << this->GetKind() << endl;
		cout << " Legs: " << this->GetLegs() << endl;
		cout << " Live: ";
		this->PrintLive();

		/*MeatEater m;
		cout << " Type taste: ";
		m.print();
		cout << endl;*/

		this->type();
		cout << endl;
	}
};

class Cat :public DomasticAnimal
{
public:
	Cat() : DomasticAnimal(0, 0, "none", "none", ERR, "none") {};
	Cat(int age, int legs, string name, string color, kind k, string owner) : DomasticAnimal(age, legs, name, color, k, owner) {};
	virtual ~Cat() {};

	void eat()
	{
		cout << " I eat cat food. It's tasty!\n";
	}

	void voice()
	{
		cout << " Mew - mew - mew! \n";
	}

	void type()
	{
		cout << " This - " << typeid(*this).name() << endl;
	}

	void print()
	{
		cout << " I' m Cat \n";
		cout << " Name: " << this->GetName() << endl;
		cout << " Age: " << this->GetAge() << endl;
		cout << " Color: " << this->GetColor() << endl;
		cout << " Kind: " << this->GetKind() << endl;
		cout << " Legs: " << this->GetLegs() << endl;
		cout << " Owner: " << this->GetOwner() << endl;

		/*MeatEater m;
		cout << " Type taste: ";
		m.print();
		cout << endl;*/

		this->type();
		cout << endl;
	}
};

class Dog : public DomasticAnimal
{
public:
	Dog() : DomasticAnimal(0, 0, "none", "none", ERR, "none") {};
	Dog(int age, int legs, string name, string color, kind k, string owner) : DomasticAnimal(age, legs, name, color, k, owner) {};
	virtual ~Dog() {};

	void eat()
	{
		cout << " I eat cat food. It's tasty!\n";
	}

	void voice()
	{
		cout << " Gav - gav - gav! \n";
	}

	void type()
	{
		cout << " This - " << typeid(*this).name() << endl;
	}

	void print()
	{
		cout << " I' m Dog \n";
		cout << " Name: " << this->GetName() << endl;
		cout << " Age: " << this->GetAge() << endl;
		cout << " Color: " << this->GetColor() << endl;
		cout << " Kind: " << this->GetKind() << endl;
		cout << " Legs: " << this->GetLegs() << endl;
		cout << " Owner: " << this->GetOwner() << endl;

		/*MeatEater m;
		cout << " Type taste: ";
		m.print();
		cout<<endl;*/

		this->type();
		cout << endl;
	}
};

/*
class MeatEater
{
public:
	void print() 
	{
		cout << " I eat meat!\n";
	}
};

class GrassEater 
{
public:
	void print()
	{
		cout << " I eat plant!\n";
	}
};*/