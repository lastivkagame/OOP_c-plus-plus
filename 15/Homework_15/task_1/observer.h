#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Product;

class Client abstract
{
public:
	Client() {};
	virtual void Buy(Product* p) = 0;
	virtual void Sell(Product* p) = 0;
	virtual ~Client() {};
};

class Product
{
private:
	string name;
	double price;
	vector<Client*>buyers;
public:
	Product() {};
	Product(string name, double price) :name(name), price(price) {};

	void Attach(Client* b)
	{
		buyers.push_back(b);
	}

	void Detach(Client* b)
	{
		auto it = find(buyers.begin(), buyers.end(), b);
		if (it != buyers.end())
		{
			buyers.erase(it);
		}
	}

	void setPrice(double newPrice)
	{
		double oldPrice = price;
		price = newPrice;
		if (newPrice < oldPrice)
		{
			NotifyBuy();
		}
		else
		{
			NotifySell();
		}
	}

	void NotifyBuy()
	{
		for (int i = 0; i < buyers.size(); i++)
		{
			buyers[i]->Buy(this);
		}
	}

	void NotifySell()
	{
		for (int i = 0; i < buyers.size(); i++)
		{
			buyers[i]->Sell(this);
		}
	}

	string GetName()const
	{
		return this->name;
	}

	double GetPrice()const
	{
		return this->price;
	}

	~Product()
	{
		buyers.clear();
	}
};

class Bank : public Client  //Спостерігачі – клієнти
{
private:
	string name;
	double sumDollar;
	double sumEuro;
	Product* prod;
public:
	Bank(string name = "", double sumDollar = 0, double sumEuro = 0) : Client()
	{
		this->name = name;
		this->sumDollar = sumDollar;
		this->sumEuro = sumEuro;
	};

	string GetName()const
	{
		return this->name;
	}

	Product* GetProduct()const
	{
		return this->prod;
	}

	double GetsumDollar()const
	{
		return this->sumDollar;
	}

	double GetsumEuro()const
	{
		return this->sumEuro;
	}

	void setProduct(Product* prod)
	{
		this->prod = prod;
	}

	void Buy(Product* p)
	{
		cout << " Dear " << name << "!\n";
		cout << "You buy " << p->GetName() << " by new price " << p->GetPrice() << endl;

		if (p->GetName() == "Dollar")
		{
			cout << " You have before: " << sumDollar << " USD \n";
			sumDollar += p->GetPrice() * (rand() % 100);
			cout << " You have after: " << sumDollar << " USD \n\n";
		}

		if (p->GetName() == "Euro")
		{
			cout << " You have before: " << sumEuro << " EUR \n";
			sumEuro += p->GetPrice() * (rand() % 100);
			cout << " You have after: " << sumEuro << " EUR \n\n";
		}
	}

	void Sell(Product* p)
	{
		cout << " Dear " << name << "!\n";
		cout << "You sell " << p->GetName() << " by new price " << p->GetPrice() << endl;

		if (p->GetName() == "Dollar")
		{
			cout << " You have before: " << sumDollar << " USD \n";
			if (sumDollar <= 0)
			{
				cout << " You dont have dollars\n";
			}
			else
			{
				if (sumDollar >= 100)
				{
					cout << " You have more than 100 you can sell \n";
					sumDollar -= p->GetPrice() * (rand() % 100);
				}
				else
				{
					cout << " You have low than 100 you cant sell\n";
				}
			}
			cout << " You have after: " << sumDollar << " USD \n\n";
		}

		if (p->GetName() == "Euro")
		{
			cout << " You have before: " << sumEuro << " EUR \n";
			if (sumEuro <= 0)
			{
				cout << " You dont have euro\n";
			}
			else
			{
				if (sumEuro >= 100)
				{
					cout << " You have more than 100 you can sell \n";
					sumEuro -= p->GetPrice() * (rand() % 100);
				}
				else
				{
					cout << " You have low than 100 you cant sell\n";
				}
			}
			cout << " You have after: " << sumEuro << " EUR \n\n";
		}
	}

	~Bank()
	{
		if (prod)
		{
			delete prod;
		}
	}
};

class Broker : public Client  //Спостерігачі – клієнти
{
private:
	string name;
	double sumDollar;
	Product* prod;
public:
	Broker(string name, double sumDollar) : Client()
	{
		this->name = name;
		this->sumDollar = sumDollar;
	};

	string GetName()const
	{
		return this->name;
	}

	Product* GetProduct()const
	{
		return this->prod;
	}

	double GetsumDollar()const
	{
		return this->sumDollar;
	}

	void setProduct(Product* prod)
	{
		this->prod = prod;
	}

	void Buy(Product* p)
	{
		cout << " Dear " << name << "!\n";
		cout << "You buy " << p->GetName() << " by new price " << p->GetPrice() << endl;

		if (p->GetName() == "Dollar")
		{
			cout << " You have before: " << sumDollar << " USD \n";
			sumDollar += p->GetPrice() * (rand() % 100);
			cout << " You have after: " << sumDollar << " USD \n\n";
		}
		else
		{
			cout << " You can't buy euro\n";
			cout << " But you subscribed on this product " << p->GetName() << endl << endl;
		}
	}

	void Sell(Product* p)
	{
		cout << " Dear " << name << "!\n";
		cout << "You sell " << p->GetName() << " by new price " << p->GetPrice() << endl;

		if (p->GetName() == "Dollar")
		{
			cout << " You have before: " << sumDollar << " USD \n";
			if (sumDollar <= 0)
			{
				cout << " You dont have dollars\n\n";
			}
			else
			{
				if (sumDollar >= 100)
				{
					cout << " You have more than 100 you can sell \n";
					sumDollar -= p->GetPrice() * (rand() % 100);
				}
				else
				{
					cout << " You have low than 100 you cant sell\n";
				}
			}
			cout << " You have after: " << sumDollar << " USD \n\n";
		}
		else
		{
			cout << " You can't sell euro becouse you not have it\n";
			cout << " But you subscribed on this product " << p->GetName() << endl << endl;
		}
	}

	~Broker()
	{
		if (prod)
		{
			delete prod;
		}
	}
};

class CourseDollar : public Product  //Предмет спостереження
{
public:
	CourseDollar(double price) :Product("Dollar", price) {};
};

class CourseEuro : public Product  //Предмет спостереження
{
public:
	CourseEuro(double price) :Product("Euro", price) {};
};