/*����������� ����� String, ������� � ���������� �����
�������������� ��� ������ �� ��������. ����� ������
���������:
-	 ����������� �� ���������, ����������� �������
������ ������ 80 ��������;
-	 �����������, ����������� ��������� ������ ������������� �������;
-	 �����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������.
-	 ���������� ������� ����������, � ����� ������������ ��������� ������������� �������������, ���� ���
��������.
-	 ����� ������ ��������� ������ ��� ����� ����� � ���������� � ������ ����� �� �����.*/

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




