/*  ------Завдання-------
Створити шаблон класу Вектор.
Додати до шаблону класу статичне поле, що буде рахувати кількість об’єктів відповідного класу .
Протестувати роботу шаблону класу для типів int(double), string та користувацького типу(Fraction чи ін).
Створити клас Вектор, що представляє собою динамічно розширюваний цілочисловий масив.

Визначити поля:
  T *buffer – вказівник на динамічний масив цілих чисел;
  capacity - розмір масиву(з запасом),
  size – фактичний розмір вектору(фактична кількість елементів вектору)

Визначити наступні методи класу: Конструктори з параметрами(використати делегування конструкторів)
  Vector(size_t size) – резервує пам`ять для масиву, фактичний розмір = size, ємність- Ваша формула, елементи - нулі
  Vector(size_t size, int value) – резервує пам’ять для масиву, фактичний розмір = size, ємність- Ваша формула, елементи = value
  Конструктор за замовчуванням – масив порожній
  Конструктор копії
  Деструктор
  Метод доступу(на читання) до полів capacity та size
  Метод перевірки чи вектор пустий(чи актуальна довжина =0, bool empty())
  Метод встановлення(зміни) елемента за індексом(void setValue(int index, T value)
  Метод доступу(читання) елемента за індексом
  Метод додавання нового елемента(pushBack(T elem)) у кінець масиву( при цьому, якщо потрібно то змінювати capacity)
  Метод вилучення останнього елемента(popBack()), перевіряти чи можна вилучити
  Метод, що повертає посилання на перший елемент вектору T & front(), якщо вектор пустий повертати посилання на деяку статичну локальну змінну методу
T & front()
{
 int static errorFront = 0;
 if (empty())
 return errorFront;
 //....
}

  Метод, що повертає посилання на останній елемент вектору T & back(), якщо вектор пустий повертати посилання на деяку статичну локальну змінну методу
  Метод вставки нового елемента за вказаним індексом(валідувати індекс)
  Метод вилучення елемента за індексом(валідувати індекс)
  Метод очистки вектору(clear()), capacity не змінювати
  Метод зміни capacity(reserve(size_t newCapacity), дані не втрачаються при збільшення capacity, не дозволяти зменшувати capacity
  Метод зміни фактичної довжини масиву void resize(size_t newSize, int value = 0), ємність масиву якщо потрібно - збільшується
  Метод виводу масиву*/

#include <iostream>
#include <string>
#include "Vector.h"
#include "Fractions.h"

using namespace std;

