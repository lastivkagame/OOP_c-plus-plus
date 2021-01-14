#include "Shape.h"

int main() 
{
	Square s;
	Circle c;
	Triangle *t = new EqualSideTriangle;

	s.Draw();
	c.Draw();
	t->Draw();

	cout << endl;
	Shape *figure = &s;
	figure->Draw();

	LINE;
	
	//Shape * figures[] = { &s,&c,t };
	Shape * figures[] = { new Circle, new Square, new EqualSideTriangle,new Circle };

	for (int i = 0; i < 3; i++) 
	{
		//cout << typeid(12.5).name() << endl;						typeid( // - some field(mina)) - return type
		//cout << "I'm " << typeid(figures[i]).name() << endl;
		figures[i]->Draw();
		delete figures[i];
	}

	LINE;

	system("pause");
	return 0;
}