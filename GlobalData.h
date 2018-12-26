#pragma once
#include <string>

using namespace std;

//класс с данными, которые используются в нескольких других классах, в данном случае это текст, который нужно найти
class GlobalData
{
	//определяем конструктор и деструктор по умолчанию в привате, чтобы нельзя был создан только 1 объект данного класса, без возможности переопределить его
	GlobalData() = default;
	~GlobalData() = default;
	
	GlobalData& operator=(const GlobalData&) = delete;
	GlobalData(const GlobalData&) = delete;

public:
	//текст, который нужно найти
	string SearchText;
	//счетчик количества найденных файлов
	size_t countOfFound = 0;
	//функция, которая возвращает объект данного класса
	static GlobalData& getObject() {
		static GlobalData gd;
		return gd;
	}
};