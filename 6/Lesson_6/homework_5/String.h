#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	int size;
	char* str;
	static int count;
public:
	//��������� ����� �������
	static int GetCount();

	//�����������u
	String();
	String(int size);
	String(int size, const char* str);
	String(String& obj);

	//�������
	void SetSize(int size);
	void SetStr(const char* str);

	//�������
	int GetSize()const;
	char* GetStr()const;

	//����
	void print()const;
	String& operator=(const String& obj);

	String& operator*(const String& right);

	String operator+(const String& right);
	friend String& operator+(const char* right, const String& left);
	String  operator++(int);
	String  operator++();

	//�������� ���������
	bool operator<(const String& right);
	bool operator>(const String& right);

	bool operator>=(const String& right);
	bool operator<=(const String& right);

	bool operator==(const String& right);
	bool operator!=(const String& right);

	void operator!();

	char& operator[](int index);

	String operator()(int start, int end);
	String operator()(int start);
	String operator()();

	void operator+=(const String& right);
};

