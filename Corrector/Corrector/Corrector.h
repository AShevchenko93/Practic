#pragma once
#ifdef CORRECTORDLL_EXPORTS
#define CORRECTORDLL_API __declspec(dllexport) 
#else
#define CORRECTORDLL_API __declspec(dllimport) 
//#pragma comment(lib, "Corrector.lib")
#endif
#define _CRT_SECURE_NO_WARNINGS
#include <vector>

using namespace std;
struct suggest
{
	vector<wchar_t> word;
	int weght;
};

class Corrector
{
public:
	CORRECTORDLL_API Corrector();
	CORRECTORDLL_API void open(const char *);
	CORRECTORDLL_API void write();
	CORRECTORDLL_API void Find();
	CORRECTORDLL_API void Find2();
	CORRECTORDLL_API void Create_dictionary();
	CORRECTORDLL_API void Reciving_word();
	CORRECTORDLL_API void Suggest_word(vector<int>);
	CORRECTORDLL_API void Write_suggest_word();
	CORRECTORDLL_API ~Corrector();
private:
	vector<wchar_t> text;
	vector<suggest> dictionary;
	vector<wchar_t> find_word;
};
