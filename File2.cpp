#pragma hdrstop
#pragma argsused

#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;
struct suggest
{
	wchar_t word[50];
	int weght;
};

suggest get_suggetion(wchar_t *target, wchar_t **base)
{
	int length;
	length=wcslen(target);
	for(int i=0;i<length;i++)
	{

	}
}
void Show_base(suggest ob)
{
	for(int i=0;i<ob.weght;i++)
	{
		cout<<ob.word[i];
	}
	cout<<endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//vector<wchar_t> base_word;
	vector<suggest> base_word;
	int ch;
	ifstream fin("1.txt");
	vector<wchar_t> Intermediate_word;
	if (!fin.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n";
	while((ch=fin.get())!=EOF)
	{
		cout<<char(ch)<<endl;
		if(char(ch)!=' ')
		{
		   Intermediate_word.push_back(wchar_t(ch));
		}else
		{
			suggest last_word;

			for(int i=0;i< Intermediate_word.size();i++)
			{
				last_word.word[i]=Intermediate_word[i];
			}
			last_word.weght= Intermediate_word.size();
			base_word.push_back(last_word);
			Intermediate_word.clear();
        }
    }
	for(int i=0;i<base_word.size();i++)
	{
		Show_base(base_word[i]);
	}
	//cout<<base_word.size();
	fin.close();
	system("pause");
	return 0;
}
