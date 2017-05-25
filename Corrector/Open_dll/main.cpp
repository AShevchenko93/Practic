#include "Corrector.h"

void main()
{
	Corrector base;
	const char file[] = { "1.txt" };
	base.open(file);
	base.write();
	base.Create_dictionary();
	base.Reciving_word();
	base.Find();
	system("pause");
}