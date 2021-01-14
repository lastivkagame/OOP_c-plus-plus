#include "Auto.h"

int main() 
{
	cout << "Auto myauto(200, 150, opel, AB12900B): ";
	Auto myauto(200, 150, "opel", "AB12900B");
	cout << "---------------------------------------------"<<endl;

	cout << "Auto myauto(40, 150, opel, AB1234DC): \n";
	Auto myauto3(40, 150, "opel", "AB1234DC");
	cout << "---------------------------------------------" << endl;

	cout << "Auto myauto(40, 150, opel, Ab1234DC): \n";
	Auto myauto4(40, 150, "opel", "Ab1234DC");
	cout << "---------------------------------------------" << endl;

	double potokSpeed, maxSpeed;
	string marka, numberAuto;

	cout << "enter potokSpeed: ";
	cin >> potokSpeed;

	cout << "enter maxSpeed: ";
	cin >> maxSpeed;

	cout << "enter marka: ";
	cin >> marka;

	cout << "enter numberAuto: ";
	cin >> numberAuto;

	Auto myauto2(potokSpeed, maxSpeed, marka, numberAuto);

	system("pause");
	return 0;
}