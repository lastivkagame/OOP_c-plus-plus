#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Auto {
private:
	double potokSpeed;
	double maxSpeed;
	string marka;
	string numberAuto;
public:
	Auto(double potokSpeed = 0, double maxSpeed = 0, string marka = "empty", string numberAuto = "empty"):marka(marka) //:potokSpeed(potokSpeed),
		//maxSpeed(maxSpeed), marka(marka), numberAuto(numberAuto)
	{
		try
		{
			Auto::WrongSpeed:: Test(potokSpeed, maxSpeed);
			this->potokSpeed = potokSpeed;
			this->maxSpeed = maxSpeed;
		}
		catch(WrongSpeed w)
		{
			w.Why();
			cout << endl;
			this->potokSpeed = 0;
			this->maxSpeed = 0;
		};

		try
		{
			Auto::InvalidNumber::Test(numberAuto);
			this->numberAuto = numberAuto;
		}
		catch (InvalidNumber w)
		{
			w.Why();
			cout << endl;
			this->numberAuto = numberAuto;
		};
	};

	double GetpotokSpeed()const
	{
		return potokSpeed;
	}

	double GetmaxSpeed()const
	{
		return this->maxSpeed;
	}

	string Getmarka()const
	{
		return this->marka;
	}

	string GetnumberAuto()const
	{
		return this->numberAuto;
	}


	class WrongSpeed
	{
	public:
		static void Test(double potokSpeed, double maxSpeed)
		{
			if ((potokSpeed > maxSpeed) || (0 > maxSpeed) || (0 > potokSpeed))
			{
				//throw "WrongSpeed: Test() - potokSpeed > maxSpeed";
				throw WrongSpeed();
			}
		}

		void Why()const
		{
			cout << "WrongSpeed: Test() - potokSpeed > maxSpeed";
		}
	};

	class InvalidNumber
	{
	public:
		void Why()const 
		{
			cout << "InvalidNumber";
		}

		static void Test(string &number)
		{
			bool flag = true;

			for (int i = 0; i < 2; i++)
			{
				//if (typeid(number[i]).name() != typeid(int).name()){}
				if ((isdigit(number[i])))
				{
					//throw "InvalidNumber";
					throw InvalidNumber();
					flag = false;
				}

				if (flag == false)
				{
					break;
				}
			}

			if (flag)
			{
				for (int i = 2; i < 6; i++)
				{
					//if (typeid(number[i]).name() == typeid(int).name()) {}
					if (!isdigit(number[i])) 
					{
						//throw "InvalidNumber";
						throw InvalidNumber();
						flag = false;
					}

					if (flag == false)
					{
						break;
					}
				}
			}

			if (flag)
			{
				for (int i = 6; i < 8; i++)
				{
					//if (typeid(number[i]).name() == typeid(int).name())
					if (isdigit(number[i]))
					{
						//throw "InvalidNumber";
						throw InvalidNumber();
						flag = false;
					}

					if (flag == false)
					{
						break;
					}
				}
			}

			for (int i = 2; i < 6; i++)
			{
				number[i] = toupper(number[i]);
			}
		}
	};
};