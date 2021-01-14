#pragma once
#include <iostream>
using namespace std;

#define LINE cout << "\n-------------------\n";

/*  --- About virtual class ---
 You can do class virtual:
  - create clearly virtual function (virtual void Draw() = 0;) -> you cant create obj abstract class
  -  write abstract before
But: you must crate about(opus) function in douther class
	
*/

class Shape /*abstract*/
{
public:
	virtual void Draw() = 0;  // do this class - virtual (class)
	/*{
		cout << " Shape\n";
	}*/

	virtual ~Shape()
	{
		cout << " ~Shape\n";
	}
};

class Square :public Shape
{
public:
	void Draw() override 
	{
		cout << "I'm " << typeid(*this).name() << endl;
		cout << " Square!\n";
	}

	~Square()
	{
		cout << " ~Square\n";
	}
};

class Circle :public Shape
{
public:
	void Draw()override
	{
		cout << "I'm " << typeid(*this).name() << endl;
		cout << " Circle!\n";
	}

	~Circle()
	{
		cout << " ~Circle\n";
	}
};

class Triangle :public Shape
{
public:
	void Draw() = 0; // do this class - virtual (class)
	/*{
		cout << "I'm " << typeid(*this).name() << endl;
		cout << " Triangl!\n";
	}*/

	~Triangle()
	{
		cout << " ~Triangle\n";
	}
};

class EqualSideTriangle: public Triangle
{
public:
	void Draw()
	{
		cout << "I'm " << typeid(*this).name() << endl;
		cout << " EqualSideTriangle!\n";
	}

	~EqualSideTriangle()
	{
		cout << " ~EqualSideTriangle\n";
	}
};