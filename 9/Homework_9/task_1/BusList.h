#pragma once
#include <string>
#include <iostream>
using namespace std;

class BusList
{
	class Bus
	{
	public:
		string number;
		string driver;
		int numRoute;

		Bus* pPrev;
		Bus* pNext;

		Bus() = default;
		Bus(string number, string driver, int numRoute) :number(number), driver(driver), numRoute(numRoute), pNext(nullptr) {};
	};

	Bus* pHead;
	Bus* pTail;

public:
	BusList();

	// + element
	void AddHead(string number, string driver, int numRoute);
	void AddTail(string number, string driver, int numRoute);
	void Insert(string after, string number, string driver, int numRoute);

	//- element
	void DelTail();
	void DelHead();
	void DelCurrent(int el);

	// get
	string GetNumber(int el);
	string GetDriver(int el);
	int GetnumRoute(int el);
	
	// other
	bool SearchElement(string el)const;
	void Clear();
	void Print()const;
	void SpesPrint(int el);
	int choose();
};

