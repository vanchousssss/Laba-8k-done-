#pragma once
#include "Object.h"
#include "Person.h"
#include "Abiturient.h"
#include "Tree.h"
#include "Event.h"
#include <iostream>
class Dialog :
	public Tree
{
public:
	Dialog(void);//конструктор
public:
	virtual ~Dialog(void);//деструктор
	virtual void GetEvent(TEvent& event);//получить событие
	virtual int Execute();//главный цикл обработки событий
	virtual void HandleEvent(TEvent& event);//обработчик
	virtual void ClearEvent(TEvent& event);//очистить событие
	int Valid();//проверка атрибута EndState
	void EndExec();//обработка события конец события
protected:
	int EndState;
};

