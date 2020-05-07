#include "Person.h";
#include "Abiturient.h";
#include "Object.h";
#include "Dialog.h"
#include "Event.h"
#include <iostream>;
#include <string>;
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	Dialog D;
	cout << "m - создание группы" << endl;
	cout << "+ - добавление элемента в группу" << endl;
	cout << "- - удаление элемента из группы" << endl;
	cout << "s - вывод информации об элементах группы" << endl;
	cout << "z - вывод информации о среднем возрасте" << endl;
	cout << "q - конец работы" << endl;
	D.Execute();
	system("pause");
}
