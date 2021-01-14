#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <functional>
#include <algorithm>  //для sort
using namespace std;

class Train
{
private:
	int number;
	string time;
	string station;
public:
	Train(int number = 0, string time = "", string station = "");

	friend ostream&operator<<(ostream&out, const Train &st);

	int GetNumber()const;
	string GetTime()const;
	string GetStation()const;

	void SetNumber(int number);
	void SetTime(string time);
	void SeStation(string station);

	~Train();
};

