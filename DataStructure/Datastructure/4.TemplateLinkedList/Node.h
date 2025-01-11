#pragma once
#include <iostream>


template<typename T>
class Node
{
	// std::cout에 쉽게 출력할 수 있도록 오버로딩.
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// 예외.
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