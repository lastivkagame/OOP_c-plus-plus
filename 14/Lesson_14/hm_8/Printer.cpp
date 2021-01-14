#include "Printer.h"

Printer::Printer()
{
	this->time = 0;
}

Printer::Printer(const Printer& obj)
{
	this->time = obj.time;
	this->doc = obj.doc;
	this->spool = obj.spool;
}

Printer::Printer(Document &doc, Spooler &spool)
{
	this->time = 0;
	this->doc = doc;
	this->spool = spool;
}

void Printer::PrintQueue() const
{
	spool.show();
	cout << endl;
}

void Printer::StartWork()
{
	int size = spool.getCount();

	for (int i = 0; i < size; i++)
	{
		system("cls");

		time = this->spool.getDocument(i).GetSize() / 10;

		while (true)
		{
			if (time <= 0)
			{
				break;
			}

			PrintQueue();

			this->spool.getDocument(i).Print();
			this->spool.showEl(i);
			cout << " wait please document is printed\n ";
			cout << " progress: \t";

			for (int j = 0; j < 3; j++)
			{
				cout << " * ";
				Sleep(1000);
				time -= 1000;
			}
			Sleep(2000);
			time -= 2000;
			system("cls");
		}

		cout << "Successful this document is ready!\n";
		cout << " I began work on next\n";
		Sleep(1000);
		system("cls");
		this->spool.Del();
	}
}

void Printer::AddDoc(string el, int priv, Document &doc)
{
	spool.enqueue(el, priv, doc);
}
