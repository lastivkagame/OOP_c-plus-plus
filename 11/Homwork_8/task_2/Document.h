#pragma once
#include <string>
#include <iostream>
using namespace std;

class Document
{
private:
	string name;
	int size;
public:
	Document();
	Document(string name, int size);
	Document(const Document& obj);

	void Print()const;

	void SetName(string name);

	string GetName()const;
	int GetSize()const;
};