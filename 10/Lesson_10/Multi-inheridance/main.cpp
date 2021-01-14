#include "Header.h"

int main() {

	Deer MyDeer("brown", 50, "other", 4);
	MyDeer.show();

	MyDeer.Roga::show();
	MyDeer.Koputa::show();

	system("pause");
	return 0;
}