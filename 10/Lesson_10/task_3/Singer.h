#pragma once
#include "Person.h"

class Singer: public virtual Person
{
	string voice;
public:
	Singer(string name = "naname", int age = 18, string sex = "non", string voice = "bass") :Person(name, age, sex) 
	{
		this->voice = voice;
	}
	Singer(Person&p, string voice) :Person(p), voice(voice) {};

	void show()const 
	{

		Person::Print();
		cout << "Voice: " << voice << endl;
	}
};


