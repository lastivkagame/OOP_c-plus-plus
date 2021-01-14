#pragma once
#include <iostream>
using namespace std;

class Fractins
{
private:
	int numerator;     // - ���������
	int denominator;   // - ���������
public:
	//������������
	Fractins();
	Fractins(int numerator);
	Fractins(int numerator, int denominator);

	//�������
	void SetNumerator(int numerator);
	void SetDenominator(int denominator);

	//�������
	int GetNumerator()const;
	int GetDenominator()const;

	//����������� ����
	Fractins(const Fractins& obj);

	//i���
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