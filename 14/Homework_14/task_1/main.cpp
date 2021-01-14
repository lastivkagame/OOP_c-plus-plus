/*Створити масив екземплярів Персон(ім’я, вік).
Впорядкувати масив об’єктів з використанням алгоритму sort() та лямбда- функцій:
o за зростанням імені;
o за спаданням віку;
o за зростанням віку, персони однакового віку впорядковуються за зростанням імен*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person(string name = "none", int age = 0) :name(name), age(age) {};

	friend ostream& operator<<(ostream& out, const Person& st)
	{
		out << "Name: " << st.name << endl;
		out << "Age: " << st.age << endl;
		return out;
	}

	bool operator<(Person& p)
	{
		return this->GetName() < p.GetName();
	}

	bool operator>(Person& p)
	{
		return this->GetName() > p.GetName();
	}

	string GetName()const
	{
		return this->name;
	}

	int GetAge()const
	{
		return this->age;
	}
};

template <typename T>
void Print(vector<T> arr)
{
	for (T& elem : arr)
	{
		cout << elem << endl;
	}
	cout << endl;
}

int main()
{
	vector<Person> persons({ Person("W", 17), Person("C", 15),Person("A", 20),Person("W", 18),Person("H", 15) });

	cout << " - Without sort - \n";
	Print(persons);

	cout << " - Sort by name(<-) - \n";
	sort(persons.begin(), persons.end());
	Print(persons);

	cout << " - Sort by age(->) - \n";
	sort(persons.begin(), persons.end(), [](Person& st1, Person& st2)
		{
			return st1.GetAge() > st2.GetAge();
		});
	Print(persons);

	cout << " - Sort by age(->),(if they = ->sort by name(->)) - \n";
	sort(persons.begin(), persons.end(), [](Person& st1, Person& st2)
		{
			if (st1.GetAge() != st2.GetAge())
			{
				return st1.GetAge() < st2.GetAge();
			}
			else
			{
				return st1 < st2;
			}
		});
	Print(persons);

	return 0;
}