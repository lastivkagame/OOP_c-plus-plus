#include "Spooler.h"

//к-тори
Spooler::Spooler()
{
	CurrentQueueLength = 0;
	MaxQueueLength = 1;

	wait = new string[1];
	priorateWaiters = new int[1];
	documents = new Document[1];
}

Spooler::Spooler(const Spooler& obj)
{
	this->MaxQueueLength = obj.MaxQueueLength;
	this->CurrentQueueLength = obj.CurrentQueueLength;

	this->wait = new string[this->MaxQueueLength];
	this->documents = new Document[this->MaxQueueLength];
	this->priorateWaiters = new int[this->MaxQueueLength];

	for (int i = 0; i < CurrentQueueLength; i++)
	{
		this->wait[i] = obj.wait[i];
		this->documents[i] = obj.documents[i];
		this->priorateWaiters[i] = obj.priorateWaiters[i];
	}
}

Spooler& Spooler::operator=(const Spooler& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	
	this->MaxQueueLength = obj.MaxQueueLength;
	this->CurrentQueueLength = obj.CurrentQueueLength;

	this->wait = new string[this->MaxQueueLength];
	this->documents = new Document[this->MaxQueueLength];
	this->priorateWaiters = new int[this->MaxQueueLength];

	for (int i = 0; i < CurrentQueueLength; i++)
	{
		this->wait[i] = obj.wait[i];
		this->documents[i] = obj.documents[i];
		this->priorateWaiters[i] = obj.priorateWaiters[i];
	}

	return *this;
}

Spooler& Spooler::operator=(Spooler&& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	delete[]wait;
	delete[]documents;
	delete[]priorateWaiters;
	
	this->MaxQueueLength = obj.MaxQueueLength;
	this->CurrentQueueLength = obj.CurrentQueueLength;

	this->wait = new string[this->MaxQueueLength];
	this->documents = new Document[this->MaxQueueLength];
	this->priorateWaiters = new int[this->MaxQueueLength];

	for (int i = 0; i < CurrentQueueLength; i++)
	{
		this->wait[i] = obj.wait[i];
		this->documents[i] = obj.documents[i];
		this->priorateWaiters[i] = obj.priorateWaiters[i];
	}

	obj.wait = nullptr;
	obj.documents = nullptr;
	obj.priorateWaiters = nullptr;

	return *this;
}

Spooler::Spooler(Spooler&& obj)
{
	*this = move(obj);
}

Spooler::Spooler(int maxQueue)
{
	CurrentQueueLength = 0;
	MaxQueueLength = maxQueue;

	wait = new string[maxQueue];
	priorateWaiters = new int[maxQueue];
	documents = new Document[maxQueue];
}

Spooler::~Spooler()
{
	if (wait != nullptr)
	{
		delete[]wait;
		wait = nullptr;
	}

	if (priorateWaiters != nullptr)
	{
		delete[]priorateWaiters;
		priorateWaiters = nullptr;
	}

	if (documents != nullptr)
	{
		delete[]documents;
		documents = nullptr;
	}
}

void Spooler::enqueue(string el, int priv, Document doc)
{
	if (!isFull())
	{
		/*int temp = 0;
		int p = 0;

		if (CurrentQueueLength > 0)
		{
			if (el == "clerk")
			{
				for (int i = 0; i < CurrentQueueLength; i++)
				{
					if (wait[i] == "clerk")
					{
						if (p == 0)
						{
							p++;
							temp = i;
						}

						if (priv > priorateWaiters[i])
						{
							temp = i;
						}
					}
				}
			}
			else if (el == "accountant")
			{
				for (int i = 0; i < CurrentQueueLength; i++)
				{
					if (wait[i] == "accountant")
					{
						if (p == 0)
						{
							p++;
							temp = i;
						}

						if (priv > priorateWaiters[i])
						{
							temp = i;
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < CurrentQueueLength; i++)
				{
					if (wait[i] == "director")
					{
						if (p == 0)
						{
							p++;
							temp = i;
						}

						if (priv > priorateWaiters[i])
						{
							temp = i;
						}
					}
				}
			}
		}

		int* pw = new int[CurrentQueueLength];
		string* w = new string[CurrentQueueLength];
		Document* d = new Document[CurrentQueueLength];
		int k = temp;

		CurrentQueueLength++;

		if (CurrentQueueLength != 1)
		{
			for (int i = temp; i < CurrentQueueLength; i++)
			{
				pw[i] = priorateWaiters[i];
				w[i] = wait[i];
				d[i] = documents[i];
			}

			for (int i = temp + 1; i < CurrentQueueLength; i++)
			{
				priorateWaiters[i] = pw[k];
				wait[i] = w[k];
				documents[i] = d[k];
			}
		}

		priorateWaiters[temp] = priv;
		wait[temp] = el;
		documents[temp] = doc;*/

		bool flag = false;
		int temp = 0;

		int* pw = new int[CurrentQueueLength];
		string* w = new string[CurrentQueueLength];
		Document* d = new Document[CurrentQueueLength];

		for (int i = 0; i < CurrentQueueLength; i++)
		{
			if (wait[i] == el)
			{
				flag = true;
				break;
			}
		}

		for (int i = 0; i < CurrentQueueLength; i++)
		{
			w[i] = wait[i];
			pw[i] = priorateWaiters[i];
			d[i] = documents[i];
		}

		bool flag2 = true;
		int k = 0;

		if (flag == true)
		{
			if (el == "director")
			{
				for (int i = 0; i < CurrentQueueLength; i++)
				{
					if ((wait[i] == "director") && (priorateWaiters[i] < priv))
					{
						temp = i;
						flag2 = false;
						break;
					}

					if ((flag2 == true) && (wait[i + 1] != "director"))
					{
						temp = i;
						break;
					}
				}
			}
			else if (el == "accoundant") 
			{
				for (int i = 0; i < CurrentQueueLength; i++)
				{
					if ((wait[i] == "accoundant") && (priorateWaiters[i] < priv))
					{
						temp = i;
						flag2 = false;
						break;
					}

					if ((flag2 == true) && (wait[i + 1] != "accoundant"))
					{
						temp = i;
						break;
					}
				}
			}
			else 
			{
				for (int i = 0; i < CurrentQueueLength; i++)
				{
					if ((wait[i] == "clerk") && (priorateWaiters[i] < priv))
					{
						temp = i;
						flag2 = false;
						break;
					}

					if ((flag2 == true) && (wait[i + 1] != "clerk"))
					{
						temp = i;
						break;
					}
				}
			}

			for (int i = 0; i < CurrentQueueLength + 1; i++)
			{
				if (i == temp)
				{
					priorateWaiters[i] = priv;
					wait[i] = el;
					documents[i] = doc;
				}
				else
				{
					priorateWaiters[i] = pw[k];
					wait[i] = w[k];
					documents[i] = d[k++];
				}
			}
		}
		else
		{
			if (el == "director") 
			{
				priorateWaiters[0] = priv;
				wait[0] = el;
				documents[0] = doc;

				for (int i = 1; i < CurrentQueueLength + 1; i++)
				{
					priorateWaiters[i] = pw[k];
					wait[i] = w[k];
					documents[i] = d[k++];
				}
			}
			else if(el == "accoundant")
			{
				flag2 = true;

				for (int i = 0; i < CurrentQueueLength + 1; i++)
				{
					if (wait[i] == "clerk" && flag2 == true) 
					{
						priorateWaiters[i] = priv;
						wait[i] = el;
						documents[i] = doc;
						flag2 = false;
					}
					else
					{
						priorateWaiters[i] = pw[k];
						wait[i] = w[k];
						documents[i] = d[k++];
					}
				}
			}
			else 
			{
				priorateWaiters[CurrentQueueLength] = priv;
				wait[CurrentQueueLength] = el;
				documents[CurrentQueueLength] = doc;

				for (int i = 0; i < CurrentQueueLength; i++)
				{
					priorateWaiters[i] = pw[k];
					wait[i] = w[k];
					documents[i] = d[k++];
				}
			}
		}

		CurrentQueueLength++;
	}
	else
	{
		cout << " Queue is full! \n\n";
	}
}

