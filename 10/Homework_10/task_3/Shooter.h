#pragma once
#include <iostream>
using namespace std;

class Shooter
{
private:
	string name;
	int digits;
public:
	Shooter();
	Shooter(string name, int digits);

	void quot();

	void SetName(string name);
	void SetDigits(int digits);
	void GiveAmmo(string name, int digits);

	string GetName()const;
	int GetDigits()const;

	void Print()const;
};