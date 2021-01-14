#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	string str(48, '.'), str2("hello"), str3;
	//cin>>str;

	str += "dots.";
	str3 = str2 + " world";
	cout << str << endl;
	cout << "str3: " << str3 << endl;
	str3.append(" some text ");

	/*try
	{
	cout << "str3[-1] " << str3[-1] << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}*/

	try
	{
		cout << "str3.at(-1):  " << str3.at(-1) << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	cout << "str3.back: " << str3.back() << endl;
	cout << "str3.front: " << str3.front() << endl;

	cout << " capasity: " << str3.capacity() << endl;
	cout << " size: " << str3.size() << endl;
	cout << "max size str3: " << str3.max_size() << endl;
	//str3.clear();
	//cout << "after clear: ";
	//	cout << str3 << endl;

	cout << "compare: " << str2.compare("hello") << endl;

	//str3.clear();

	if (str3.empty())
	{

		cout << "string is empty\n";
	}

	//str3.insert(str3.begin(), '!');
	str3.insert(str3.end(), '!');
	cout << "after insert: " << str3 << endl;
	str3.pop_back();
	//		vid				do
	str3.replace(str3.begin(), str3.begin() + 5, "bye");
	cout << "after insert: " << str3 << endl;

	str3.reserve(51);

	cout << "afer reserve " << str3.capacity() << endl;

	cout << "substr(5,10) " << (str3 += str3.substr(5, 10)) << endl;

	str3.reserve(51);

	cout << endl;
	cout << endl;

	cout << " capasity: " << str3.capacity() << endl;
	cout << " size: " << str3.size() << endl;

	str3.shrink_to_fit();
	cout << " capasity: " << str3.capacity() << endl;
	cout << " size: " << str3.size() << endl;

	str3.resize(45, '.');
	cout << str3 << endl;

	sort()

	system("pause");
	return 0;
}