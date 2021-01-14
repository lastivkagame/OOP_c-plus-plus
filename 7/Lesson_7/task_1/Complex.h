#pragma once
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926;

class Complex
{
private:
	double x;
	double y;
public:
	//конструктори

	Complex(double x0 = 1);
	Complex(double x0, double y0);
	Complex(Complex& obj);

	Complex(Complex&& obj);



	//сеттери
	void SetX(double x);
	void SetY(double x);

	//геттери
	double GetX()const;
	double GetY()const;

	//інкременти і дикрименти(постфіксні і префікстні)
	Complex& operator++();
	Complex& operator++(int);
	Complex& operator--();
	Complex& operator--(int);

	//дії над комплексними числами
	Complex operator+(const Complex& obj);
	Complex operator-(const Complex& obj);
	Complex operator*(const Complex& obj);
	Complex operator/(const Complex& obj);

	//порівняння комплексних чисел
	bool operator ==(const Complex& obj);

	//ще деякі методи
	Complex& operator=(const Complex& obj);
	Complex& operator=( Complex&& obj);

	Complex& operator+=(Complex obj);
	Complex& operator-=(Complex obj);

	//ще деякі методи
	double modul();
	double argument();
	void showComplex()const;

	//операції для введення та виведення рядка
	friend ostream& operator<<(ostream& os, const Complex right);
	friend istream& operator>>(istream& is, Complex& right);
};