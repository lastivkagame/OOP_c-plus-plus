#include "Complex.h"


Complex::Complex(double x0) : x(x0), y(x0) {}
Complex::Complex(double x0, double y0) : x(x0), y(y0) {}

Complex::Complex(Complex& obj)
{
	this->SetX(obj.GetX());
	this->SetY(obj.GetY());
}

Complex::Complex(Complex && obj)
{
	*this = move(obj);
}

void Complex::SetX(double x)
{
	this->x = x;
}

void Complex::SetY(double x)
{
	this->y = y;
}

double Complex::GetX()const
{
	return x;
}

double Complex::GetY()const
{
	return y;
}

bool Complex::operator==(const Complex& obj)
{
	if (x == obj.x && y == obj.y)
	{
		return true;
	}

	return false;
}

Complex& Complex::operator=(const Complex& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	this->x = obj.x;
	this->y = obj.y;
	return *this;
}

Complex& Complex::operator=(Complex && obj)
{
	this->x = obj.x;
	this->y = obj.y;
	return *this;
}

Complex& Complex::operator+=(Complex obj)
{
	x = obj.x;
	y = y + obj.y;
	return *this;
}

Complex& Complex::operator-=(Complex obj)
{
	x = obj.x;
	y = y - obj.y;
	return *this;
}

double Complex::modul()
{
	return pow(x * x + y * y, 1 / 2.0);
}

double Complex::argument()
{
	return atan2(y, x) * 180 / PI;
}

void Complex::showComplex()const
{
	if (y >= 0)
	{
		cout << x << "+" << y << "i";
	}
	else
	{
		cout << x << "-" << fabs(y) << "i";  //fabl - модуль числа
	}
}

Complex Complex::operator+(const Complex& obj)
{
	Complex temp(0);
	temp.x = this->x + obj.x;
	temp.y = this->y + obj.y;
	return temp;
}

Complex Complex::operator-(const Complex& obj)
{
	Complex temp(0);
	x = x - obj.x;
	y = y - obj.y;

	temp.x = x;
	temp.y = y;

	return temp;
}

Complex Complex::operator*(const Complex& obj)
{
	Complex temp(0);

	x = x * obj.x - y * obj.y;
	y = y * obj.x + x * obj.y;

	temp.x = x;
	temp.y = y;

	return temp;
}

Complex Complex::operator/(const Complex &obj)
{
	double temp;
	temp = obj.x * obj.x - obj.y * obj.y;
	x = x * obj.x + y * obj.y;
	y = y * obj.x - x * obj.y;
	return temp;
}

Complex& Complex::operator++()
{
	this->y++;
	this->x++;

	return *this;
}

Complex& Complex::operator++(int)
{
	Complex temp = *this;

	this->y++;
	this->x++;

	return temp;
}

Complex& Complex::operator--()
{
	this->y--;
	this->x--;

	return *this;
}

Complex& Complex::operator--(int)
{
	Complex temp = *this;

	this->y--;
	this->x--;

	return temp;
}

//операції для введення та виведення рядка
ostream& operator<<(ostream& os, const Complex right)
{
	right.showComplex();
	return os;
}

istream& operator>>(istream& is, Complex& right)
{
	int num1, num2;
	cin >> num1 >> num2;
	right.SetX(num1);
	right.SetY(num2);

	return is;
}