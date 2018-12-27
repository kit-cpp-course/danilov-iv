#include "stdafx.h"
#include <windows.h>
#include "searchfile.h"

using namespace std;
namespace fs = std::experimental::filesystem;

int main(size_t size, char ** args)
{
	setlocale(0, "rus");
	//проверка количества аргументов (должно быть 2: путь каталога и искомое слово)
	if (size != 2) {
		cout << "Ошибка в введенных данных" << endl;
		system("pause");
		return 0;
	}
	//проверяем директорию на существование
	if (!fs::exists(args[0]))
	{
		cout << "Такой директории не существует" << endl;
		system("pause");
		return 0;
	}
	GlobalData & gb = GlobalData::getObject();
	gb.SearchText = args[1];
	//создаем объект класса searchfile, который находит файлы типа file, docx и т.д.
	searchfile sf(args[0]);
	sf.start();
	system("pause");
	return 0;
}