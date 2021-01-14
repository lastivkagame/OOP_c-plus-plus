#include <iostream>
#include <string>
using namespace std;

class Base
{
	int a;
public:
	Base(int a = 20) :a(a) {};

	void Show()const
	{
		cout << a << "from Base" << endl;
	}

	virtual ~Base() {};
};

class Derived :public Base
{
	string name;
public:
	Derived(string name = "none") :Base()
	{
		this->name = name;
	}

	void ShowName()const
	{
		cout << name << " from derived" << endl;
	}
};

class SuperDerrived :public Base
{
	
};

int main() {

	Base*b = new Derived();  // upcast
	//Derived *d = new Derived();

	dynamic_cast<Derived*>(b)->ShowName();
	Derived *fromBase = dynamic_cast<Derived*>(b);

	fromBase->ShowName();

	cout << typeid(b).name() << endl;
	cout << typeid(fromBase).name() << endl; // "Derrived *"

	Derived*test;

	if (dynamic_cast<Derived*>(b))  //check
	{
		cout << "Derrived *" << endl;
	}

	//SuperDerrived*demoBadCast = dynamic_cast<Base*>(fromBase);  // error upcast
	//SuperDerrived *demoBadCast = (Base)fromBase;  // error upcast

	fromBase->ShowName();
	((Base*)fromBase)->Show();  //upcast

	Base * up = fromBase; // upcast;

	system("pause");
	return 0;
}