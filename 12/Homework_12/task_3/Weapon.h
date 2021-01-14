#pragma once
#include "Barrack.h"
#include <iostream>
using namespace std;

class Weapon
{
public:
	virtual int Shot() = 0;
	virtual Weapon* Clone() = 0;
	virtual ~Weapon() {};
};

class Knifes : public Weapon
{
public:
	int Shot()
	{
		cout << "  -Knife- \n";
		return 5;
	}

	Weapon* Clone()
	{
		return new Knifes(*this);
	}
};

class Grenades : public Weapon
{
public:
	int Shot()
	{
		cout << "  -Grenades- \n";
		return 10;
	}

	Weapon* Clone()
	{
		return new Grenades(*this);
	}
};

class Electroshock : public Weapon
{
public:
	int Shot()
	{
		cout << "  -Electroshock- \n";
		return 7;
	}

	Weapon* Clone()
	{
		return new Electroshock(*this);
	}
};

const int NUM_PROTOTYPES = 3;

enum WEAPONTYPE
{
	KNIFES = 1, GRENADES, ELECTROSHOCK
};

class FactoryWeapons
{
public:
	static Weapon* prototypes[NUM_PROTOTYPES];
	static Weapon* CreateWeapon(WEAPONTYPE weapontype)
	{
		switch (weapontype)
		{
		case WEAPONTYPE::KNIFES:
		case WEAPONTYPE::GRENADES:
		case WEAPONTYPE::ELECTROSHOCK:
			return	prototypes[weapontype - 1]->Clone();
			break;
		default:
			return prototypes[1]->Clone();
			break;
		}
	}
};