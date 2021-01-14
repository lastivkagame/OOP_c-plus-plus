/*�������� 2
������� ��������, ��� ����������� ������ �������������� ��� ��������� ����� html - �����.
����������� � ������� ������� �����
����������� ���������(������ ����� ��������� ����������, ����� ����� � ����)
	��������� - ������, �� �������� � ���� ������� ��������� 1 ����(<h1> text< / h1>)
	��������� - ������, �� �������� � ���� ������� ��������� 2 ����(<h2> text< / h2>)
	��������� - ��������, �� �������� � ���� ������� <div style = �background - color: ���� > �. < / div>.
	�������� ���� ������ � ��� ���� ���������(div) �� ������(h1, h2)
���������,
int main()
{
	Element* root = new Composite(�LightSteelBlue�);
	root->Add(new H1(�first�));
	root->Add(new H2(�second�));

	Element* inner = new Composite(�Violet�);
	inner->Add(new H2(�third�));

	Element* inner2 = new Composite(�LightGreen�);
	inner2->Add(new H1(�fourth�));

	root->Add(inner);
	root->Add((Element*)inner2);
	root->Print();
}
// fileComposite.html
<div style = �background - color:Tomato�>
<h1> first< / h1>
<h2> second< / h2>

<div style = �background - color:Violet�>
<h2> third< / h2>
< / div>

<div style = �background - color:LightGreen�>
<h1> fourth< / h1>
< / div>
< / div>*/

#include "Composite.h"

string Element::namefile = "fileComposite.html";
int Element::num = 0;

int main()
{
	Element* root = new Composite("LightSteelBlue");
	root->Add(new H1("first"));
	root->Add(new H2("second"));
	Element* inner = new Composite("Violet");
	inner->Add(new H2("third"));
	inner->Closed();
	Element* inner2 = new Composite("LightGreen");
	inner2->Add(new H1("fourth"));
	root->Add(inner);
	root->Add((Element*)inner2);
	inner2->Closed();
	root->Closed();

	Element* inner3 = new Composite("Yellow");
	inner3->Add(new img("img/apple_.png", "this is apple"));
	inner3->Closed();
	root->Print();

	return 0;
}