void Spooler::dequeue(string el, int priv, Document doc)
{
	if (!isEmpty())
	{
		int start, end, temp = -1;
		bool flag2 = true;

		for (int i = 0; i < CurrentQueueLength; i++)
		{
			if (wait[i] == el)
			{
				start = i;
				break;
			}
		}

		for (int i = start; i < CurrentQueueLength; i++)
		{
			if (wait[i] != el)
			{
				end = i;
				break;
			}
		}

		for (int i = start; i < end; i++)
		{
			if (priorateWaiters[i] < priv)
			{
				temp = i;
				break;
			}
		}

		if (temp == -1) 
		{
			temp = end;
		}

		int* temp2 = new int[(--CurrentQueueLength)];
		string* temp3 = new string[(--CurrentQueueLength)];
		Document* temp4 = new Document[(--CurrentQueueLength)];

		CurrentQueueLength--;

		for (int i = 0; i < CurrentQueueLength; i++)
		{
			temp2[i] = priorateWaiters[i + 1];
			temp3[i] = wait[i + 1];
			temp4[i] = documents[i + 1];
		}

		for (int i = 0; i < (--CurrentQueueLength); i++)
		{
			if (i < temp)
			{
				documents[i] = temp4[i];
				wait[i] = temp3[i];
				priorateWaiters[i] = temp2[i];
			}
			else
			{
				priorateWaiters[i] = temp2[i + 1];
				wait[i] = temp3[i + 1];
				documents[i] = temp4[i + 1];
			}
		}
	}
}

void Spooler::Del()
{
	CurrentQueueLength--;

	int* temp2 = new int[CurrentQueueLength];
	string* temp3 = new string[CurrentQueueLength];
	Document* temp4 = new Document[CurrentQueueLength];

	for (int i = 0; i < CurrentQueueLength; i++)
	{
		temp2[i] = priorateWaiters[i + 1];
		temp3[i] = wait[i + 1];
		temp4[i] = documents[i + 1];
	}

	for (int i = 0; i < CurrentQueueLength; i++)
	{
		priorateWaiters[i] = temp2[i];
		wait[i] = temp3[i];
		documents[i] = temp4[i];
	}
}

bool Spooler::isEmpty() const
{
	return CurrentQueueLength == 0;
}

bool Spooler::isFull() const
{
	return CurrentQueueLength == MaxQueueLength;
}

int Spooler::getCount() const
{
	return CurrentQueueLength;
}

Document* Spooler::getDocuments() const
{
	return this->documents;
}

Document Spooler::getDocument(int el) const
{
	return this->documents[el];
}

void Spooler::show() const
{
	if (!isEmpty()) {

		cout << "Wait: ";
		for (int i = 0; i < CurrentQueueLength; i++)
		{
			cout << wait[i] << "  ";
		}
		cout << endl;

		cout << "Priorate: ";
		for (int i = 0; i < CurrentQueueLength; i++)
		{
			cout << priorateWaiters[i] << "\t";
		}
		cout << endl;
	}
	else
	{
		cout << "It's empty!\n";
	}
}

void Spooler::showEl(int index) const
{
	cout << "who: " << wait[index] << endl;
	cout << "priorate: " << priorateWaiters[index] << endl;
}

void Spooler::clear()
{
	CurrentQueueLength = 0;
}