#include "Shooter.h"

Shooter::Shooter() :Shooter("none", 0) {};

Shooter::Shooter(string name, int digits) : name(name), digits(digits) {}

void Shooter::quot()
{
	digits--;
	cout << " It be " << name << " one digit( you have " << digits << " yet )\n";
}

void Shooter::SetName(string name)
{
	this->name = name;
}

void Shooter::SetDigits(int digits)
{
	this->digits = digits;
}

void Shooter::GiveAmmo(string name, int digits)
{
	this->name = name;
	this->digits = digits;
}

string Shooter::GetName() const
{
	return this->name;
}

int Shooter::GetDigits() const
{
	return this->digits;
}

void Shooter::Print() const
{
	cout << " Name: " << name << endl;
	cout << " Digits: " << digits << endl;
}
