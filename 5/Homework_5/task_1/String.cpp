#include "String.h"

//конструкторu
String::String() :String(80, "") {}  // конструктор по замовчуванню
String::String(int size) : String(size, "") {}  //конструктор, який дозволяє створити рядок довільного розміру, вміст рядка “”

String::String(int size, const char* str) //все і розмір і строка
{
	this->size = size;
	SetStr(str);
	count++;
}

String::String(String& obj)  //конструктор копій
{
	this->size = obj.size;
	this->SetStr(obj.str);
	count++;
}

//сеттери
void String::SetSize(int size)
{
	this->size = size;
}

void String::SetStr(const char* str)
{
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
}

//геттери
int String::GetSize()const
{
	return this->size;
}

char* String::GetStr() const
{
	return this->str;
}

int String::GetCount()  //статичний метод доступу до count
{
	return count;
}

void String::print() const
{
	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i];
	}
}

//other
String& String::operator=(const String& obj)  //c-tor copy
{
	if (this == &obj)
	{
		return *this;
	}
	delete[]this->str;
	this->SetSize(obj.GetSize());
	this->SetStr(obj.GetStr());
	// а де move = ? це була домашня перед тим як ми вчили 
	return *this;
}

//операції 
String String::operator*(const String& right)   //результатом перетину рядків "Microsoft" та "Windows" буде рядок "ioso".
{
	char* strg = new char[strlen(right.GetStr()) + 1];
	//String temp(strlen(right.GetStr()));
	//char strg[100];
	int k = 0;

	for (int i = 0; i < strlen(this->GetStr()); i++)
	{
		for (int j = 0; j < strlen(right.GetStr()); j++)
		{
			if (this->operator[](i) == right[j])
			{
				strg[k++] = right.GetStr()[j];

			}
		}
	}
	strg[k++] = '\0';

	char* strg2 = new char[strlen(strg) + 1];
	strcpy_s(strg2, strlen(strg) + 1, strg);

	String temp(strlen(strg2) + 1, strg2);
	//бо створився об'єкт про який юзер не знає
	count--;

	delete[]strg;
	delete[]strg2;

	return temp;
}

String String::operator+(const String& right)  //додає 2 рядки
{
	char* strTemp = new char[strlen(right.GetStr()) + strlen(this->GetStr()) + 1];
	int k = 0;

	//хай буде 2 циклами так простіше сприймати 
	for (int i = 0; i < strlen(this->GetStr()); i++)
	{
		strTemp[k++] = this->str[i];
	}

	for (int i = 0; i < strlen(right.GetStr()); i++)
	{
		strTemp[k++] = right.GetStr()[i];
	}

	strTemp[k++] = '\0';

	String temp((strlen(strTemp) + 1), strTemp);
	delete[]strTemp;

	//бо створився об'єкт про який юзер не знає
	count--;

	return temp;
}

String operator+(const char* right, const String& left)
{
	char* strTemp = new char[((strlen(left.GetStr()) + (strlen(right)) + 1))];
	int k = 0;

	//хай буде 2 циклами так простіше сприймати 
	for (int i = 0; i < strlen(right); i++)
	{
		strTemp[k++] = right[i];
	}

	for (int i = 0; i < strlen(left.GetStr()); i++)
	{
		strTemp[k++] = left.GetStr()[i];
	}

	strTemp[k++] = '\0';

	String temp((strlen(strTemp) + 1), strTemp);
	//delete[]strTemp;

	//бо створився об'єкт про який юзер не знає
	String::count--;

	return temp;
}

char& String::operator[](int index) const
{
	if (index >= 0 && index < size)
	{
		return str[index];
	}

	throw "index error"; //генеруємо помилку!
}

String String::operator()(int start, int end)
{
	String temp;
	int k = 0;

	if (start >= 0 && start < strlen(this->GetStr()))
	{
		if (end > 0 && end < strlen(this->GetStr()))
		{
			for (int i = start; i <= end; i++)
			{
				temp[k++] = this->GetStr()[i];
			}
		}
	}
	temp[k++] = '\0';
	//бо створився об'єкт про який юзер не знає
	count--;

	return temp;
}

String String::operator()(int start)
{
	String temp;
	int k = 0;

	if (start >= 0 && start < strlen(this->GetStr()))
	{
		for (int i = start; i < strlen(this->GetStr()); i++)
		{
			temp[k++] = this->GetStr()[i];
		}
	}
	temp[k++] = '\0';
	//бо створився об'єкт про який юзер не знає
	count--;

	return temp;
}

String String::operator()()
{
	String temp;
	int k = 0;

	for (int i = 0; i < strlen(this->GetStr()); i++)
	{
		temp[k++] = this->GetStr()[i];
	}
	temp[k++] = '\0';
	//бо створився об'єкт про який юзер не знає
	count--;

	return temp;
}

String& String::operator+=(const String& right)
{
	*this = (*this + right);
	return *this;
}

String& String::operator++(int)
{
	String temp = *this;

	for (int i = 0; i < strlen(str); i++)
	{
		str[i]++;
	}

	//бо створився об'єкт про який юзер не знає
	count--;

	return temp;
}

String& String::operator++()
{
	for (int i = 0; i < strlen(str); i++)
	{
		str[i]++;
	}

	return *this;
}

bool String::operator<(const String& right)
{
	if (this->GetSize() > right.GetSize())
	{
		return true;
	}
	else
	{
		return false;
	}

	//можна було б і окремо винести якщо рівне(але тоді що повертати правду чи неправду )
	//хоча можна було б генерувати помилку але хай так буде
}

bool String::operator>(const String& right)
{
	if (this->GetSize() < right.GetSize())
	{
		return true;
	}
	else
	{
		return false;
	}
	//можна було б і окремо винести якщо рівне(але тоді що повертати правду чи неправду )
	//хоча можна було б генерувати помилку але хай так буде
}

bool String::operator>=(const String& right)
{
	if (this->GetSize() <= right.GetSize())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator<=(const String& right)
{
	if (this->GetSize() >= right.GetSize())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator==(const String& right)
{
	for (int i = 0; i < strlen(this->GetStr()); i++)
	{
		if (this->GetStr()[i] != right.GetStr()[i])
		{
			return false;
		}
	}

	return true;
}

bool String::operator!=(const String& right)
{
	for (int i = 0; i < strlen(this->GetStr()); i++)
	{
		if (this->GetStr()[i] != right.GetStr()[i])
		{
			return true;
		}
	}

	return false;
}
String String::operator!()  //здійснити реверс рядка. Наприклад, результатом реверсу String'а "Windows" буде новий String "swodniW".
{
	int size = strlen(this->GetStr()) + 1;
	char* strg = new char[size];
	int j = strlen(this->GetStr()) - 1;

	for (int i = 0; i < strlen(this->GetStr()) + 1; i++)
	{
		if (i == strlen(this->GetStr()))
		{
			j = strlen(this->GetStr());
			strg[j] = '\0';

			this->SetStr(strg);
			return *this;
		}

		strg[i] = this->GetStr()[j--];
	}
}

//операції для введення та виведення рядка
ostream& operator<<(ostream& os, const String& right)
{
	//right.print();
	os <<right.str <<  endl;
	return os;
}

istream& operator>>(istream& is, String& right)
{
	for (int i = 0; i < right.GetSize(); i++)
	{
		is >> right[i];
	}
	return is;
}