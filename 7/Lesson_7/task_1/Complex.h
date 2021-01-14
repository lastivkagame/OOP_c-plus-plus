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
	//������������

	Complex(double x0 = 1);
	Complex(double x0, double y0);
	Complex(Complex& obj);

	Complex(Complex&& obj);



	//�������
	void SetX(double x);
	void SetY(double x);

	//�������
	double GetX()const;
	double GetY()const;

	//���������� � ����������(��������� � ���������)
	Complex& operator++();
	Complex& operator++(int);
	Complex& operator--();
	Complex& operator--(int);

	//䳿 ��� ������������ �������
	Complex operator+(const Complex& obj);
	Complex operator-(const Complex& obj);
	Complex operator*(const Complex& obj);
	Complex operator/(const Complex& obj);

	//��������� ����������� �����
	bool operator ==(const Complex& obj);

	//�� ���� ������
	Complex& operator=(const Complex& obj);
	Complex& operator=( Complex&& obj);

	Complex& operator+=(Complex obj);
	Complex& operator-=(Complex obj);

	//�� ���� ������
	double modul();
	double argument();
	void showComplex()const;

	//�������� ��� �������� �� ��������� �����
	friend ostream& operator<<(ostream& os, const Complex right);
	friend istream& operator>>(istream& is, Complex& right);
};