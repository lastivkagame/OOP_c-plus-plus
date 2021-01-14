#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	int size;
	char* str;
	static int count;  //�������� �������� ���� � �������� �������� �� ����� ������ ���������� �����
public:
	//��������� ����� ������� �� count
	static int GetCount();

	//�����������u
	String();   //�-��� �� ������������
	String(int size);   // �-��� � �������(�� ���.)
	String(int size, const char* str);   // �-��� � ������� + �����
	String(String& obj);   //�-��� ����
	String(String&& obj); //����������� ���� � move

	//�������
	void SetSize(int size);
	void SetStr(const char* str);

	//�������
	int GetSize()const;
	char* GetStr() const;

	//����
	void print()const;
	String& operator=(const String& obj);
	String& operator=(String&& obj);  //������� = � �����������
	String operator*(const String& right);  //����������� �������� ����� "Microsoft" �� "Windows" ���� ����� "ioso".
	String operator+(const String& right);  //���� 2 �����
	friend String operator+(const char* right, const String& left);
	String& operator++(int);  //����������� ++ ��� ����� "Abcd" ���� "Bcde"
	String& operator++();

	//�������� ���������
	bool operator<(const String& right);
	bool operator>(const String& right);

	bool operator>=(const String& right);
	bool operator<=(const String& right);

	bool operator==(const String& right);
	bool operator!=(const String& right);

	//other
	String operator!();  //�������� ������ �����. ���������, ����������� ������� String'� "Windows" ���� ����� String "swodniW".
	char& operator[](int index) const;
	String operator()(int start, int end);
	String operator()(int start);
	String operator()();

	String& operator+=(const String& right);

	//�������� ��� �������� �� ��������� �����
	friend ostream& operator<<(ostream& os, const String& right);
	friend istream& operator>>(istream& is, String& right);

};