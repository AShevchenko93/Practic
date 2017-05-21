#include "Corrector.h"



Corrector::Corrector()
{
}

void Corrector::open(const char *file_name)
{
	wifstream fin(file_name, ios_base::binary | ios_base::in);
	if (!fin.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n";
	else
	{
		struct stat file;
		stat(file_name, &file);
		n = file.st_size;
		if (1 == (n & 1))
		{
			cout << "Ошибка в файле считывания" << endl;
		}
		text.resize(n);
		fin.read(text.data(), n);
	}
	fin.close();
	vector<wchar_t> text2;
	for (int i = 0; i < n; i = i + 2)
	{
		text2.push_back(text[i] + text[i + 1]);
	}
	text.clear();
	for (int i = 0; i < text2.size(); i++)
	{
		text.push_back(text2[i]);
	}
}

void Corrector::write()
{
	wofstream file("2.txt", ios_base::binary | ios_base::out);
	file.write(text.data(), n);
	file.close();
}

void Corrector::Find()
{
	int length_word = text.size();
	vector<int> Concurrences;
	vector<int> pos;
	int k = 0;
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (dictionary[i].weght == length_word)
		{
			pos.push_back(i);
			Concurrences.push_back(0);
			for (int j = 0; j << dictionary[i].weght;j++)
			{
				if (dictionary[i].word[j] == text[j])
				{
					Concurrences[k]++;
					
				}
			}
			k++;
		}
	}
	if (pos.size() > 0)Suggest_word(pos, Concurrences);
	cout << "Количество совпадений: " << pos.size() << endl;;
}

void Corrector::Find2()
{

}

void Corrector::Create_dictionary()
{
	vector<wchar_t> Intermediate_word;
	for (int i = 2; i < n; i++)
	{
		if (i == (n - 5) && text[i] != '\r')
		{
			for (; i < n; i++)
			{
				Intermediate_word.push_back(text[i]);
				suggest Last_word;
				Last_word.word.resize(Intermediate_word.size());
				Last_word.word = Intermediate_word;
				Last_word.weght = Intermediate_word.size();
				dictionary.push_back(Last_word);
				Intermediate_word.clear();
			}
			break;
		}
		
		if (text[i] != '\r' && text[i+1] != 0 && text[i+2] != '\n' && text[i+3] != '\0')
		{
			Intermediate_word.push_back(text[i]);
		}
		else
		{
			suggest Last_word;
			Last_word.word.resize(Intermediate_word.size());
			Last_word.word = Intermediate_word;
			Last_word.weght = Intermediate_word.size();
			dictionary.push_back(Last_word);
			Intermediate_word.clear();
		}
	}
}

void Corrector::Number_words()
{
	cout << "Количество слов в словаре: "<< dictionary.size()+1 << endl;
}

void Corrector::Reciving_word()
{
	open("Reciving_word.txt");
	write();
}

void Corrector::Suggest_word(vector<int> pos, vector<int> number)
{
	wofstream file("Suggest_word.txt", ios_base::binary | ios_base::out);
	for (int i = 0; i < pos.size(); i++)
	{
		float chance;
		chance = number[i] / dictionary[pos[i]].weght;
		if (chance > 60)
		{
			file.write(dictionary[pos[i]].word.data(), dictionary[pos[i]].weght);
		}
	}
	file.close();
}




Corrector::~Corrector()
{
}
