#pragma once
//FILO - first int last out
//FIFI - first int first out

class Stack  //�������� ���������
{
private:
	static const int MAX_SIZE = 5; //����������� ������� �-��� ��������
	int stack[MAX_SIZE];
	enum { EMPTY = -1 };
	int top = EMPTY; //������ ��������� ��������� ��������; ������ �������;
public:
	Stack() = default;
	void push(int el);
	bool pop(int& el);
	void clear();
	bool isEmpty()const;
	bool isFull()const;
	int GetCount()const; //�-��� �������� � �����
};