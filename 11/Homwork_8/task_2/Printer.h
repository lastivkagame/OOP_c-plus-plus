#pragma once
#include <string>
#include "Document.h"
#include "Spooler.h"

/* Принтер -- клас Printer, котрий знає:
 екземпляр Spooler-а, у якого запитуватиме документи
 документ, котрий друкує в даний момент
 скільки часу залишилося до завершення, або момент завершення*/

class Printer
{
private:
	int time;
	Document doc;
	Spooler spool;
public:
	Printer();
	Printer(int time, Document doc, Spooler spool);
	Printer(const Printer& obj);

	void PrintQueue()const;
	void StartWork();

	void AddDoc(string el, int priv, Document doc);
};