// 전처리(Pre - Process).
#include <iostream>
#include "Log.h"
//void Log(const char* message); 이것은 꼭 지워줘야 함. 있으면 코드 중복으로 문제가 생김

//#define Square(x)((x)*(x))

inline int Square(int x) {
	return x * x;
}
// 진입점(Entry Point)
int main() {
	//출력
	//std::cout << "Hello World\n";


	Log("Hello World");
	std::cout << Square(10) << "\n";

	// 의미없음, 바로 종료되지 말라고 추가. 아무 문자나 입력되라고 하는 것
	std::cin.get();


}