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
		std::cout << "키 : Baker 항목을 찾았습니다.\n";
	}
	else
	{
		std::cout << "키 : Beaker항목을 못 찾았습니다.\n";
	}
	table.Delete("kim");
	std::cin.get();
}