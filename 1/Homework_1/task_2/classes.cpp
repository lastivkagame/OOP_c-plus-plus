#include "classes.h"

employee::employee(int number1, float salary1)
{
	SetNumber(number1);
	SetSalary(salary1);
}

void employee::print()
{
	cout << "  Eployee \n";
	cout << "  Number: " << number << endl;
	cout << "  Salary: " << salary << endl;
}

int employee::GetNumber()
{
	return number;
}

float employee::GetSalary()
{
	return salary;
}

void employee::SetNumber(int number1)
{
	number = number1;
}

void employee::SetSalary(float salary1)
{
	salary = salary1;
}