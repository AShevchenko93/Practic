#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <sys/stat.h>
#include <locale>
#include <codecvt>
using namespace std;
struct suggest
{
	vector<wchar_t> word;
	int weght;
};

class Corrector
{
public:
	Corrector();
	void open(const char *);
	void write();
	void Find();
	void Find2();
	void Create_dictionary();
	void Reciving_word();
	void Suggest_word(vector<int>);
	void Write_suggest_word();
	~Corrector();
private:
	vector<wchar_t> text;
	vector<suggest> dictionary;
	vector<wchar_t> find_word;
};

