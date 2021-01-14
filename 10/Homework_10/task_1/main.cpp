/*	1.Создайте класс Student, который будет содержать информацию о студенте.
С помощью механизма наследования, реализуйте класс Aspirant
(аспирант — студент, который готовится к защите кандидатской работы) производный от Student.*/

#include <iostream>
#include "Student.h"
#include "Aspirant.h"
using namespace std;

int main() {

	Aspirant st2("Candidate work", "07.05.XX", "P.T.Petrow", 84896, "economic", " bookkeeper");
	st2.Print();

	return 0;
}