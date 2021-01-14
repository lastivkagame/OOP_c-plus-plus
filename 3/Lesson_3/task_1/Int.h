#pragma once
#include <iostream>
using namespace std;


class Int
{
private:
	int number;
	const int test;
	static int count;
public:
	Int();
	Int(int number);
	Int(const Int & obj);


	int GetNumber()const;
	void SetNumber(int number);

	void print()const;
	static int GetCount();

	Int Sum(/*Int * this*/const Int& a);
	Int Sub(const Int& a);
	Int& SumEqual(const Int& obj);

	~Int();
};

