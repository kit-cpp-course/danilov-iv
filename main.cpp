#include "stdafx.h"
#include <windows.h>
#include "searchfile.h"

using namespace std;
namespace fs = std::experimental::filesystem;

int main(int argc, char *argv[])
{
	setlocale(0, "rus");
	string rootDir, SearchText;
	cout << "in name directory ";
	cin >> rootDir;
	//проверяем директорию на существование
	if (!fs::exists(rootDir)) 	cout << "Такой директории не существует" << endl;
	else
	{
		GlobalData & gb = GlobalData::getObject();
		cout << "searchText ";
		cin >> gb.SearchText;
		//создаем объект класса searchfile, который находит файлы типа file, docx и т.д.
		searchfile sf(rootDir);
		sf.start();
	}
	system("pause");
	return 0;
}
 
