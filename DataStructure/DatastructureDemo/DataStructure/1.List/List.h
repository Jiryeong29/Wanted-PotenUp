#pragma once
#include <iostream>
class List
{
public:

	List();
	~List();

	// 원소 추가.
	void PushBack(const int& datA);

	// Move 추가.
	void PushBack(const int&& data);

	// 접근 함수.
	int& At(int index);

	// 접근 함수.
	const int& At(int index) const;
	// 연산자 오버로딩.


	// 요소 수 반환.
	int Count() const { return cnt; }
	// 저장 용량 반환.
	int Capacity() const { return capacity; }
	// 배열 주소 반환.
	int* Data() const { return data; }

	void Print()const {
		for (int i = 0;i < cnt; ++i)
		{
			std::cout << data[i] << " ";
		}
		std::cout <<
			"\n";
	}
private:
	void ReAllocate();
private:
	int* data = nullptr;
	int capacity = 2;
	int cnt = 0;
};