#include <iostream>
using namespace std;

class Room {
	float height;
	float width;
	float length;
public:

	Room() : Room(2.8, 3, 2) {}
	Room(float h, float w, float l) :height(h), width(w), length(l) {}

	float Square()const
	{
		return  width * length;
	}

	float GetH()const 
	{
		return height;
	}

	float GetW()const
	{
		return width;
	}

	float GetL()const
	{
		return length;
	}


	Room(const Room&obj) : Room(obj.GetH(), obj.GetW(), obj.GetL())
	{
	
	}
};

class Flat {
	int count;
	Room * rooms;
public:
	Flat() {}
	Flat(int count, Room * r) : count(count), rooms(r) {}

	float TotalSquare()const
	{
		float sum = 0;
		for (int i = 0; i < count; i++)
		{
			sum += rooms[i].Square();
		}
		return sum;
	}
	~Flat() {
		delete[]rooms;
	}

};


int main()
{
	Room r1;
	Room r2(2.8, 5, 5);
	//Room * arr = new Room[2]{ r1,r2 };

	Flat fl(2, new Room[2]{ r1,r2 });
	cout << "Total square: " << fl.TotalSquare() << endl;

	system("pause");
	return 0;
}