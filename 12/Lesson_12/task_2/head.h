#pragma once
#include <iostream>
#include <string>
using namespace std;

class Grandpa
{
private:
	int age;
	string name;
public:
	Grandpa() :Grandpa(60, "some") {};
	Grandpa(int age, string name) :age(age), name(name) {};
	virtual ~Grandpa() {};

	virtual void Sleep()
	{
		cout << " I grandpa I sleep!";
	}

	virtual void Print()const
	{
		cout << " - Grandpa - \n";
		cout << " Name: " << GetName() << endl;
		cout << " Age: " << GetAge() << endl;
		Type();
	}

	virtual void Type() const
	{
		cout << " type: " << typeid(this).name() << endl;
	}

	int GetAge()const 
	{
		return this->age;
	}

	string GetName()const
	{
		return this->name;
	}
};

class Daddy:public Grandpa
{
private:

public:
	Daddy() :Grandpa() {};
	Daddy(int age, string name) :Grandpa(age, name) {};
	virtual ~Daddy() {};

	virtual void Walk() 
	{
		cout << " I Daddy I walk!\n";
	}

	virtual void Sleep() 
	{
		cout << " I Daddy I sleep!\n";
	}

	void Type() const
	{
		cout << " type: " << typeid(this).name() << endl;
	}

	virtual void Print()const 
	{
		cout << " - Daddy - \n";
		cout << " Name: " << GetName() << endl;
		cout << " Age: " << GetAge() << endl;
		Type();
	}
};

class Son:public Daddy
{
private:

public:
	Son() :Daddy() {};
	Son(int age, string name) :Daddy(age, name) {};
	virtual ~Son() {};

	virtual void Walk() 
	{
		cout << " I Son I walk!\n";
	}

	virtual void Play() 
	{
		cout << " I Son I play!\n";
	}

	virtual void Sleep()
	{
		cout << " I son I sleep!\n";
	}

	void Type()const
	{
		cout << " type: " << typeid(this).name() << endl;
	}

	virtual void Print()const
	{
		cout << " - Son - \n";
		cout << " Name: " << GetName() << endl;
		cout << " Age: " << GetAge() << endl;
		Type();
	}
};