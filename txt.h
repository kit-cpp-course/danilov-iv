#pragma once
#include "stdafx.h"
#include "file.h"

using namespace std;

class Txt :public file
{
public:
	//конструктор производный от file
	Txt(string _fileName) : file(_fileName) {};
	//функция, которая ищет SearchText в файле 
	void search();
};

