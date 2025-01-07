#pragma once
#include <iostream>

class Node
{
	// std::cout에 쉽게 출력할 수 있도록 오버로딩
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// 예외.
	friend class LinkedList;
public:
	Node();
	Node(int data);
private:
	int data = 0;
	Node* next = nullptr;
};