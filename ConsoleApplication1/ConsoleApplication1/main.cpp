#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <sys/stat.h>
#include "Corrector.h"
using namespace std;

/*
suggest get_suggetion(wchar_t *target, wchar_t **base)
{
	int length;
	length = wcslen(target);
	for (int i = 0; i<length; i++)
	{

	}
	return 
}*/

int main()
{
	setlocale(0, "");
	Corrector base;
	const char file[] = { "1.txt" };
	base.open(file);
	base.write();
	//base.Create_dictionary();
	//base.Number_words();
	//base.Reciving_word();
	//base.Find();
	system("pause");
	return 0;
}