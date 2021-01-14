#pragma once
#include <iostream>
using namespace std;

class Reservoir {
private:
	char* name;
	double width;
	double depth;
	double length;
	char* type;
public:
	Reservoir(const char* n = "none", double w = 0, double d = 0, double l = 0, const char* t = "none");

	char* GetName()const;
	double GetWidth()const;
	double GetDepth()const;
	double GetLength()const;
	char* GetType()const;

	void SetName(const char* n);
	void SetWidth(double w);
	void SetDepth(double d);
	void SetLength(double l);
	void SetType(const char* t);

	Reservoir(const Reservoir& obj);

	double volumeWater(double w, double l, double d);   //(ширина * длина * максимальная глубина);
	double areaWater(double w, double l);   //(ширина * длина)
	bool isOneType(char* t1, char* t2);
	void print();

	~Reservoir();
};