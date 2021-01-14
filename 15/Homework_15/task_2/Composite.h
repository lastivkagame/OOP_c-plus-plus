#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Element
{
private:
	string name;
public:
	static int num;
	static string namefile;
	ofstream fout;

	Element(string name = "fileComposite.html") :name(name) {};

	virtual void Add(Element* c) = 0;
	virtual void Closed() = 0;

	void Print() 
	{
		string temp;
		vector<string>text;
		ifstream read("fileComposite.html");
		while (!read.eof())
		{
			getline(read, temp);
			cout << temp << endl;
		}
	}

	string GetName()const
	{
		return name;
	}

	char GetNameIndex(int index)
	{
		return this->name[index];
	}

	virtual ~Element() {};
};

class Composite : public Element //composee
{
public:
	Composite(string name) :Element(name)
	{
		fout.open("fileComposite.html", ios_base::app);
		if (num == 0)
		{
			fout << namefile << endl;
			fout << "<div style = background - color: " << GetName() << " > \n";
			num++;
		}
		else
		{
			if (GetNameIndex(0) != '<' && GetNameIndex(1) != '<')
			{
				fout << "\n<div style = background - color: " << GetName() << " > \n";
			}
		}
		fout.close();
	};

	void Add(Element* c)override
	{
		fout.open("fileComposite.html", ios_base::app);

		if (c->GetNameIndex(0) == '<' || c->GetNameIndex(1) == '<')
		{
			fout << (c->GetName()) << endl;
		}

		fout.close();
	}

	void Closed()
	{
		fout.open("fileComposite.html", ios_base::app);
		fout << "</div>\n";
		fout.close();
	}

	~Composite() {};
};

class H1 :public Element
{
private:
	string extention;
public:
	H1(string name) :Element("<h1> " + name + "</h1>") {};

	void Add(Element* c)
	{
		throw exception("Invalid operation");
	}

	void Closed() {};
};

class H2 :public Element
{
private:
	string extention;
public:
	H2(string name) :Element("<h2> " + name + "</h2>") {};

	void Add(Element* c)
	{
		throw exception("Invalid operation");
	}

	void Closed() {};
};

class img :public Element
{
private:
	string extention;
public:
	img(string name, string opus) :Element("<img src='" + name + "' alt = '" + opus + "'>") {};

	void Add(Element* c)
	{
		throw exception("Invalid operation");
	}

	void Closed() {};
};