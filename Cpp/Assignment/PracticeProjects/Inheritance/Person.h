#pragma once
// ����, �̸�
class Person
{
public:
	Person();
	Person(int age, const wchar_t* name);
	~Person();

	Person(const Person& other);


protected:
	int age;
	wchar_t* name;
};

