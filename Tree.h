#pragma once
#include "Object.h"
#include "Event.h"
#include <iostream>
using namespace std;
class Tree
{
public:
	Tree(int);//конструтор с параметрами
public:
	~Tree(void);//деструктор
	void Add();//добавление элемента в вектор
	void Del();
	void Show();
	void show_age();
	int operator() ();//размер вектора
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;//указатель на первый элемент вектора
	int size;//размер
	int cur;//текущая позиция
};
