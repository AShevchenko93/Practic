#pragma once
#ifdef CORRECTORDLL_EXPORTS
#define CORRECTORDLL_API __declspec(dllexport) 
#else
#define CORRECTORDLL_API __declspec(dllimport) 
//#pragma comment(lib, "Corrector.lib")
#endif
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>

using namespace std;
struct suggest
{
	wchar_t *word;
	size_t length=0;
};

struct answer
{
	int weght = 0;
	int pos;
};

bool operator <(const answer &a, const answer &b)
{
	return a.weght > b.weght;
}

class CORRECTORDLL_API Corrector_lite
{
public:
	Corrector_lite();
	void open(const char *);
	 void Create_dictionary();
	//CORRECTORDLL_API void Receiving_word(vector<wchar_t>);
	//void Receiving_word(const wchar_t *);
	//CORRECTORDLL_API void Find();
	vector<suggest> Find2(const wchar_t *,int);
	//CORRECTORDLL_API void Suggest_word();
	//void Suggest_word2(vector<suggest>, vector<answer>);
	void Sort_answer(vector<answer>);
	//CORRECTORDLL_API vector<wchar_t> Answer_return();
	//vector<suggest> Answer_return1();
	~Corrector_lite();
private:
	vector<wchar_t> text;
	vector<suggest> dictionary;
	int number_find_word;
};