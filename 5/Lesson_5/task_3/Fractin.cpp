#include "Fractin.h"

//������������
Fractins::Fractins() :Fractins(0, 1) { this->Abrev(); }
Fractins::Fractins(int numerator) : Fractins(numerator, 1) { this->Abrev(); }
Fractins::Fractins(int numerator, int denominator) : numerator(numerator)
{
	if (denominator == 0)
	{
		cout << "You entered the denominator incorrectly!\n";
		this->denominator = 1;
	}
	else
	{
		if (denominator > 0)
		{
			this->denominator = denominator;
		}
		else
		{
			this->denominator = denominator;
			this->numerator = denominator;
		}
	}
	this->Abrev();
}

//�������
void Fractins::SetNumerator(int numerator)
{
	this->numerator = numerator;
	this->Abrev();
}

void Fractins::SetDenominator(int denominator)
{
	if (denominator == 0)
	{
		cout << "You entered the denominator incorrectly!\n";
		this->denominator = 1;
	}
	else
	{
		if (denominator > 0)
		{
			this->denominator = denominator;
		}
		else
		{
			this->denominator = denominator;
			this->numerator = denominator;
		}
	}

	this->Abrev();
}

//�������
int Fractins::GetNumerator()const
{
	return numerator;
}

int Fractins::GetDenominator()const
{
	return denominator;
}

//����������� ����
Fractins::Fractins(const Fractins& obj)
{
	this->SetNumerator(obj.GetNumerator());
	this->SetDenominator(obj.GetDenominator());
}

void Fractins::print() const
{
	cout << numerator << " / " << denominator << endl;
}

Fractins Fractins::Abrev()
{
	if ((numerator < 0) || (numerator < 0 && denominator < 0))
	{
		numerator = (numerator);
		denominator = (denominator);
	}

	int min;
	if (numerator < denominator)
	{
		min = numerator;
	}
	else
	{
		min = denominator;
	}

	bool flag = true;

	while (flag)
	{
		flag = false;

		for (int i = 2; i <= min; i++)
		{
			if (numerator % i == 0 && denominator % i == 0)
			{
				numerator /= i;
				denominator /= i;
				flag = true;
			}
		}
	}

	return *this;
}

Fractins Fractins::operator+(const Fractins& obj)
{
	Fractins res;
	if (this->denominator == obj.GetDenominator())
	{
		res.SetNumerator((this->numerator + obj.GetNumerator()));
	}
	else
	{
		for (int i = 0;; i++)
		{
			if ((i % this->denominator == 0 && i % obj.GetDenominator() == 0))
			{
				res.SetNumerator((this->numerator * (i / denominator)) + (obj.GetDenominator() * (i / obj.GetDenominator())));
				res.SetDenominator(i);

				break;
			}
		}
	}

	res.Abrev();

	return res;
}

Fractins Fractins::operator-(const Fractins& obj)
{
	Fractins res;
	if (this->denominator == obj.GetDenominator())
	{
		res.SetNumerator((this->numerator - obj.GetNumerator()));
	}
	else
	{
		for (int i = 0;; i++)
		{
			if ((i % this->denominator == 0 && i % obj.GetDenominator() == 0))
			{
				res.SetNumerator((this->numerator * (i / denominator)) - (obj.GetDenominator() * (i / obj.GetDenominator())));
				res.SetDenominator(i);

				break;
			}
		}
	}

	res.Abrev();

	return res;
}

Fractins Fractins::operator*(const Fractins& obj)
{
	Fractins res;

	res.SetDenominator((this->denominator * obj.GetDenominator()));
	res.SetNumerator((this->numerator * obj.GetNumerator()));

	res.Abrev();

	return res;
}

Fractins Fractins::operator/(const Fractins& obj)
{
	Fractins res;

	res.SetDenominator((this->denominator * obj.GetNumerator()));
	res.SetNumerator((this->numerator * obj.GetDenominator()));

	res.Abrev();

	return res;
}

char Fractins::comparison(Fractins& obj)
{
	Fractins a, b;
	obj.Abrev();
	if (this->denominator == obj.GetDenominator())
	{
		if (this->numerator > obj.GetNumerator())
		{
			return '>';
		}
		else  if (this->numerator > obj.GetNumerator())
		{
			return '<';
		}
		else
		{
			return '=';
		}
	}
	else if (this->numerator == obj.GetNumerator())
	{
		if (this->denominator > obj.GetDenominator())
		{
			return '>';
		}
		else  if (this->denominator < obj.GetDenominator())
		{
			return '<';
		}
		else
		{
			return '=';
		}
	}
	else
	{
		for (int i = 0;; i++)
		{
			if ((i % this->denominator == 0 && i % obj.GetDenominator() == 0))
			{
				a.SetNumerator((this->numerator * (i / denominator)));
				a.SetDenominator(i);
				a.Abrev();

				b.SetDenominator((obj.GetDenominator() * (i / obj.GetDenominator())));
				b.SetDenominator(i);
				b.Abrev();

				if (a.GetNumerator() > b.GetNumerator())
				{
					return '>';
				}
				else  if (a.GetNumerator() < b.GetNumerator())
				{
					return '<';
				}
				else
				{
					return '=';
				}

				break;
			}
		}
	}
}

int Fractins::intNumber()
{
	int num;
	num = numerator / denominator;
	return num;
}

double Fractins::doubleNumber()
{
	double num;
	num = numerator / denominator;
	return num;
}
