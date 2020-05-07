#include "Object.h"
#include "Person.h"
#include "Abiturient.h"
#include "Tree.h"
#include "Event.h"
#include "Dialog.h"
#include <iostream>
#include <string>
using namespace std;
//конструктор
Dialog::Dialog(void) :Tree(EndState)
{
	EndState = 0;
}
//деструктор
Dialog::~Dialog(void)
{
}
//получение события
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-s/qam";//строка содержит коды операций
	string s;
	string param;

	char code;
	cout << '>';
	cin >> s;
	code = s[0];//первый символ команды
	if (OpInt.find(code) >= 0)//является ли символ кодом операции
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm':event.command = cmMake; break;//создать группу
		case '+':event.command = cmAdd; break;//добавить объект в группу
		case '-':event.command = cmDel; break;//удалить объект из группы
		case's':event.command = cmShow; break;//просмотр группы
		case'q':event.command = cmQuit; break;//конец работы
		case 'z':event.command = cmGet; break;//информация о среднем возрасте элементов
		}
		//выделяем параметры команды, если они есть
		if (s.size() > 1)
		{
			param = s.substr(1, s.size() - 1);
			int A = atoi(param.c_str());//преобразуем параметр в число
			event.a = A;//записываем в сообщение
		}
	}
	else
	{
		event.what = evNothing;//пустое событие
		cout << "Команда не найдена" << endl;
	}
}
int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);//получить событие
		HandleEvent(event);//обработать событие
	} while (!Valid());
	return EndState;
}
int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;//пустое событие
}
void Dialog::EndExec()
{
	EndState = 1;
}
//обработчик событий
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake://создание группы
			size = event.a;
			beg = new Object * [size];
			cur = 0;
			ClearEvent(event);
			break;
		case cmAdd:
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del();
			ClearEvent(event);
			break;
		case cmShow:
			Show();
			ClearEvent(event);
			break;
		case cmGet:
			show_age();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		default:Tree::HandleEvent(event);
		};
	};
}