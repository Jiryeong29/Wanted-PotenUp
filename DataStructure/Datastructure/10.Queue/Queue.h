#pragma once
#include <iostream>
// 큐의 최대 크기
const int maxSize = 100;

class Queue
{
public:
	Queue() 
	{
		memset(data, 0, sizeof(int) * maxSize);
	}

	bool IsEmpty() const
	{
		return front == rear;
	}
	bool IsFull() const
	{
		return false;
	}
	// 데이터 추가.
	void Enqueue(int value)
	{
		if (IsFull())
		{
			std::cout << "Error: 큐가 가득참.\n";
			return;
		}

		// 데이터 추가할 인덱스 계산후 삽입.
		rear = (rear + 1) % maxSize;
		data[rear] = value;
	}

	// 데이터 추출.
	bool Dequeue(int& outValue)
	{
		if (IsEmpty())
		{
			std::cout << "Error: 큐가 비어있음.\n";
			return false;
		}

		// 데이터 추출할 위치를 찾아서 추출.
		front = (front + 1) % maxSize;
		outValue = data[front];
		return true;
	}

	// 출력.
	void Print()
	{
		std::cout << "큐 내용: ";
		int max = (front < rear) ? rear : rear + maxSize;
		for (int ix = front + 1; ix <= max; ++ix)
		{
			std::cout << data[ix % maxSize] << " ";
		}

		std::cout << "\n";
	}


	

private:
	
	int front = 0;		// 데이터 출력 위치
	int rear = 0;		// 데이터 입력 위치

	int data[maxSize];

};
