#include "classes.h"

Reservoir::Reservoir(const char* n, double w, double d, double l, const char* t)
{
	SetName(n);
	SetWidth(w);
	SetDepth(d);
	SetLength(l);
	SetType(t);
}

//геттери
char* Reservoir::GetName()const
{
	return name;
}

double Reservoir::GetWidth()const
{
	return width;
}

double Reservoir::GetDepth()const
{
	return depth;
}

double Reservoir::GetLength()const
{
	return length;
}

char* Reservoir::GetType()const
{
	return type;
}

//сеттери
void Reservoir::SetName(const char* n)
{
	//if (name != nullptr)
	//{
	delete[]name;
	//}

	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

void Reservoir::SetWidth(double w)
{
	width = w;
}

void Reservoir::SetDepth(double d)
{
	depth = d;
}

void Reservoir::SetLength(double l)
{
	length = l;
}

void Reservoir::SetType(const char* t)
{
	//if (type != nullptr)
	//{
	delete[]type;
	//}

	type = new char[strlen(t) + 1];
	strcpy_s(type, strlen(t) + 1, t);
}

double Reservoir::volumeWater(double w, double l, double d)  //(ширина * длина * максимальная глубина);
{
	return w * l * d;
}

double Reservoir::areaWater(double w, double l)
{
	return w * l;
}

bool Reservoir::isOneType(char* t1, char* t2)
{
	return (!(strcmp(t1, t2)));
}

void  Reservoir::print()
{
	cout << " Name: " << name << endl;
	cout << " Width: " << width << endl;
	cout << " Depth: " << depth << endl;
	cout << " Length: " << length << endl;
	cout << "Type: " << type << endl;
}

Reservoir::~Reservoir()
{
	if (name != nullptr)
	{
		delete[]name;
		name = nullptr;
	}

	if (type != nullptr)
	{
		delete[]type;
		type = nullptr;
	}
}