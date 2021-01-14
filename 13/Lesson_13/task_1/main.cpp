#include <iostream>
#include <string>
#include <exception>
using namespace std;

float division(float a, float b)
{
	if (b != 0) 
	{
		return a / b;
	}
	else
	{
		throw "Error! divide by zero!\n";  // generating error
	}
}

class SomeClass
{
private:
	int a;
public:
	class Error
	{
	public:

		string owner;
		int a;

		Error(string owner, int a) :owner(owner), a(a)
		{

		}
	};

	SomeClass(int a = 0) 
	{
		if (a < 0) 
		{
			throw Error("c-tor SomeClass(): number cant be 0", a);
		}

		this->a = a;
		cout << "C-tor works\n";
	}
	
	void Test() 
	{
		//...........
		throw Error("method Test()",a); //c-tor Error
	}
};

int main() 
{

#pragma region try catch
	//try
	//{
	//	float res = division(5, 0);
	//	cout << "After divide: ";  //we dont see this becouse is error in up code 
	//	cout << division(5, 2) << endl;  //we come to catch
	//}
	//catch (const char* ex)  // there we catch error by tupe const char*
	//{
	//	cout << ex << endl;
	//}
	////cerr <<  error is writing in potok and after we need clean potok

	//cout << "After\n";
#pragma endregion

#pragma region try catch with different type of error
	//try 
	//{
	//	//throw - 1; //int
	//	//throw 'A';
	//	//throw 4.5;
	//	throw "some error";
	//}
	//catch (int) 
	//{ 
	//	cout << "error int\n";
	//}
	//catch(char)
	//{
	//	cout << "error char\n";
	//}
	//catch (...) 
	//{
	//	cout << "Another type\n";
	//}
#pragma endregion

#pragma region try catch with class
	//try
	//{
	//	SomeClass obj1, obj2(100);
	//	//obj1.Test();  //throw
	//	obj2.Test();
	//}
	//catch (SomeClass::Error& ex) 
	//{
	//	cout << "Owner: " << ex.owner << " Number: " << ex.a << endl;
	//}

	//try
	//{
	//	SomeClass a(-100);
	//	a.Test();
	//}
	//catch (SomeClass::Error e)
	//{
	//	cout <<  e.owner << " Number: " << e.a << endl;
	//}
#pragma endregion

	try
	{
		const long SIZE = 300000000;
		int *arr = new int[SIZE];
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}