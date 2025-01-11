#include <iostream>

// Main.cpp-> 컴파일 -> Main.obj
// 링커(Linker) -> Library.lib 연결
// exe 생성 

// 1차 방법 : library 파일에 있는 코드를 선언만 하기
//class Math
//{
//public:
//	static int Add(int a, int b);
//	static int Substract(int a, int b);
//	static int Multiply(int a, int b);
//	static int Divide(int a, int b);
//};

// 2차 
//#include <MyMath.h> // OK
#include "MyMath.h"


int main() {
	std::cout << "Hello\n";
	std::cout << "10 + 20  : " << Math::Add(10, 20) << '\n';
	std::cout << "10 - 20  : " << Math::Substract(10, 20) << '\n';
	std::cin.get();
}