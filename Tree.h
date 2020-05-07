#pragma once
#include "Object.h"
#include "Event.h"
#include <iostream>
using namespace std;
class Tree
{
public:
	Tree(int);//���������� � �����������
public:
	~Tree(void);//����������
	void Add();//���������� �������� � ������
	void Del();
	void Show();
	void show_age();
	int operator() ();//������ �������
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;//��������� �� ������ ������� �������
	int size;//������
	int cur;//������� �������
};
