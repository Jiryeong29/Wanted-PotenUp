#include "Person.h"
#include <iostream>

Person::Person()
	: age(0), name(nullptr)
{

	std::cout << "Person 기본생성자" << std::endl;
}

// otherName에 const를 붙이면 오류가 나는데 왜이러지?
Person::Person(int age, const wchar_t* otherName)
	: age(age), name(nullptr)
{
	std::cout << "Person 생성자" << std::endl;
	size_t len = wcslen(otherName) + 1; // wcslen: wchar_t[] 문자열 길이 구하는 함수
	this->name = new wchar_t[len];
	wcscpy_s(this->name, len, otherName);
}

Person::~Person()
{
	std::cout << "Person 소멸자!" << std::endl;
	delete[] name;
}

Person::Person(const Person& other)
{

}