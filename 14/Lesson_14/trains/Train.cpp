#include "Train.h"

Train::Train(int number, string time, string station) :number(number), time(time), station(station) {}

int Train::GetNumber() const
{
	return this->number;
}

string Train::GetTime() const
{
	return this->time;
}

string Train::GetStation() const
{
	return this->station;
}

void Train::SetNumber(int number)
{
	this->
}

Train::~Train(){};

ostream & operator<<(ostream & out, const Train & st)
{
	out << "Number: " << st.number << endl;
	out << "Time: " << st.time << endl;
	out << "Station: " << st.station << endl;

	return out;

}