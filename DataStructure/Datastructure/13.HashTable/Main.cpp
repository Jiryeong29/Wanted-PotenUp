#include <iostream>
#include "HashTable.h"
int main()
{
	HashTable table;
	table.Add("Park", "Yujin");
	table.Add("Shin", "Jiryeong");
	table.Add("An", "Hongjun");
	table.Add("kim", "NamSook");

	table.Print();

	Pair<std::string, std::string> value;
	if(table.Find("Kim", value))
	{
		std::cout << "Ű : Baker �׸��� ã�ҽ��ϴ�.\n";
	}
	else
	{
		std::cout << "Ű : Beaker�׸��� �� ã�ҽ��ϴ�.\n";
	}
	table.Delete("kim");
	std::cin.get();
}