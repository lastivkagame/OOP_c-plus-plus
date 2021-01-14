#include <iostream>
#include <string>
using namespace std;

template <typename T>
T Max(T x, T y)   //узагальнений шаблон
{
	cout << "General template works! T Max(T x, T y) \n";
	return x > y ? x : y;
}

template <typename T>
T Max( T** arr, int rows, int cols)   //узагальнений шаблон
{
	T max = tolower(arr[0][0]);

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (tolower(arr[i][j]) > max)
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}

template<>char Max( char** arr, int rows, int cols) 
{
	char max = tolower(arr[0][0]);

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (tolower(arr[i][j]) > max)
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}

template<>float Max(float x, float y)  //спеціалізація шаблону Max для типу float
{
	cout << "Specializatio template works!  Max(T x, T y) \n";
	return x > y ? x : y;
}

template<>char Max(char x, char y)  //спеціалізація шаблону Max для типу float
{
	cout << "Specializatio template works!  Max(T x, T y) \n";
	return tolower(x) > tolower(y) ? x : y;
}

float Max(float x, float y)   //звичайна функція
{
	cout << "Ordinary function works! float Max(T x, T y) \n";
	return x > y ? x : y;
}

char Max(char x, char y) //звичайна функція
{
	cout << "Usual function works! char Max(T x, T y) \n";
	return tolower(x) > tolower(y) ? x : y;  //tolower - переведи в нижній регістр(робить малі букви); to upper -  робить великі букви
}

template <typename T>
T Max(const T arr[], int size) 
{
	T max = arr[0];

	for (int i = 1; i < size; i++) 
	{
		if (arr[i] > max) 
		{
			max = arr[i];
		}
	}
	return max;
}

template <typename T>
T Sum(T a, T b) 
{
	return a + b;
}

template <typename T1, typename T2>
auto Sum(T1 a, T2 b) //auto - дозволяємо компілятору визначити тип самостійно( компілятор сам вирішить сам який тип повернути)
{
	return a + b;
}

// ПРИОРІТИЕТ виклику:
//1)звичайна функція
//2)спеціалізація
//3) шаблонна іункція

int main() {

	cout << "Max(100,200): " << Max(100, 200) << endl; //T = double
	cout << "Max( - 10.5f,20,56f): " << Max(-10.5f, 20.56f) << endl; //ordinary
	cout << "Max<float>( - 10.5,20,56): " << Max<float>(-10.5, 20.56) << endl; //spec


	cout << "Max('a','Z') = " << Max('a', 'Z') << endl;  // standart
	cout << "Max('a','Z') = " << Max<char>('a', 'Z') << endl;   //template
	cout << "Max('a','Z') = " << Max<float>('a', 'Z') << endl;   //можна но не варто


	int arr[5] = { 4,7,23,1,3 };
	int * arr2 = new int[5]{ 4,7,23,1,3 };
	char * arr3 = new char[5]{ 68,78,97,65,20 };

	cout << "Max array: " << Max(arr, 5) << endl;
	cout << "Max array(arr2): " << Max(arr2, 5) << endl;
	cout << "Max array(arr3): " << Max(arr3, 5) << endl; //general

	cout << " Max('D','a') = " << Max('D', 'a') << endl;

	system("cls");

	char ** arr5 = new char*[1]; 
	arr5[0] = new char[2]{ 68,78 };
	arr5[1] = new char[2]{ 97, 65 };

	//char * arr6 = new char[2][2]{ 68,78,97,65 };

	cout << "Max(arr5): " << Max(arr5, 2, 2) << endl;
	cout << "Max<char>(arr5): " << Max<char>(arr5, 2, 2) << endl;

	cout << "----------------------\n";

	cout << "Sum(5, 8.5) = " << Sum(5, 8.5) << endl;

	system("cls");
	string str = "Hello world!";

	for (auto el : str)  //char el // compile define el as char
	{
		cout << el << ' ';
	}

	cout << endl;

	system("pause");
	return 0;
}