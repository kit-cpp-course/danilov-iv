#include "stdafx.h"
#include "txt.h"


void Txt::search()
{
	GlobalData& gb = GlobalData::getObject();
	ifstream ifs(this->fileName, ios::in);
	static char c = '\0';
	string buf = "\0";
	while (ifs.peek() >= 0 && !ifs.eof())
	{
		ifs >> c; buf += c;
	}

	ifs.close();
	
	size_t pos = 0;
	if ((pos = buf.find(gb.SearchText, 0)) != string::npos) {
		gb.countOfFound++;
		cout << "Найдено в "<< this->fileName<<endl;
	}
}
