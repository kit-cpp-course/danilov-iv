#pragma once
#include "stdafx.h"
#include "file.h"
using namespace std;

class html :public file
{
public:
	//конструктор производный от file
	html(string _fileName) :file(_fileName) {};
	//функция, которая ищет SearchText в файле 
	void search();
};
