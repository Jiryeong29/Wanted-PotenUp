#include "Student.h"
#include <iostream>
Student::Student()
	:major(nullptr)
{
}
Student::Student(int age, const wchar_t* name, const wchar_t* otherMajor)
	: Person(age, name), major(nullptr)
{
	std::cout << "Student ������ ȣ��" << std::endl;
	size_t len = wcslen(otherMajor)+1; // wcslen: wchar_t[] ���ڿ� ���� ���ϴ� �Լ�
	this->major = new wchar_t[len];
    wcscpy_s(this->major, len, otherMajor);
}

Student::~Student()
{
	std::cout << "Student �Ҹ��� ȣ��" << std::endl;
	delete[] major;
}

Student::Student(const Student& other)
	: Person(other.age, other.name)
{
	// person��ü�� ���ڿ��� ���� �����Ҵ��� ����� �ϴµ� ���⼭ �� ����� �ϳ�?
	//this->age = other.age;

	//// name ����
	//size_t len = wcslen(other.name)+1;
	//this->name = new wchar_t[len];
	//wcscpy_s(this->name, len, other.name);
	// major ����
	size_t len = wcslen(other.major)+1;
	len = wcslen(other.major)+1;
	this->major = new wchar_t[len];
	wcscpy_s(this->major, len, other.major);

}


void Student::ShowData()
{
	std::wcout << "�̸� : " << this->name << std::endl;
	std::cout << "���� : " << this->age << std::endl;
	std::wcout << "���� : " << major << std::endl;


}
