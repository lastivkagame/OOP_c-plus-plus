#include "Fortress.h"

Fortress::Fortress(string name, int digits) :Catapult(name, digits), Shooter(name, digits), ArcherTower(name, digits), Archer(name, digits), Range(name, digits) {}

void Fortress::Wound(int number, string who)
{
	if (who == "wall") 
	{
		if (number >= wall) 
		{
			wall = 0;
			cout << "\n Wall is fall!!!\n";
		}
		else 
		{
			wall -= number;
		}
	}
	else if (who == "gate") 
	{
		if (number >= gate)
		{
			gate = 0;
			cout << " Gate is fall!!!\n";
		}
		else
		{
			gate -= number;
		}
	}
	else if (who == "ditch")
	{
		if (number >= ditch)
		{
			ditch = 0;
			cout << " Ditch is fall!!!\n";
		}
		else
		{
			ditch -= number;
		}
	}
	else if (who == "archer" || who == "range")
	{
		if (number >= ArcherTower::GetLive())
		{
			ArcherTower::Wound(Archer::GetLive(), "archer");
			ArcherTower::Wound(Range::GetLive(), "range");
			cout << " ArcherTower is fall!!!\n";
		}
		else
		{
			ArcherTower::Wound(number, who);
		}
	}
	else if (who == "catapult")
	{
		if (number >= Catapult::GetLive())
		{
			Catapult::Wound(Catapult::GetLive());
			cout << " Catapult is fall!!!\n";
		}
		else
		{
			Catapult::Wound(number);
		}
	}
}

void Fortress::ConsistentWound(int number)
{
	if (ditch > 0) 
	{
		ditch = -number;

		if (ditch < 0) 
		{
			ditch = 0;
		}
	}
	else if (wall > 0) 
	{
		wall -= number;

		if (wall < 0)
		{
			wall = 0;
		}
	}
	else if (gate > 0)
	{
		gate -= number;

		if (gate < 0)
		{
			gate = 0;
		}
	}
	else if (Catapult::GetLive() > 0)
	{
		Catapult::Wound(number);
	}
	else 
	{
		ArcherTower::Wound(number, "range");
		ArcherTower::Wound(number, "archer");
	}
}

void Fortress::QuotCatapult()
{
	if (Shooter::GetDigits() > 0)
	{
	Catapult::quot();
	}
	else
	{
		cout << "We have nothing to shoot!\n";
	}
}

void Fortress::Archertower(string who)
{
	if (Shooter::GetDigits() > 0)
	{
		if (who == "archer")
		{
			Archer::quot();
		}
		else
		{
			Range::quot();
		}
	}
	else
	{
		cout << "We have nothing to shoot!\n";
	}
}

bool Fortress::IsFortrees()
{
	int temp;
	temp = wall + gate + ditch + ArcherTower::GetLive() + Catapult::GetLive();

	if (temp > 0) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Fortress::Print() const
{
	cout << "\n --- Statistic about your Fortress --- \n";
	cout << " ~ Archer Tower: \n";
	cout << "      # Archer: " << Archer::GetLive() << " % " << endl;
	cout << "      # Range: " << Range::GetLive() << " % " << endl;
	cout << " ~ Catapult: " << Catapult::GetLive() << " % " << endl;
	cout << " ~ Wall: " << wall << " % " << endl;
	cout << " ~ Gate: " << gate << " % " << endl;
	cout << " ~ Ditch: " << ditch << " % " << endl;
	cout << "-----------------------------------------\n\n";
};
