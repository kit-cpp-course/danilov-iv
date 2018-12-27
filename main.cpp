#include "stdafx.h"
#include <windows.h>
#include "searchfile.h"

using namespace std;
namespace fs = std::experimental::filesystem;

int main(size_t size, char ** args)
{
	setlocale(0, "rus");
	//�������� ���������� ���������� (������ ���� 2: ���� �������� � ������� �����)
	if (size != 2) {
		cout << "������ � ��������� ������" << endl;
		system("pause");
		return 0;
	}
	//��������� ���������� �� �������������
	if (!fs::exists(args[0]))
	{
		cout << "����� ���������� �� ����������" << endl;
		system("pause");
		return 0;
	}
	GlobalData & gb = GlobalData::getObject();
	gb.SearchText = args[1];
	//������� ������ ������ searchfile, ������� ������� ����� ���� file, docx � �.�.
	searchfile sf(args[0]);
	sf.start();
	system("pause");
	return 0;
}