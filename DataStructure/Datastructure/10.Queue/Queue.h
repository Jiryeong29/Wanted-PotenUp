#pragma once
#include <iostream>
// ť�� �ִ� ũ��
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
	// ������ �߰�.
	void Enqueue(int value)
	{
		if (IsFull())
		{
			std::cout << "Error: ť�� ������.\n";
			return;
		}

		// ������ �߰��� �ε��� ����� ����.
		rear = (rear + 1) % maxSize;
		data[rear] = value;
	}

	// ������ ����.
	bool Dequeue(int& outValue)
	{
		if (IsEmpty())
		{
			std::cout << "Error: ť�� �������.\n";
			return false;
		}

		// ������ ������ ��ġ�� ã�Ƽ� ����.
		front = (front + 1) % maxSize;
		outValue = data[front];
		return true;
	}

	// ���.
	void Print()
	{
		std::cout << "ť ����: ";
		int max = (front < rear) ? rear : rear + maxSize;
		for (int ix = front + 1; ix <= max; ++ix)
		{
			std::cout << data[ix % maxSize] << " ";
		}

		std::cout << "\n";
	}


	

private:
	
	int front = 0;		// ������ ��� ��ġ
	int rear = 0;		// ������ �Է� ��ġ

	int data[maxSize];

};
