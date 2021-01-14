/*Створити клас Int, що імітує роботу стандартного типу int.
Наприклад, нехай код основної програми (в функції main()) для вбудованого типу int має наступний вигляд:
//при використанні змінних стандартного типу int
	int a = 8, b = 3, res = 0;
	res = a + b;
	res = a / b;
	cоut << res << еndl;
//при використанні об’єктів типу Int, аналогічний код буде мати вигляд
	Int a(8), b(3), res; // res: [0]
	res = a.sum(b); // res : [11]
	cоut << res.getValue() << еndl; // 11
	res = a.div(b); // res : [2]
	cоut << res.getValue() << еndl; // 2

Єдине поле даного класу повинно мати тип int.
Створити
	Конструктори( за замовчуванням та з одним параметром, Конструктор копій)
	Методи доступу до  поля класу

	Метод виведення значення на екран
	Метод додавання до даного екземпляру класу Int іншого екземпляру класу Int
	Метод віднімання від даного екземпляру класу Int іншого екземпляру класу Int
	Метод множення  даного екземпляру класу Int  на інший екземпляр класу Int
	Метод діленння  даного екземпляру класу Int  на інший екземпляр класу Int(врахувати, що ділення на 0 неможливе)

Напишіть програму, в якій будуть створені три об’єкта класу Int, два з яких будуть ініціалізовані.
Додайте два ініціалізованих об’єкта, присвойте результат третьому, а потім відобразіть результат на екран.
*/

#include<iostream>
using namespace std;

class Int
{
private:
	int number;
public:
	Int() :number(0) {}
	Int(int number) : number(number) {}
	Int(const Int& obj)
	{
		this->SetNumber(obj.GetNumber());
	}


	int GetNumber()const
	{
		return number;
	}

	void SetNumber(int number)
	{
		this->number = number;
	}

	void print()const
	{
		cout << number << endl;
	}

	Int Sum(const Int& a)
	{
		Int temp;
		temp.SetNumber(this->number + a.GetNumber());
		return temp;
	}

	Int Sub(const Int& a)
	{
		Int temp;
		temp.SetNumber(this->number - a.GetNumber());
		return temp;
	}

	Int Mnz(const Int& a)
	{
		Int temp;
		temp.SetNumber(this->number * a.GetNumber());
		return temp;
	}

	Int Del(const Int& a)
	{
		Int temp;
		if (a.GetNumber() != 0)
		{
			temp.SetNumber(this->number / a.GetNumber());
			return temp;
		}
		else
		{
			cout << "Inccorect! You can't divide by zero!\n";
			return -1;
		}
	}
};

int main()
{
	Int a(20);
	Int b(10);


	cout << "a = ";
	a.print();
	cout << endl;
	cout << "b = ";
	b.print();
	cout << endl;

	Int sum = a.Sum(b);
	cout << "Sum = a + b = ";
	sum.print();
	cout << endl;

	Int sub = a.Sub(b);
	cout << "Sub = a - b = ";
	sub.print();
	cout << endl;

	Int mnz = a.Mnz(b);
	cout << "Mnz = a * b = ";
	mnz.print();
	cout << endl;

	Int del = a.Del(b);
	cout << "Del = a / b = ";
	del.print();
	cout << endl;

	int choose, choose2, number;

	do
	{
		system("pause");
		system("cls");
		cout << " Menu:\n";
		cout << " 0 - change number\n";
		cout << " 1 - + numbers\n";
		cout << " 2 - - numbers\n";
		cout << " 3 - * numbers\n";
		cout << " 4 - / numbers\n";
		cout << " 5 - all\n";
		cout << " 6 - exit\n";
		cout << "Answer: ";
		cin >> choose;
		system("cls");

		switch (choose)
		{
		case 0:
			cout << " a = ";
			a.print();
			cout << " b = ";
			b.print();
			cout << endl;
			cout << "You want change:\n";
			cout << " 1 - a\n";
			cout << " 2 - b\n";
			cout << "Answer: ";
			cin >> choose2;

			if (choose2 == 1)
			{
				cout << "Enter number a\n";
				cin >> number;
				a.SetNumber(number);
			}
			else if (choose2 == 2)
			{
				cout << "Enter number a\n";
				cin >> number;
				b.SetNumber(number);
			}
			else
			{
				cout << "Inccorect direction!\n";
			}
			break;
		case 1:
			sum = a.Sum(b);
			cout << " Sum:  a + b = ";
			sum.print();
			cout << endl;
			break;
		case 2:
			sub = a.Sub(b);
			cout << " Sub: a - b = ";
			sub.print();
			cout << endl;
			break;
		case 3:
			mnz = a.Mnz(b);
			cout << " Mnz: a * b = ";
			mnz.print();
			cout << endl;
			break;
		case 4:
			del = a.Del(b);
			cout << " Del: a / b = ";
			del.print();
			cout << endl;
			break;
		case 5:
			sum = a.Sum(b);
			cout << "Sum = a + b = ";
			sum.print();
			cout << endl;

			sub = a.Sub(b);
			cout << "Sub = a - b = ";
			sub.print();
			cout << endl;

			mnz = a.Mnz(b);
			cout << "Mnz = a * b = ";
			mnz.print();
			cout << endl;

			del = a.Del(b);
			cout << "Del = a / b = ";
			del.print();
			cout << endl;
			break;
		default:
			break;
		}
	} while (choose != 6);

	return 0;
}