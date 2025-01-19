#pragma once
#include <iostream>

class Node
{
	// std::cout�� ���� ����� �� �ֵ��� �����ε�
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// ����.
	friend class LinkedList;
public:
	Node();
	Node(int data);
private:
	int data = 0;
	Node* next = nullptr;
};