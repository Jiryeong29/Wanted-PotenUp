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
    // capacity가 현재 개수 보다 클 때.
    if (cnt >= capacity)
    {
        std::cout << "capcity가득참\n";
    }
    this->data[cnt] = data;
    ++cnt;
}

void List::PushBack(const int&& data)
{
    // capacity가 현재 개수 보다 클 때.
    if (cnt >= capacity)
    {
        std::cout << "capcity가득참\n";
        ReAllocate();
    }
    this->data[cnt] = data;
    ++cnt;
}

int& List::At(int index)
{
    if (index >= cnt)
    {
        std::cout << "접근 불가능한 index입니다.\n";

        __debugbreak();
    }
    // TODO: 여기에 return 문을 삽입합니다.

    return data[index];
}

const int& List::At(int index) const
{

    if (index >= cnt)
    {
        std::cout << "접근 불가능한 index입니다.\n";
        __debugbreak();
    }
    // TODO: 여기에 return 문을 삽입합니다.

    return data[index];
}

void List::ReAllocate()
{
    capacity *= 2;
    int* tmp = new int[capacity];
    data = std::move(tmp);
}
