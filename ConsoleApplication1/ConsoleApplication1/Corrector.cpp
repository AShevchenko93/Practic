#include "Corrector.h"



Corrector::Corrector()
{
}

void Corrector::open(const char *file_name)
{
	FILE *file = fopen(file_name, "rb");
	if (file == NULL)
	{
		fputs("Ошибка файла", stderr);
		exit(1);
	}
	fseek(file, 0, SEEK_END);                          
	long lSize = ftell(file);                           
	rewind(file);
	text.resize(lSize/2);
	if (text.data() == NULL)
	{
		fputs("Ошибка памяти", stderr);
		exit(2);
	}
	size_t result = fread(text.data(), 1, lSize, file);
	if (result != lSize)
	{
		fputs("Ошибка чтения", stderr);
		exit(3);
	}
	fclose(file);
	
}

void Corrector::write()
{
	FILE * ptrFile = fopen("2.txt", "wb");
	fwrite(text.data(), 2, text.size(), ptrFile);
	fclose(ptrFile);
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
	for (int i = 1; i < text.size(); i++)
	{
		if (!iswcntrl(text[i]))
		{
			Intermediate_word.push_back(text[i]);
		}
		else
		if(Intermediate_word.size() > 0)
		{
			suggest Last_word;
			Last_word.word.resize(Intermediate_word.size());
			Last_word.word = Intermediate_word;
			Last_word.weght = Intermediate_word.size();
			dictionary.push_back(Last_word);
			Intermediate_word.clear();
		}
	}
	suggest Last_word;
	Last_word.word.resize(Intermediate_word.size());
	Last_word.word = Intermediate_word;
	Last_word.weght = Intermediate_word.size();
	dictionary.push_back(Last_word);
	Intermediate_word.clear();
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
