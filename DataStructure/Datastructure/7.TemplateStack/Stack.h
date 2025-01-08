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

	// 스택이 가득 찼는지 확인하는 함수.
	inline bool IsFull() const
	{
		return count == size;
	}

	bool Push(T value)
	{
		if (IsFull())
		{
			std::cout << "스택이 가득차 저장 실패\n";
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
			std::cout << "스택이 비어서 출력 실패\n";
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