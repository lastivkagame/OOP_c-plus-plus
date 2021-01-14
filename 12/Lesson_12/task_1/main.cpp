#include <iostream>
using namespace std;

void ChangeAgr(const int* a) 
{
	//*a = 100;  // error, a - const
	int *pA = const_cast<int*>(a);  // do a - no const
	*pA = 1000;
}

class Test
{
private:
	int a;
public:
	Test(int a = 222) :a(a) {};

	void SetA(int a) 
	{
		this->a = a;
	}

	int GetA()const
	{
		return this->a;
	}

	void Show()const 
	{
		Test* temp = const_cast<Test*>(this);
		(temp->a)++;
		cout << " from Test = " << a << endl;
	}

};

int main() {

#pragma region static_cast
	//float d = 123.678;  // ne yavne privedena do tupy
	//int a;

	//a = d;
	//cout << " a = " << a << endl;

	//int i = 97;
	//char s = i;
	//cout << "int to char: s = " << s << endl;

	//int b = 2;
	//cout << " a / b = 123 / 2 = " << (float)a / b << endl; // C - style cast
	////----------------------------------------------------------
	//float res = static_cast<float>(a) / b;
	//cout << " static_cast<float> (res) = " << res << endl;
#pragma endregion

#pragma region const_cast<int*>
	//int a = 10;

	//ChangeAgr(&a);
	//cout << " a = " << a << endl;

	//const int aa = 50;
	//ChangeAgr(&aa);
	//cout << " const &aa = " << aa << endl;
	////int b = const_cast<int>(aa); - error
#pragma endregion


	Test obj;
	obj.Show();
	obj.SetA(100);
	obj.Show();

	const Test obj2(50);
	obj2.Show();
//	obj2.SetA(100);  error becouse SetA() - no const



	system("pause");
	return 0;
}