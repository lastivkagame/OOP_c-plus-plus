#include "Person.h"

Person::Person() :Person(0, "empty", "undefined")
{
	//cout << "default C-tor Person\n";
};

Person::Person(int age, string name, string sex)
{
	//cout << "Overload c-tor person\n";
	this->age = age;
	this->name = name;
	this->sex = sex;
}

void Person::Print() const
{
	cout << " Person: \n";
	cout << " Age: " << age << endl;
	cout << " Name: " << name << endl;
	cout << " Sex: " << sex << endl;
}

void Person::PutInfo()
{
	cout << "Enter name: ";
	cin >> name;

	cout << "Enter age: ";
	cin >> age;

	cout << "Enter sex: ";
	cin >> sex;
}

int Person::GetAge() const
{
	return age;
}

string Person::GetName() const
{
	return name;
}

string Person::GetSex() const
{
	return sex;
}

Student::Student() :Person()
{
	//cout << "default C-tor Student";
	spec = "null";
	id = -99999998;
	group = "null";
}

Student::Student(string spec, string group, int age, string name, string sex) :Person(age, name, sex)
{
	//cout << "Overload c-tor student(spec, group, age, name,sex)\n";
	this->spec = spec;
	this->group = group;
	this->id = rand() % 10000 + 10;
}

Student::Student(string spec, string group, Person & p) :Person(p)
{
	//cout << "Overload c-tor student(spec, group, Person&p)\n";
	this->spec = spec;
	this->group = group;
	this->id = rand() % 10000 + 10;
}

void Student::PutInfo()
{
	Person::PutInfo();
	cout << "Enter spec: ";
	cin >> spec;

	cout << "Enter group: ";
	cin >> group;
}

int Student::GetId() const
{
	return id;
}

string Student::GetSpec() const
{
	return spec;
}

string Student::GetGroup() const
{
	return group;
}

void Student::Print() const
{
	cout << "Student: " << endl;
	Person::Print();
	cout << " Spec: " << spec << endl;
	cout << " Group: " << group << endl;
	cout << " Id: " << id << endl;
}

Employee::Employee() :Person()
{
	//cout << "default C-tor Eployee\n";
	placeWork = "null";
	wage = 0;
	position = "null";
}

Employee::Employee(string placeWork, string position, double wage, int age, string name, string sex) :Person(age, name, sex)
{
	cout << "Overload c-tor Eployee(string placeWork, string position, double wage, age, name, sex)\n";
	this->position = position;
	this->placeWork = placeWork;
	this->wage = wage;
}

Employee::Employee(string placeWork, string position, double wage, Person & p) :Person(p)
{
	//cout << "Overload c-tor Eployee(string placeWork, string position, double wage, age, name, sex)\n";
	this->position = position;
	this->placeWork = placeWork;
	this->wage = wage;
}

string Employee::GetPlaceWork()const
{
	return placeWork;
}

string Employee::GetPosition()const
{
	return position;
}

double Employee::GetWage()const
{
	return wage;
}

void Employee::PutInfo()
{
	Person::PutInfo();
	cout << "Enter work place: ";
	cin >> placeWork;

	cout << "Enter position: ";
	cin >> position;

	cout << "Enter wage: ";
	cin >> wage;
}

void Employee::Print() const
{
	Person::Print();

	cout << " Work Place: " << placeWork << endl;
	cout << " Position: " << position << endl;
	cout << " Wage: " << wage << endl;
}

Manager::Manager() :Employee()
{
	//cout << "default C-tor Manager\n";
	count = 0;
}

Manager::Manager(int count, Employee * arr, string placeWork, string position, double wage, int age, string name, string sex) :Employee(placeWork, position, wage, age, name, sex)
{
	this->count = count;
	this->arr = new Employee[count];

	for (int i = 0; i < count; i++)
	{
		this->arr[i] = arr[i];
	}
}

Manager::Manager(int count, Employee * arr)
{
	this->count = count;
	this->arr = new Employee[count];

	for (int i = 0; i < count; i++)
	{
		this->arr[i] = arr[i];
	}
}

Manager::Manager(int count, Employee & p) :Employee(p)
{
	this->count = count;
	this->arr = new Employee[count];
}

void Manager::RemoveEmpl(int el)
{
	Employee*arr2 = new Employee[count - 1];

	for (int i = 0; i < count; i++)
	{
		if (i != el)
		{
			arr2[i] = arr[i];
		}
	}

	count--;
	delete[]arr;
	arr = new Employee[count];

	for (int i = 0; i < count; i++)
	{
		arr[i] = arr2[i];
	}
}

void Manager::AddEmpl(int el)
{
	Employee*arr2 = new Employee[count + 1];
	Employee p;
	p.PutInfo();
	int k = 0;

	for (int i = 0; i < count + 1; i++)
	{
		if (i == el)
		{
			arr2[i] = p;
		}
		else
		{
			arr2[i] = arr[k++];
		}
	}

	count++;
	delete[]arr;
	arr = new Employee[count];

	for (int i = 0; i < count; i++)
	{
		arr[i] = arr2[i];
	}
}

void Manager::Print() const
{
	cout << "     ---Arr---  \n ";
	for (int i = 0; i < count; i++)
	{
		arr[i].Print();
	}
	cout << endl;
}

Employee * Manager::GetArr() const
{
	return arr;
}

int Manager::GetCount() const
{
	return count;
}

Manager::~Manager()
{
	if (arr != nullptr)
	{
		delete[]arr;
		arr = nullptr;
	}
}