int main()
{
	//Протестувати роботу шаблону класу для типів int(double), string та користувацького типу(Fraction чи ін).
	Vector <int> i(2, 4);
	Vector <double> dbl(5, 5.5);
	Vector <string> str(3, "w");
	Vector <double> d = dbl;
	Vector <Fractins> frac(5, 10);

	cout << "This Vector type int: ";
	i.Print();

	cout << "\nThis Vector type double: ";
	dbl.Print();

	cout << "\nThis Vector type copy double: ";
	d.Print();

	cout << "\nThis Vector type string: ";
	str.Print();

	cout << "\nThis Vector type Fractions: ";
	//cout << frac << endl;                              
//	frac.Print();                                      

	cout << endl << endl;
	system("pause");
	system("cls");

	//Метод доступу(на читання) до полів capacity та size
	cout << "\nSize i = " << i.GetSize() << "\tCapacity i = " << i.GetCapacity() << endl << endl;

	// Метод перевірки чи вектор пустий
	cout << " d is empty? - " << boolalpha << d.Empty() << endl;

	//Метод встановлення(зміни) елемента за індексом(void setValue(int index, T value) 
	cout << endl;
	dbl.Print();
	cout << endl;
	cout << " dbl.SetValue(3, 3.3): \n";
	dbl.SetValue(3, 3.3);
	dbl.Print();
	cout << endl;
	cout << endl;

	//Метод доступу(читання) елемента за індексом
	//cout << "str.GetValue(1): " << str.GetValue(1) << endl;

	////Метод додавання нового елемента(pushBack(T elem)) у кінець масиву
	cout << "i:  " << i << endl;		
	cout << "i: ";
	i.Print();
	cout << " i.PushBack(3). i:  ";
	i.PushBack(3);
	cout << endl;
	i.Print();
	cout << endl;

	////Метод вилучення останнього елемента(popBack())
	//cout << " i.PopBack().i:  ";
	i.PopBack();
	cout << endl;
	i.Print();
	cout << endl;

	//// Метод, що повертає посилання на перший елемент вектору T & front()
	//cout << " dbl adress first el: " << &dbl.GetFront() << endl;

	////Метод, що повертає посилання на останній елемент вектору T & back()
	//cout << " dbl adress last el: " << &dbl.GetBack() << endl;

	//Метод вставки нового елемента за вказаним індексом
	cout << " We set new value s at 2-index in str. Str:  ";
	str.SetNewValue(2, "s");                                            //NOTWORK I DONT UNDENSTAND WHY IT HELP PLS
	str.Print();
	cout << endl;

	//Метод вилучення елемента за індексом
	cout << " We delete value that have 2-index in str. Str:  ";
	str.DeleteValue(2);                                                //NOTWORK I DONT UNDENSTAND WHY IT HELP PLS
	str.Print();
	cout << endl;

	/*//Метод очистки вектору(clear())*/

	i.Clear();
	cout << "i after clear(): " << i << endl;        //якщо це не закомнтувати то нівіть запускати відмовляється

	//Метод зміни capacity(reserve(size_t newCapacity)

	cout << " d.Reserv(7): ";
	d.Reserv(7);
	d.Print();
	cout << endl;

	//Метод зміни фактичної довжини масиву void resize(size_t newSize, int value)
	cout << " d.Resize(6,9): ";
	d.Resize(6, 9);
	d.Print();
	cout << endl;



	
	system("pause");
	system("cls");

	cout << " --- All this only with Fractions ---  \n";

	cout << "\nSize frac = " << frac.GetSize() << "\tCapacity frac = " << frac.GetCapacity() << endl << endl;
	cout << " frac is empty? - " << boolalpha << frac.Empty() << endl;
	cout << endl;
	//frac.Print();
	cout << endl;
	cout << " frac.SetValue(1, 2): \n";
	frac.SetValue(1, 2);
	//frac.Print();
	cout << endl;
	cout << endl;
	cout << "frac.GetValue(1): " << frac.GetValue(1) << endl;
	cout << "frac: ";
	//frac.Print();
	cout << " frac.PushBack(3). i:  ";
	frac.PushBack(3);
	cout << endl;
	//frac.Print();
	cout << endl;
	cout << " frac.PopBack().i:  ";
	frac.PopBack();
	cout << endl;
	//frac.Print();
	cout << endl;
	cout << " frac adress first el: " << &frac.GetFront() << endl;
	cout << " frac adress last el: " << &frac.GetBack() << endl;
	cout << " We set new value s at 1-index in frac. frac:  ";
	frac.SetNewValue(1, 2);                                            //NOTWORK I DONT UNDENSTAND WHY IT HELP PLS
	//frac.Print();
	cout << endl;
	cout << " We delete value that have 1-index in frac. Frac:  ";
	frac.DeleteValue(2);                                                //NOTWORK I DONT UNDENSTAND WHY IT HELP PLS
	//frac.Print();
	cout << endl;
	frac.Clear();
	cout << "frac after clear(): " << i << endl;         //якщо це не закомнтувати то нівіть запускати відмовляється
	cout << " frac.Reserv(7): ";
	frac.Reserv(7);
	//frac.Print();
	cout << endl;
	cout << " frac.Resize(6,9): ";
	frac.Resize(6, 9);
	//frac.Print();
	cout << endl;
	

	system("pause");
	return 0;
}