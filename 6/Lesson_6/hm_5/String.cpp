#include "String.h"

int String::GetCount()
{
	return count;
}

//конструкторu
String::String() :String(80, "") {}
String::String(int size) : String(size, "") {}

String::String(int size, const char* str)
{
	this->size = size;
	SetStr(str);
	count++;
}

String::String(String& obj)
{
	this->size = size;
	SetStr(str);
	count++;
}

void String::SetSize(int size)
{
	this->size = size;
}

void String::SetStr(const char* str)
{
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
}

int String::GetSize()const
{
	return size;
}

char* String::GetStr() const
{
	return str;
}

void String::print() const
{
	cout << str << endl;
}

String& String::operator=(const String& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	SetSize(obj.GetSize());
	SetStr(obj.GetStr());

	return *this;
}

String& String::operator*(const String& right)
{
//	char* strg = new char[strlen(right.GetStr()) + 1];
	char strg[100];
	int k = 0;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < right.GetSize(); j++)
		{
			if (this->operator[](i) == right[j])
			{
				strg[k++] = right.GetStr()[j];
				
			}
		}
	}

	char* ready = new char[strlen(strg) + 1];

	strcpy_s(ready, strlen(strg) + 1, strg);

	delete[]strg;

	String temp(strlen(ready), ready);

	delete[]ready;

	return temp;
}

String& String::operator+(const String& right)
{
	char* strTemp = new char[(right.GetSize() + this->GetSize() + 1)];
	int k = 0;

	//хай буде 2 циклами так простіше сприймати 
	for (int i = 0; i < this->GetSize(); i++)
	{
		strTemp[k++] = this->str[i];
	}

	for (int i = 0; i < right.GetSize(); i++)
	{
		strTemp[k++] = right.GetStr()[i];
	}

	String temp((strlen(strTemp) + 1), strTemp);
	delete[]strTemp;

	return temp;
}

String& operator+(const char* right, const String& left)
{
	char* strTemp = new char[(left.GetSize() + strlen(right) + 1)];
	int k = 0;

	//хай буде 2 циклами так простіше сприймати 
	for (int i = 0; i < left.GetSize(); i++)
	{
		strTemp[k++] = left.GetStr()[i];
	}

	for (int i = 0; i < strlen(right); i++)
	{
		strTemp[k++] = right[i];
	}

	String temp((strlen(strTemp) + 1), strTemp);
	delete[]strTemp;

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

String& String::operator()(int start, int end)
{
	String temp;
	int k = 0;

	if (start >= 0 && start < this->GetSize())
	{
		if (end > 0 && end < this->GetSize())
		{
			for (int i = start; i <= end; i++)
			{
				temp[k++] = this->GetStr()[i];
			}
		}
	}

	return temp;
}

String& String::operator()(int start)
{
	String temp;
	int k = 0;

	if (start >= 0 && start < this->GetSize())
	{
		for (int i = start; i < this->GetSize(); i++)
		{
			temp[k++] = this->GetStr()[i];
		}
	}

	return temp;
}

String& String::operator()()
{
	String temp;
	int k = 0;

	for (int i = 0; i < this->GetSize(); i++)
	{
		temp[k++] = this->GetStr()[i];
	}

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

	for (int i = 0; i < size; i++)
	{
		str[i]++;
	}

	return temp;
}

String& String::operator++()
{
	for (int i = 0; i < size; i++)
	{
		str[i]++;
	}

	return *this;
}

bool String::operator<(const String& right)
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

bool String::operator>(const String& right)
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

bool String::operator>=(const String& right)
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

bool String::operator<=(const String& right)
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
void String::operator!()
{
	char* strg = new char[this->GetSize() + 1];
	int j = this->GetSize();

	for (int i = 0; i < this->GetSize(); i++)
	{
		strg[i] = this->GetStr()[j--];
	}

	this->SetStr(strg);
	delete[]strg;
}


