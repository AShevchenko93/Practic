#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <sys/stat.h>
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
	void Number_words();
	void Reciving_word();
	void Suggest_word(vector<int>, vector<int>);
	~Corrector();
private:
	vector<wchar_t> text;
	vector<suggest> dictionary;
	vector<wchar_t> find_word;
	int n;
};

