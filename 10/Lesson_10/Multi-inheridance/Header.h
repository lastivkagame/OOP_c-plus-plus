#pragma once
#include <iostream>
#include <string>
using namespace std;

class Roga
{
	string color;
	int weight;
public:
	Roga() :color("dirty"), weight(10) {};
	Roga(string color, int weight) :color(color), weight(weight) { };
	void show() { cout << "color: " << color << "\t" << weight << " kg\n"; }
};

class Koputa
{
	string shape;
	int count;

public:
	Koputa() :shape("standart"), count(4) {};
	Koputa(string shape, int count) :shape(shape), count(count) {};
	void show() { cout << "shape: " << shape << "\t" << count << " sht\n"; }
};


class Deer : public Roga, public Koputa
{
private:

public:
	Deer() :Roga(), Koputa() {};
	Deer(string color, int weight, string shape, int count) :Roga(color, weight), Koputa(shape, count) {};

	void show() 
	{
		Roga::show();
		Koputa::show();
	}
};
