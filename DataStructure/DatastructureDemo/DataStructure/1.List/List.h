#pragma once
#include <iostream>
class List
{
public:

	List();
	~List();

	// ���� �߰�.
	void PushBack(const int& datA);

	// Move �߰�.
	void PushBack(const int&& data);

	// ���� �Լ�.
	int& At(int index);

	// ���� �Լ�.
	const int& At(int index) const;
	// ������ �����ε�.


	// ��� �� ��ȯ.
	int Count() const { return cnt; }
	// ���� �뷮 ��ȯ.
	int Capacity() const { return capacity; }
	// �迭 �ּ� ��ȯ.
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