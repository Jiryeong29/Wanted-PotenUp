#include <iostream>
#include "Student.h"
//	char: 1byte(영문자(1byte)). -> const char* t 타입 | std::cout 
//  wchar_t: 2byte(동아시아권문자(2byte)) -> const wchar_t* 타입 | std::wcout | const wchar_t* wideName = L"Ronnie"

int main()
{
	Student Jang1(20, L"Jang Se Yun", L"Computer Science");
	Jang1.ShowData();

	Student Jang2(Jang1);
	Jang2.ShowData();
}