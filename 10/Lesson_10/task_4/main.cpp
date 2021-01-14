#include "CircleInSquare.h"
#include <iostream>
using namespace std;

int main() {

	double side, radius;
	cout << "Enter side and next radius: ";
	cin >> side >> radius;

	CircleInSquare obj(side, radius);

	cout << "  ---Obj-- \n";
	cout << " Area circle: " << obj.Circle::Area() << endl;
	cout << " Area square: " << obj.Square::Area() << endl;
	cout << " AreaPartFigure: " << obj.AreaPartFigure() << endl;
	cout << " CircleLength: " << obj.CircleLength() << endl;
	cout << " Perumentr: " << obj.Perumentr() << endl;
	cout << " totalLength: " << obj.totalLength() << endl;
	cout << " GetSide: " << obj.GetSide() << endl;
	cout << " GetRadius: " << obj.GetRadius() << endl;

	system("pause");
	system("cls");

	obj.SetRadius(2);
	cout << " \n\n-set radius 5-\n";
	cout << " GetSide: " << obj.GetSide() << endl;
	cout << " GetRadius: " << obj.GetRadius() << endl;
	cout << "\n\ -nset side 4- \n";
	obj.SetSide(8);
	cout << " GetSide: " << obj.GetSide() << endl;
	cout << " GetRadius: " << obj.GetRadius() << endl;

	system("pause");
	system("cls");

	cout << "  ---Obj-- \n";
	cout << " Area circle: " << obj.Circle::Area() << endl;
	cout << " Area square: " << obj.Square::Area() << endl;
	cout << " AreaPartFigure: " << obj.AreaPartFigure() << endl;
	cout << " CircleLength: " << obj.CircleLength() << endl;
	cout << " Perumentr: " << obj.Perumentr() << endl;
	cout << " totalLength: " << obj.totalLength() << endl;
	cout << " GetSide: " << obj.GetSide() << endl;
	cout << " GetRadius: " << obj.GetRadius() << endl;

	system("pause");
	return 0;
}
