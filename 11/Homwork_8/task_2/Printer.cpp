#include "Printer.h"

Printer::Printer()
{
	this->time = 0;
}

Printer::Printer(int time, Document doc, Spooler spool)
{
	this->time = time;
	this->doc = doc;
	this->spool = spool;
}

Printer::Printer(const Printer& obj)
{
	this->time = obj.time;
	this->doc = obj.doc;
	this->spool = obj.spool;
}

void Printer::PrintQueue() const
{
	spool.show();
	cout << endl;
}

void Printer::StartWork()
{
	for (int i = 0; i < spool.getCount(); i++)
	{
		this->spool.getDocument(i);
		this->spool.Del();
		//Sleep(time);
	}
}

void Printer::AddDoc(string el, int priv, Document doc)
{
	spool.enqueue(el, priv, doc);
}
