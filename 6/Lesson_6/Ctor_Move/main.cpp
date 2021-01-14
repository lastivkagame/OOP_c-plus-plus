#include "Value.h"
#define LINE cout << "---------------------------------\n\n"

int Value::id = 0;

int main() 
{

	Value o1(12), o2(100), o3(200);

	cout << " " << o1 << " " << o2 << " " << o3 << endl;

	LINE;

	o1 = move(o2);
	cout << o1 << endl << o2 << endl;

	Value o4 = o1;
	cout << o4 << endl;

	LINE;

	Value o5 = move(o1);
	cout << o5;
	cout << o1;

	LINE;

	o3 = o3;
	cout << o3 << endl;

	LINE;

	cout << o3 << " " << o5 << endl;
	Value res = o3 + o5;
	cout << res;

	LINE;

	system("pause");
	return 0;
}