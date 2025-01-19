#pragma once
#include "Person.h"
class Student : public Person
{
public:
	Student();
	Student(int age, const wchar_t* name,const wchar_t* major);

	~Student();
	Student(const Student& other);


	void ShowData();
private:
	wchar_t* major;
};

