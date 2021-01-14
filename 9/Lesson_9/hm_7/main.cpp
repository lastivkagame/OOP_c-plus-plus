/*  ------��������-------
�������� ������ ����� ������.
������ �� ������� ����� �������� ����, �� ���� �������� ������� �ᒺ��� ���������� ����� .
������������ ������ ������� ����� ��� ���� int(double), string �� ��������������� ����(Fraction �� ��).
�������� ���� ������, �� ����������� ����� �������� ������������ ������������ �����.

��������� ����:
  T *buffer � �������� �� ��������� ����� ����� �����;
  capacity - ����� ������(� �������),
  size � ��������� ����� �������(�������� ������� �������� �������)

��������� ������� ������ �����: ������������ � �����������(����������� ����������� ������������)
  Vector(size_t size) � ������� ���`��� ��� ������, ��������� ����� = size, ������- ���� �������, �������� - ���
  Vector(size_t size, int value) � ������� ������ ��� ������, ��������� ����� = size, ������- ���� �������, �������� = value
  ����������� �� ������������� � ����� �������
  ����������� ��ﳿ
  ����������
  ����� �������(�� �������) �� ���� capacity �� size
  ����� �������� �� ������ ������(�� ��������� ������� =0, bool empty())
  ����� ������������(����) �������� �� ��������(void setValue(int index, T value)
  ����� �������(�������) �������� �� ��������
  ����� ��������� ������ ��������(pushBack(T elem)) � ����� ������( ��� �����, ���� ������� �� �������� capacity)
  ����� ��������� ���������� ��������(popBack()), ��������� �� ����� ��������
  �����, �� ������� ��������� �� ������ ������� ������� T & front(), ���� ������ ������ ��������� ��������� �� ����� �������� �������� ����� ������
T & front()
{
 int static errorFront = 0;
 if (empty())
 return errorFront;
 //....
}

  �����, �� ������� ��������� �� ������� ������� ������� T & back(), ���� ������ ������ ��������� ��������� �� ����� �������� �������� ����� ������
  ����� ������� ������ �������� �� �������� ��������(��������� ������)
  ����� ��������� �������� �� ��������(��������� ������)
  ����� ������� �������(clear()), capacity �� ��������
  ����� ���� capacity(reserve(size_t newCapacity), ��� �� ����������� ��� ��������� capacity, �� ��������� ���������� capacity
  ����� ���� �������� ������� ������ void resize(size_t newSize, int value = 0), ������ ������ ���� ������� - ����������
  ����� ������ ������*/

#include <iostream>
#include <string>
#include "Vector.h"
#include "Fractions.h"

using namespace std;

