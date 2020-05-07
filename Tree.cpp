#include "Object.h"
#include "Person.h"
#include "Abiturient.h"
#include "Tree.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;
//����������� � �����������
Tree::Tree(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//����������
Tree::~Tree(void)
{
	if (beg != 0) delete[]beg;
	beg = 0;
}
//���������� �������, �� ������� ��������� p � ������
void Tree::Add()
{
	//����� �� �������� ���� ��������� �������
	cout << "1.Person" << endl;
	cout << "2.Abiturient" << endl;
	int y;
	Object* p;
	cin >> y;
	if (y == 1)//���������� ������� ������ Car
	{
		Person* a = new Person;
		a->Input();//���� �������� ���������
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//���������� � ������
			cur++;
		}
	}
	else
		if (y == 2)//���������� ������� ������ Lorry
		{
			Abiturient* b = new Abiturient;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}
//�������� �������
void Tree::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//����� ������ Show()
		p++;//����������� ��������� �� ��������� ������
	}
}
void Tree::show_age()
{
	if (cur == 0)
		cout << "Empty" << endl;
	else
	{
		double srVr = 0;
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			srVr += static_cast<double>((*p)->show_age());//����� ������ show_age()
			p++;//����������� ��������� �� ��������� ������
		}
		srVr /= cur;

		cout << "������� �������: " << srVr << endl;
	}


}
//��������, ������� ���������� ������ �������
int Tree::operator()()
{
	return cur;
}
//�������� �������� �� �������, ������ �� �������������
void Tree::Del()
{
	if (cur == 0)return;
	cur--;
}
void Tree::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//����� ������
			p++;//����������� ��������� �� ��������� ������
		}
	}

}