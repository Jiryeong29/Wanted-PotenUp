#pragma once
#include <iostream>

template<typename T, int size =10>
class Stack
{
public:
	Stack()
	{
		memset(data, 0, sizeof(T) * size);
	}

	void Clear()
	{
		count = 0;
	}

	inline int Count() const
	{
		return count;
	}

	inline bool IsEmpty() const
	{
		return count == 0;
	}

	// ������ ���� á���� Ȯ���ϴ� �Լ�.
	inline bool IsFull() const
	{
		return count == size;
	}

	bool Push(T value)
	{
		if (IsFull())
		{
			std::cout << "������ ������ ���� ����\n";
			return false;
		}

		data[count] = value;
		++count;
		return true;
	}

	bool Pop(T& outValue)
	{
		if (IsEmpty())
		{
			std::cout << "������ �� ��� ����\n";
			return false;
		}
		--count;
		outValue = data[count];
		return true;
	}
	
private:
	T data[size];

	int count = 0;
};