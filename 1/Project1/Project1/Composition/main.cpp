#include <iostream>
using namespace std;

class Room {
	float height;
	float width;
	float length;

public: 
	Room() : Room(2.8, 3, 2)
	{}
	Room(float h, float w, float l) : height(h), width(w),
								length(l)
	{}
	Room(const Room & obj): Room(obj.GetH(), obj.GetW(), obj.GetL())
	{
	}
	float GetH()const {
		return height;
	}
	float GetW()const {
		return width;
	}
	float GetL()const {
		return length;
	}
	float Square() const
	{
		return width * length;
	}
};

class Flat {
	int count;
	Room * rooms;
public:
	Flat() {}
	Flat(int count, Room * r) : count(count), rooms(r)
	{}

	float TotalSquare() const
	{
		float suma = 0;
		for (int i = 0; i < count; i++)
		{
			suma += rooms[i].Square();
		}
		return suma;
	}
	~Flat()
	{
		delete[]rooms;
	}
};

void main()
{
	Room r1;
	Room r2(2.8, 5, 5);
//	Room* arr = new Room[2]{ r1,r2 };

	Flat f(2, new Room[2]{ r1,r2 });
	cout << "Total square: " << f.TotalSquare() << endl;

	system("pause");
}