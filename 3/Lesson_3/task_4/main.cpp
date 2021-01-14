/*Разработать класс String, который в дальнейшем будет
использоваться для работы со строками. Класс должен
содержать:
-	 Конструктор по умолчанию, позволяющий создать
строку длиной 80 символов;
-	 Конструктор, позволяющий создавать строку произвольного размера;
-	 Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.
-	 Необходимо создать деструктор, а также использовать механизмы делегирования конструкторов, если это
возможно.
-	 Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран.*/

#include "class.h"

int main() {

	int size, choose;

	cout << " Object 1(default constructor): \n";
	String object1;
	object1.print();

	cout << " Object 2(size(for array) that user enter): \n";
	cout << " Size: ";
	cin >> size;
	String object2(size);
	object2.print();

	cout << " Object 3(char array): \n";
	String object3("Have a nice day!");
	object3.print();

	cout << "Do you want change some object ?\n";
	cout << " 1 - Yes\n";
	cout << " 2 - No\n";
	cout << "Answer: ";
	cin >> choose;

	system("pause");
	return 0;
}




