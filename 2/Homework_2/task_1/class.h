#pragma once

#include <iostream>
using namespace std;

class String {
private:
	int size;
	char* someString;
public:

	//������������
	String();
	String(int size);
	String(int size, const char* someString);

	//����������
	~String();

	//������� ������
	void print()const;

	//������� � ������
	char* GetSomeString()const;
	void SetSomeString(const char* someString);

	int GetSize()const;
	void SetSize(int size);

	//����������� ����(��� ����)
	String(const String& obj);

};