#include "Document.h"

Document::Document() :name(""), size(0) {}
Document::Document(string name, int size) : name(name), size(size) {}

Document::Document(const Document& obj)
{
	name = obj.name;
	size = obj.size;
}

void Document::Print() const
{
	cout << " name: " << name << endl;
	cout << " size: " << size << endl;
}

void Document::SetName(string name)
{
	this->name = name;
}

string Document::GetName() const
{
	return this->name;
}

int Document::GetSize() const
{
	return this->size;
};