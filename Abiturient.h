#pragma once
#include "Object.h"
#include "Person.h";
#include <string>;
#include <iostream>;
class Abiturient :
	public Person
{
public:
	Abiturient(void);
public:
	~Abiturient(void);
	void Show();
	void Input();
	Abiturient(string, int, int, string);
	Abiturient(const Abiturient&);
	float Get_ball() { return ball; }
	string Get_specialty() { return specialty; }
	void Set_ball(int);
	void Set_specialty(string);
	Abiturient& operator=(const Abiturient&);
protected:
	int ball;
	string specialty;
};

