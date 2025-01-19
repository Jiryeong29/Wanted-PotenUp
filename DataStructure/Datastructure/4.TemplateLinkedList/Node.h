#pragma once
#include <iostream>


template<typename T>
class Node
{
	// std::cout�� ���� ����� �� �ֵ��� �����ε�.
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// ����.
	template<typename T>
	friend class LinkedList;

public:
	Node() 
		:data()
	{
		/*if (std::is_pointer<T>())
		{
			data = nullptr;
		}
		else
		{
			data = 0;
		}*/
	}
	Node(T data)
		:data(data)
	{
	}
private:
	T data = 0;
	Node<T>* next = nullptr;
};