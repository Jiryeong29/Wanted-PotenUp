#include "Student.h"
#include <iostream>
Student::Student()
	:major(nullptr)
{
}
Student::Student(int age, const wchar_t* name, const wchar_t* otherMajor)
	: Person(age, name), major(nullptr)
{
	std::cout << "Student 생성자 호출" << std::endl;
	size_t len = wcslen(otherMajor)+1; // wcslen: wchar_t[] 문자열 길이 구하는 함수
	this->major = new wchar_t[len];
    wcscpy_s(this->major, len, otherMajor);
}

Student::~Student()
{
	std::cout << "Student 소멸자 호출" << std::endl;
	delete[] major;
}

Student::Student(const Student& other)
	: Person(other.age, other.name)
{
	// person객체의 문자열에 대해 동적할당을 해줘야 하는데 여기서 또 해줘야 하나?
	//this->age = other.age;

	//// name 복사
	//size_t len = wcslen(other.name)+1;
	//this->name = new wchar_t[len];
	//wcscpy_s(this->name, len, other.name);
	// major 복사
	size_t len = wcslen(other.major)+1;
	len = wcslen(other.major)+1;
	this->major = new wchar_t[len];
	wcscpy_s(this->major, len, other.major);

}


void Student::ShowData()
{
	std::wcout << "이름 : " << this->name << std::endl;
	std::cout << "나이 : " << this->age << std::endl;
	std::wcout << "전공 : " << major << std::endl;


}
