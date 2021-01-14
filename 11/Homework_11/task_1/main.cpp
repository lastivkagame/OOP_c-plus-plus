/*1. �������� ����������� ������� ���� Shape, �� ������:
o        ���� �������� ������� print(), printShapeName() � ��� ���������
o        �������� ������� �rea(),volume(), �� ���������� ������� ��������.


***printShapeName() � ����� ���������� �� ��������� typeid()

���� Point ��������� ��������� �rea(),volume() �� ����� Shape(����� �� ������� ����� �� �ᒺ�).
���� Circle  ��������� ��������� volume() �� ����� Point,  ��� �� ������ ��������� �rea().
����  Cylinder �� ����� ��������� ������� �rea()  �� volume().

�������� ����� �����(����� ��������� �� ������� ����).
��������� ������ ���������� �����, �ᒺ�� �� ��������� ��� ����� ������ � ������.
*/

#include <iostream>
#include "Circle.h"
#include "Cylinder.h"
#include "Point.h"
using namespace std;

int main()
{
	Circle circle(3);
	Cylinder cylinder(2, 4);

	Shape* figures[] = { &circle,&cylinder, new Point };

	for (int i = 0; i < 3; i++)
	{
		figures[i]->Print();
		cout << endl;
	}

	return 0;
}