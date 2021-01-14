#include "Array.h"
#include <string>

int main() {

	Array <int>arr;
	arr[0] = 10;
	arr[1] = 40;
	arr[2] = 20;
	arr[3] = 30;
	arr[4] = 15;

	cout << arr << endl;

	Array <double>arrD(3);
	arrD[0] = 12.5;
	arrD[1] = -6.8;
	arrD[2] = 34.67;

	cout << "Double Array<double>\n";
	cout << arrD << endl;

	cout << "Max Array <double> = " << arrD.Max() << endl;

	Array<string> arrS(3);
	arrS[0] = "C++";
	arrS[1] = "Design patterns";
	arrS[2] = "Assembler";
	cout << endl;
	cout << "arrS = " << arrS << endl;
	cout << "Max of arrS = " << arrS.Max() << endl;

	Array<const char*>arrC(3);
	arrC[0] = "C++";
	arrC[1] = "Design patterns";
	arrC[2] = "Assembler";

	cout << arrC << endl;
	cout << "Max of arrC = " << arrC.Max() << endl;
	system("pause");
	return 0;
}