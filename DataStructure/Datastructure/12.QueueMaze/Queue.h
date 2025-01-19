#pragma once

#include <iostream>

// ť Ŭ����.
template<typename T, int size = 10>
class Queue
{
public:
    Queue()
    {
        // �迭�� �ʱ� ���� 0���� ����.
        memset(data, 0, sizeof(T) * size);
    }

    // ť�� ������� Ȯ���ϴ� �Լ�.
    bool IsEmpty() const
    {
        return front == rear;
    }

    // ť�� ����á���� Ȯ���ϴ� �Լ�.
    bool IsFull() const
    {
        return (rear + 1) % size == front;
    }

    // ������ �߰�.
    bool Enqueue(const T& value)
    {
        if (IsFull())
        {
            std::cout << "Error: ť�� ������.\n";
            return false;
        }

        // ������ �߰��� �ε��� ����� ����.
        rear = (rear + 1) % size;
        data[rear] = value;

        return true;
    }

    // ������ ����.
    bool Dequeue(T& outValue)
    {
        if (IsEmpty())
        {
            std::cout << "Error: ť�� �������.\n";
            return false;
        }

        // ������ ������ ��ġ�� ã�Ƽ� ����.
        front = (front + 1) % size;
        outValue = data[front];
        return true;
    }

    // ���.
    void Print()
    {
        std::cout << "ť ����: ";
        int max = (front < rear) ? rear : rear + size;
        for (int ix = front + 1; ix <= max; ++ix)
        {
            std::cout << data[ix % size] << " ";
        }

        std::cout << "\n";
    }


private:
    // �����Ͱ� ��µǴ� ��ġ.
    int front = 0;

    // �����Ͱ� �ԷµǴ� ��ġ.
    int rear = 0;

    // ������ �����.
    T data[size];
};