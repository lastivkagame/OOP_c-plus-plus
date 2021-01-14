#pragma once
#include <iostream>
#include <string>
using namespace std;

class Value
{
private:
	string name = "o";
	static int id;
	int *pVal;
public:
	Value() = default;
	Value(int val) : pVal(new int(val)) 
	{ 
		++id; 
		name += to_string(id);
	}

	friend  ostream & operator<<(ostream &os, const Value & obj);
	Value(const Value &obj);

	Value& operator=(const Value &obj);
	Value&operator=(Value && obj);  //операто = з переміщенням

	Value(Value && obj); //конструктор move

	Value operator + (const Value & right);

	void setName();

	~Value() 
	{
		if (pVal) 
		{
			delete pVal;
			pVal = nullptr;
		}
	}
};