int main()
{
	//������������ ������ ������� ����� ��� ���� int(double), string �� ��������������� ����(Fraction �� ��).
	Vector <int> i(2, 4);
	Vector <double> dbl(5, 5.5);
	Vector <string> str(3, "w");
	Vector <double> d = dbl;
	Vector <Fractins> frac(5, 10);

	cout << "This Vector type int: ";
	i.Print();

	cout << "\nThis Vector type double: ";
	dbl.Print();

	cout << "\nThis Vector type copy double: ";
	d.Print();

	cout << "\nThis Vector type string: ";
	str.Print();

	cout << "\nThis Vector type Fractions: ";
	//cout << frac << endl;                              
//	frac.Print();                                      

	cout << endl << endl;
	system("pause");
	system("cls");

	//����� �������(�� �������) �� ���� capacity �� size
	cout << "\nSize i = " << i.GetSize() << "\tCapacity i = " << i.GetCapacity() << endl << endl;

	// ����� �������� �� ������ ������
	cout << " d is empty? - " << boolalpha << d.Empty() << endl;

	//����� ������������(����) �������� �� ��������(void setValue(int index, T value) 
	cout << endl;
	dbl.Print();
	cout << endl;
	cout << " dbl.SetValue(3, 3.3): \n";
	dbl.SetValue(3, 3.3);
	dbl.Print();
	cout << endl;
	cout << endl;

	//����� �������(�������) �������� �� ��������
	//cout << "str.GetValue(1): " << str.GetValue(1) << endl;

	////����� ��������� ������ ��������(pushBack(T elem)) � ����� ������
	cout << "i:  " << i << endl;		
	cout << "i: ";
	i.Print();
	cout << " i.PushBack(3). i:  ";
	i.PushBack(3);
	cout << endl;
	i.Print();
	cout << endl;

	////����� ��������� ���������� ��������(popBack())
	//cout << " i.PopBack().i:  ";
	i.PopBack();
	cout << endl;
	i.Print();
	cout << endl;

	//// �����, �� ������� ��������� �� ������ ������� ������� T & front()
	//cout << " dbl adress first el: " << &dbl.GetFront() << endl;

	////�����, �� ������� ��������� �� ������� ������� ������� T & back()
	//cout << " dbl adress last el: " << &dbl.GetBack() << endl;

	//����� ������� ������ �������� �� �������� ��������
	cout << " We set new value s at 2-index in str. Str:  ";
	str.SetNewValue(2, "s");                                            //NOTWORK I DONT UNDENSTAND WHY IT HELP PLS
	str.Print();
	cout << endl;

	//����� ��������� �������� �� ��������
	cout << " We delete value that have 2-index in str. Str:  ";
	str.DeleteValue(2);                                                //NOTWORK I DONT UNDENSTAND WHY IT HELP PLS
	str.Print();
	cout << endl;

	/*//����� ������� �������(clear())*/

	i.Clear();
	cout << "i after clear(): " << i << endl;        //���� �� �� ������������ �� ���� ��������� ������������

	//����� ���� capacity(reserve(size_t newCapacity)

	cout << " d.Reserv(7): ";
	d.Reserv(7);
	d.Print();
	cout << endl;

	//����� ���� �������� ������� ������ void resize(size_t newSize, int value)
	cout << " d.Resize(6,9): ";
	d.Resize(6, 9);
	d.Print();
	cout << endl;



	
	system("pause");
	system("cls");

	cout << " --- All this only with Fractions ---  \n";

	cout << "\nSize frac = " << frac.GetSize() << "\tCapacity frac = " << frac.GetCapacity() << endl << endl;
	cout << " frac is empty? - " << boolalpha << frac.Empty() << endl;
	cout << endl;
	//frac.Print();
	cout << endl;
	cout << " frac.SetValue(1, 2): \n";
	frac.SetValue(1, 2);
	//frac.Print();
	cout << endl;
	cout << endl;
	cout << "frac.GetValue(1): " << frac.GetValue(1) << endl;
	cout << "frac: ";
	//frac.Print();
	cout << " frac.PushBack(3). i:  ";
	frac.PushBack(3);
	cout << endl;
	//frac.Print();
	cout << endl;
	cout << " frac.PopBack().i:  ";
	frac.PopBack();
	cout << endl;
	//frac.Print();
	cout << endl;
	cout << " frac adress first el: " << &frac.GetFront() << endl;
	cout << " frac adress last el: " << &frac.GetBack() << endl;
	cout << " We set new value s at 1-index in frac. frac:  ";
	frac.SetNewValue(1, 2);                                            //NOTWORK I DONT UNDENSTAND WHY IT HELP PLS
	//frac.Print();
	cout << endl;
	cout << " We delete value that have 1-index in frac. Frac:  ";
	frac.DeleteValue(2);                                                //NOTWORK I DONT UNDENSTAND WHY IT HELP PLS
	//frac.Print();
	cout << endl;
	frac.Clear();
	cout << "frac after clear(): " << i << endl;         //���� �� �� ������������ �� ���� ��������� ������������
	cout << " frac.Reserv(7): ";
	frac.Reserv(7);
	//frac.Print();
	cout << endl;
	cout << " frac.Resize(6,9): ";
	frac.Resize(6, 9);
	//frac.Print();
	cout << endl;
	

	system("pause");
	return 0;
}