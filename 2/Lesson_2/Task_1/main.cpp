#include "Point.h"

int Point::count = 0;

int main()
{
	Point p;
	p.Show();
	cout << "Count: " << Point::count << endl;

	Point p2(10, 20, "s");
	p.Show();

	const Point START(0, 0, "none");
	cout << "Start of system coordinates: " << START.GetX() << " " << START.GetY() << endl;

	START.Show();

	Point p3 = p2;

	p3.Show();

	p3.SetName("o");
	p3.Show();
	p2.Show();

	system("pause");

	return 0;
}