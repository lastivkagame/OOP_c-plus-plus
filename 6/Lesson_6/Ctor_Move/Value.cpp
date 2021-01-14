#include "Value.h"

ostream & operator<<(ostream & os, const Value & obj)
{
	if (obj.pVal != nullptr)
	{
		os << obj.name << ":" << *(obj.pVal) << endl;
	}
	else 
	{
		os << "Obj is nullptr\n";
	}

	return os;
}

Value::Value(const Value & obj)
{
	pVal = new int;
	*pVal = *obj.pVal;
	cout << "Ctor copy works!!!\n";
	setName();
}

Value & Value::operator=(const Value & obj)
{
	if (this == &obj) 
	{
		cout << "it was asigned itself!!!" << endl;
		return *this;
	}
	
	*pVal = *obj.pVal;
	cout << "operator = works!\n";
	return *this;
}

//операто = з переміщенням
Value & Value::operator=(Value && obj)
{
	if (this == &obj)
	{
		return *this;
	}
	delete pVal;
	pVal = obj.pVal;
	obj.pVal = nullptr;
	cout << "operator = (&&) works\n";
	return *this;
}


Value::Value(Value && obj)
{
	//pVal = obj.pVal; //забираємо силку собі(get reference of obj for myself(this))
	//obj.pVal = nullptr;
	cout << "move ctor works!!!\n";
	setName();


	// якщо визначили оператор = з переміщенням то перші 2 рядки моджна замінити на
	*this = move(obj);
}

Value Value::operator+(const Value & right)
{
	cout << "operator + works" << endl;
	return (*this->pVal + *right.pVal);
}

void Value::setName()
{
	++id;
	name = name + to_string(id);
}
