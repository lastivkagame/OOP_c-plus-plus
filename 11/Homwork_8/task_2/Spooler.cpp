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

Spooler::Spooler(const Spooler& obj)
{
	this->documents = obj.documents;
	this->CurrentQueueLength = obj.CurrentQueueLength;
	this->MaxQueueLength = obj.MaxQueueLength;
	this->priorateWaiters = obj.priorateWaiters;
}

void Spooler::enqueue(string el, int priv, Document doc)
{
	if (!isFull())
	{
		int temp = 0;

		if (CurrentQueueLength > 0)
		{
			if (el == "clerk")
			{
				for (int i = 0; i < CurrentQueueLength; i++)
				{
					if (priv > priorateWaiters[i] && (wait[i] == "clerk"))
					{
						temp = i;
					}
				}
			}
			else if (el == "accountant")
			{
				for (int i = 0; i < CurrentQueueLength; i++)
				{
					if (priv > priorateWaiters[i] && (el == "accountant"))
					{
						temp = i;
					}
				}
			}
			else
			{
				for (int i = 0; i < CurrentQueueLength; i++)
				{
					if (priv > priorateWaiters[i] && (el == "director"))
					{
						temp = i;
					}
				}
			}
		}

		int temp2;
		string temp3;
		Document temp4;

		CurrentQueueLength++;

		if (CurrentQueueLength != 1)
		{
			for (int i = temp; i < CurrentQueueLength; i++)
			{
				temp2 = priorateWaiters[i];
				priorateWaiters[i + 1] = temp2;

				temp3 = wait[i];
				wait[i + 1] = temp3;

				temp4 = documents[i];
				documents[i + 1] = temp4;
			}
		}

		priorateWaiters[temp] = priv;
		wait[temp] = el;
		documents[temp] = doc;
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
		int temp = 0;
		for (int i = 0; i < CurrentQueueLength; i++)
		{
			if (wait[i] != el)
			{
				break;
			}

			if (priv > priorateWaiters[i])
			{
				temp = i;
			}
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
		for (int i = 0; i < CurrentQueueLength; i++)
		{
			cout << wait[i] << " ";
		}

		cout << "Priorate: ";
		for (int i = 0; i < CurrentQueueLength; i++)
		{
			cout << priorateWaiters[i] << "\t";
		}
	}
	else
	{
		cout << "It's empty!\n";
	}
}

void Spooler::clear()
{
	CurrentQueueLength = 0;
}