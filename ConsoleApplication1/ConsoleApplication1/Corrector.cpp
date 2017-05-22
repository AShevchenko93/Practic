#include "Corrector.h"



Corrector::Corrector()
{
}

void Corrector::open(const char *file_name)
{
	FILE *file = fopen(file_name, "rb");
	if (file == NULL)
	{
		fputs("������ �����", stderr);
		exit(1);
	}
	fseek(file, 0, SEEK_END);                          
	long lSize = ftell(file);                           
	rewind(file);
	text.resize(lSize/2);
	if (text.data() == NULL)
	{
		fputs("������ ������", stderr);
		exit(2);
	}
	size_t result = fread(text.data(), 1, lSize, file);
	if (result != lSize)
	{
		fputs("������ ������", stderr);
		exit(3);
	}
	fclose(file);
	
	/*wifstream fs_in(file_name, ios::binary);
	int size = 0;
	fs_in.seekg(0, ios::end);
	size = fs_in.tellg();
	if (size & 1)
	{
		cerr << "������ � �������� �����" << endl;
	}
	text.resize(size / 2);
	fs_in.clear();
	fs_in.seekg(0, ios::beg);
	// apply BOM-sensitive UTF-16 facet
	fs_in.imbue(locale(fs_in.getloc(), new codecvt_utf16<wchar_t, 0x10ffff, consume_header>));
	fs_in.read(text.data(), text.size());
	fs_in.close();*/
}

void Corrector::write()
{
	FILE * ptrFile = fopen("2.txt", "wb");
	fwrite(text.data(), 2, text.size(), ptrFile);
	fclose(ptrFile);
}

void Corrector::Find()
{
	int length_word = text.size() - 1;
	int n = dictionary.size();
	vector<int> pos;
	for (int i=0; i < n; i++)
	{
		int k = dictionary[i].word.size();
		if ((k - 2) < length_word && (k + 2) > length_word)
		{
			bool flag = false;
			for (int j = 0; j < (text.size()-1) && j < k; j++)
			{
				if (dictionary[i].word[j] == text[j+1])
				{
					dictionary[i].weght++;
					flag = true;
				}
			}
			if(flag) pos.push_back(i);
		}
	}
	if (pos.size() > 0)
	{
		Suggest_word(pos);
		Write_suggest_word();
	}
}

void Corrector::Find2()
{

}

void Corrector::Create_dictionary()
{
	vector<wchar_t> Intermediate_word;
	for (int i = 1; i < text.size(); i++)
	{
		wchar_t Intermediate_character = text[i];
		if (!iswcntrl(Intermediate_character))
		{
			Intermediate_word.push_back(Intermediate_character);
		}
		else
		if(Intermediate_word.size() > 0)
		{
			suggest Last_word;
			Last_word.word.resize(Intermediate_word.size());
			Last_word.word = Intermediate_word;
			Last_word.weght = 0;
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

void Corrector::Reciving_word()
{
	text.clear();
	open("Reciving_word.txt");
}

void Corrector::Suggest_word(vector<int> pos)
{
	for (int i = 0; i < pos.size(); i++)
	{
		float chance;
		chance = (float)dictionary[pos[i]].weght/(float)dictionary[pos[i]].word.size();
		if (chance > 0.6)
		{
			for (int j = 0; j < dictionary[pos[i]].word.size(); j++)
			{
				find_word.push_back(dictionary[pos[i]].word[j]);
			}
			find_word.push_back('\r');
			find_word.push_back('\n');
		}
	}
}

void Corrector::Write_suggest_word()
{
	FILE * ptrFile = fopen("Suggest_word.txt", "wb");
	fwrite(find_word.data(), 2, find_word.size(), ptrFile);
	fclose(ptrFile);
}




Corrector::~Corrector()
{
}
