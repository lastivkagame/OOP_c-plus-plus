/*	1.�������� ����� Student, ������� ����� ��������� ���������� � ��������.
� ������� ��������� ������������, ���������� ����� Aspirant
(�������� � �������, ������� ��������� � ������ ������������ ������) ����������� �� Student.*/

#include <iostream>
#include "Student.h"
#include "Aspirant.h"
using namespace std;

int main() {

	Aspirant st2("Candidate work", "07.05.XX", "P.T.Petrow", 84896, "economic", " bookkeeper");
	st2.Print();

	return 0;
}