#pragma once
#include "stdafx.h"
#include "file.h"
using namespace std;

class docx :public file
{
public:
	//конструктор производный от file
	docx(string _fileName) :file(_fileName) {};
	//функция, которая ищет SearchText в файле 
	void search();
};
