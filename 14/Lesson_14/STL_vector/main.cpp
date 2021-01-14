#include"Person.h"
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
void Print(vector<T> arr)
{
	//string line(30, '_');
	//cout << line << endl;
	//for (auto &elem : arr) можна й так
	for (T &elem : arr)
	{
		cout << elem << endl;
	}
	/*cout << endl << " Size: " << arr.size() << endl;
	cout << endl << " Capacity: " << arr.capacity() << endl;
	cout << line << endl;*/
	cout << endl;
}

bool compareAge(Student st1, Student st2)
{
	return st1.GetAge() < st2.GetAge();
}

int main()
{
	vector<Student> group({
		Student("Sasha", 18, 5),
		Student("Max", 23, 7),
		Student("Andriy", 15, 10),
		Student("Kolia", 25, 2),
		Student("Oksana", 20, 12)
		});

	Print(group);
	sort(group.begin(), group.end());
	cout << "Sort group by name";
	Print(group);

	cout << "Sort group  by mark";
	sort(group.begin(), group.end(), [](Student& st1, Student& st2) 
		{
			return st1.GetMark() < st2.GetMark();
		});

	Print(group);

	cout << "Sort group by age";
	sort(group.begin(), group.end(), compareAge);

	Print(group);

	system("pause");
	return 0;
}