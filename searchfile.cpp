#include "stdafx.h"
#include "searchfile.h"

using namespace std;
namespace fs = std::experimental::filesystem;

void searchfile::start() {

	
	//создаем массив (массив  умных указателей на класс file)
	//создавать обьекты такого класса(абстрактного) нельзя, но можно создавать на него ссылки
	//этими ссылками так же можно указывать на все классы, что унаследованы от класса file
	//т.е. у нас массив с ссылками, что указывают на разные классы, которые унаследованы от одного класса file
	//у него есть все нужные методы, кроме search, их реализует каждый потомок самостоятельнj
	//vector - это такой динамический класс, который при переполнении сам выделяет себе память
	vector <shared_ptr<file>> files;
	//функция рекурсивного прохода по всем файлам каталога и его подкаталогов
	GlobalData& gb = GlobalData::getObject();
	for (const auto & entry : fs::recursive_directory_iterator(rootDir))
	{
		string path = entry.path().string(),
		ext = entry.path().extension().string();
		//ext - расширение файла, заходим в тело условного оператора соответсвующего типа
		if (ext == ".txt") {
			//добавляем в вектор указатель на объект типа Txt
			files.push_back(shared_ptr<file>(new Txt(path)));
			//вызываем функцию поиска для данного объекта 
			files[files.size() - 1]->search();
		}
		if (ext == ".docx")
		{
			//аналогично
		}
		//аналогично и для других типов	
	}
	if (gb.countOfFound == 0) cout << "Совпадений не найдено"<<endl;
	
}