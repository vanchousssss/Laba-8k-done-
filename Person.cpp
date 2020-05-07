#include "Object.h"
#include "Person.h"
#include "Event.h"
//����������� ��� ����������
Person::Person(void)
{
	name = "";
	age = 0;
}
//����������
Person::~Person()
{
}
//����������� � �����������
Person::Person(string M, int C)
{
	name = M;
	age = C;
}
//����������� �����������
Person::Person(const Person& person)
{
	name = person.name;
	age = person.age;
}
//���������
void Person::Set_name(string M)
{
	name = M;
}
void Person::Set_age(int C)
{
	age = C;
}
//�������� ������������
Person& Person::operator=(const Person& c)
{
	if (&c == this) return *this;
	name = c.name;
	age = c.age;
}
//����� ��� ��������� ���������
void Person::Show()
{
	cout << "NAME : " << name << endl;
	cout << "AGE : " << age << endl;
}
//����� ��� ����� �������� ���������
void Person::Input()
{
	cout << "Name: "; cin >> name;
	cout << "Age: "; cin >> age;
}
void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:
			cout << "name= " << name << endl;
			break;
		}
	}
}
int Person::show_age()
{
	return age;
}
