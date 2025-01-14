#include "List.h"
#include <iostream>
List::List()
    : data(nullptr), capacity(2), cnt(0)
{
    data = new int[capacity];
}

List::~List()
{

    if (data != nullptr)
    {
        delete[] data;
    }
}

void List::PushBack(const int& data)
{
    // capacity�� ���� ���� ���� Ŭ ��.
    if (cnt >= capacity)
    {
        std::cout << "capcity������\n";
    }
    this->data[cnt] = data;
    ++cnt;
}

void List::PushBack(const int&& data)
{
    // capacity�� ���� ���� ���� Ŭ ��.
    if (cnt >= capacity)
    {
        std::cout << "capcity������\n";
        ReAllocate();
    }
    this->data[cnt] = data;
    ++cnt;
}

int& List::At(int index)
{
    if (index >= cnt)
    {
        std::cout << "���� �Ұ����� index�Դϴ�.\n";

        __debugbreak();
    }
    // TODO: ���⿡ return ���� �����մϴ�.

    return data[index];
}

const int& List::At(int index) const
{

    if (index >= cnt)
    {
        std::cout << "���� �Ұ����� index�Դϴ�.\n";
        __debugbreak();
    }
    // TODO: ���⿡ return ���� �����մϴ�.

    return data[index];
}

void List::ReAllocate()
{
    capacity *= 2;
    int* tmp = new int[capacity];
    data = std::move(tmp);
}
