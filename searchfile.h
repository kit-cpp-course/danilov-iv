#pragma once

#include "stdafx.h"
#include "txt.h"

using namespace std;

class searchfile
{
protected:

	//имя корневого каталога 
	string rootDir;


public:
	//конструктор
	searchfile(string _rootDir) : rootDir(_rootDir) {};
	

	//перебирает все файлы и добавляет их в вектор объектов file, вызывает функцию search от производных классов от file
	void start();

};