#pragma once

#pragma once

#include <iostream>
using namespace std;

class String {
private:
	char* someString;
	int size;
public:

	//������������
	String();
	String(int size);

	String(const char* someString = "none", int size = 20);

	//����������
	~String();

	//������� ������
	void print()const;

	//������ � �����
	char* GetSomeString()const;
	void SetSomeString(const char* someString);

	//����������� ����(��� ����)
	String(const String& obj);

};
