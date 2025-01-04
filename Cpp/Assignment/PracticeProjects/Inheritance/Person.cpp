#include "Person.h"
#include <iostream>

Person::Person()
	: age(0), name(nullptr)
{

	std::cout << "Person �⺻������" << std::endl;
}

// otherName�� const�� ���̸� ������ ���µ� ���̷���?
Person::Person(int age, const wchar_t* otherName)
	: age(age), name(nullptr)
{
	std::cout << "Person ������" << std::endl;
	size_t len = wcslen(otherName) + 1; // wcslen: wchar_t[] ���ڿ� ���� ���ϴ� �Լ�
	this->name = new wchar_t[len];
	wcscpy_s(this->name, len, otherName);
}

Person::~Person()
{
	std::cout << "Person �Ҹ���!" << std::endl;
	delete[] name;
}

Person::Person(const Person& other)
{

}