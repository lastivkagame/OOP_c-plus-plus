#pragma once
#include <iostream>
using namespace std;

class employee {
private:
	int number;
	float salary;
public:
	employee(int number1 = 0, float salary1 = 0);
	void print();

	int GetNumber();
	float GetSalary();

	void SetNumber(int number1);
	void SetSalary(float salary1);
};