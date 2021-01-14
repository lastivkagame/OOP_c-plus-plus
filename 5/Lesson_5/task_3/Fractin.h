#pragma once
#include <iostream>
using namespace std;

class Fractins
{
private:
	int numerator;     // - чисельник
	int denominator;   // - знаменник
public:
	//конструктори
	Fractins();
	Fractins(int numerator);
	Fractins(int numerator, int denominator);

	//сеттери
	void SetNumerator(int numerator);
	void SetDenominator(int denominator);

	//геттери
	int GetNumerator()const;
	int GetDenominator()const;

	//конструктор копій
	Fractins(const Fractins& obj);

	//iнше
	void print()const;
	Fractins Abrev();

	//operators + - * /
	Fractins operator+(const Fractins& obj);
	Fractins operator-(const Fractins& obj);
	Fractins operator*(const Fractins& obj);
	Fractins operator/(const Fractins& obj);

	char comparison(Fractins& obj);
	int intNumber();
	double doubleNumber();
};