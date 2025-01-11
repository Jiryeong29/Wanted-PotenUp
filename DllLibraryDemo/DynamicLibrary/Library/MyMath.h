#pragma once

// DLL 라이브러리용 클래스 제작
// Dynamic LIckig LIbrary.
// Dynamic -> Runtime -> 실행 중에
// __declspec(dllexport) | __declspec(dllimport)
#ifdef BUILD_DLL
#define MATH_DLL __declspec(dllexport)
#else 
#define MATH_DLL __declspec(dllimport)
#endif

class MATH_DLL Math
{
public:
	static int Add(int a, int b);
	static int Substract(int a, int b);
	static int Multiply(int a, int b);
	static int Divide(int a, int b);
};