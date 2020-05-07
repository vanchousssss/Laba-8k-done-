#include "Object.h"
#include "Person.h"
#include "Abiturient.h"
#include "Tree.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;
//конструктор с параметрами
Tree::Tree(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//деструктор
Tree::~Tree(void)
{
	if (beg != 0) delete[]beg;
	beg = 0;
}
//добавление объекта, на который указатель p в вектор
void Tree::Add()
{
	//выбор из объектов двух возможных классов
	cout << "1.Person" << endl;
	cout << "2.Abiturient" << endl;
	int y;
	Object* p;
	cin >> y;
	if (y == 1)//добавление объекта класса Car
	{
		Person* a = new Person;
		a->Input();//ввод значений атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2)//добавление объекта класса Lorry
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
//просмотр вектора
void Tree::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show()
		p++;//передвигаем указатель на следующий объект
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
			srVr += static_cast<double>((*p)->show_age());//вызов метода show_age()
			p++;//передвигаем указатель на следующий объект
		}
		srVr /= cur;

		cout << "Средний возраст: " << srVr << endl;
	}


}
//операция, которая возвращает размер вектора
int Tree::operator()()
{
	return cur;
}
//удаление элемента из вектора, память не освобождается
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
			(*p)->HandleEvent(e);//вызов метода
			p++;//передвигаем указатель на следующий объект
		}
	}

}