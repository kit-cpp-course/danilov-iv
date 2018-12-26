#pragma once
#include "stdafx.h"
using namespace std;

class file
{
protected:
	

	//Имя файла 
	string fileName;

public:

	file(string _fileName) : fileName(_fileName) {};

	//виртуальная функция, которая и делает класс абстрактным
	//от этого класса будет наследоваться классы конкретного расширения файла и у каждого будет своя функия search
	virtual void search() = 0;

};