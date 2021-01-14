#include "Point.h"

Point::Point(int x, int y, const char* name)
{
	this->x = x;  //уникнути путаниці імен
	this->y = y;
	this->SetName(name);
	count++;
}

Point::Point(const Point & obj)
{
	this->x = obj.GetX();
	this->SetY(obj.GetY());
	this->SetName(obj.GetName());
	count++;
}

void Point::SetX(int x)
{
	this->x = x;
}

void Point::SetY(int y)
{
	this->y = y;
}

void Point::SetName(const char * name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

int Point::GetX()const
{
	return this->x;
}

int Point::GetY()const
{
	return this->y;
}

char * Point::GetName() const
{
	return this->name;
}

void Point::Show()const
{
	cout << " " << name << endl;
	cout << "(" << x << "," << y << ")" << endl;
}

Point::Point() 
{
	x = 0;
	y = 0;
	this->SetName("none");
	count++;
}

Point::~Point() 
{
	if (name != nullptr)
	{
		delete[]name;
		name = nullptr;
	}
}
	

