#include "Person.h"
#include "Abiturient.h"
Abiturient::Abiturient(void) :Person()
{
	ball = 0;
	specialty = "";
}
Abiturient::~Abiturient(void)
{
}
Abiturient::Abiturient(string M, int C, int B, string G) :Person(M, C)
{
	ball = B;
	specialty = G;
}
Abiturient::Abiturient(const Abiturient& L)
{
	name = L.name;
	age = L.age;
	ball = L.ball;
	specialty = L.specialty;
}
Abiturient& Abiturient::operator=(const Abiturient& l)
{
	if (&l == this) return*this;
	name = l.name;
	age = l.age;
	return *this;
}
void Abiturient::Show()
{
	cout << "NAME : " << name << endl;
	cout << "AGE : " << age << endl;
	cout << "BALL : " << ball << endl;
	cout << "SPECIALTY : " << specialty << endl;
}
void Abiturient::Input()
{
	cout << "Name: "; cin >> name;
	cout << "Age: "; cin >> age;
	cout << "Ball: "; cin >> ball;
	cout << "Specialty: "; cin >> specialty;
}