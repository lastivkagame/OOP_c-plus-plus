#pragma once
#include "color.h"

class Dessign //���� � ����� ������ ���������� �������� (����� ����� ������������, ���� �� ����) 
{
public:
	int color = 12; //����� ��� ���� �������

	void FirstLoader(); //������ ���� ����� ��������
	
	int Menu();  // �����

	void Name(); // ������ �������� ����� ���
	
	void SpecialPrint(vector<string> temp, int el, int color = -1);  // ����� �� �������� �������� ������ �����(��� ������� ���� ��������) 
	
};