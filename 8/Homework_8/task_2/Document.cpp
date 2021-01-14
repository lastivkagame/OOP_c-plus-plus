#include "Document.h"

Document::Document() :name(""), size(0) {}
Document::Document(string name, int size) : name(name), size(size) {}

Document::Document(const Document& obj)
{
	name = obj.name;
	size = obj.size;
}

Document& Document::operator=(const Document& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	this->name = obj.name;
	this->size = obj.size;

	return *this;
}

Document& Document::operator=(Document&& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	this->name = obj.name;
	this->size = obj.size;
	
	return *this;
}

Document::Document(Document&& obj)
{
	*this = move(obj);
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