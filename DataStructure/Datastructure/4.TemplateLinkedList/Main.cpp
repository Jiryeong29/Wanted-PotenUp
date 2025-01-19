#include <iostream>
#include "LinkedList.h"
int main() 
{
	LinkedList<int> list;
	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.Insert(40);
	list.Insert(50);


	std::cout << "--------리스트 데이터 출력 ----------\n";
	list.Print();
	list.Delete(30);
	list.Delete(50);

	list.Delete(60);
	list.Delete(5);

	std::cout << "--------리스트 삭제 후 출력 ----------\n";
	list.Print();

	std::cin.get();
}