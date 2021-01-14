#pragma once
#include "Person.h"
#include <vector>

class Programmer: public virtual Person
{
private:
	vector<string> skills;
public:
	Programmer(string name, int age, string sex) :Person(name, age, sex) 
	{
		skills.push_back("c++");
	}
	void addSkill(string skill) 
	{
		skills.push_back(skill);
	}
	
	void showSkills()const 
	{
		cout << GetName() << "'s skills: ";

		for (int i = 0; i < skills.size(); i++) 
		{
			cout << skills[i] << "\t";
		}
		cout << endl;
	}
};

