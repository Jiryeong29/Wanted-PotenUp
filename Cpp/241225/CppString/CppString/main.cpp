#include <iostream>
// 진입점(Entry Point)
int main() 
{
	//auto testString = "Hello";
	const char* testString = "Hello";
	char charArray[] = "Hello";

	// 동적할당
	// long lon g-> __int64  : 8바이트 새롭게 추가 됨 64비트 차지하는 바이트는 똑같으나 상호간의 호환이 되지 않는다. 네이밍이 모호하기 때문에 __int64가 나옴
	// __int32 : 32비트 
	size_t length = strlen("Ronnie") + 1; // size_t 메모리공간을 지칭을 할 때 4바이트 8바이트 어쩌구?
	char* name = new char[length];
	strcpy_s(name, length, "Ronnie");

	// 테스트 출력.
	std::cout << testString << "\n";
	std::cout << charArray << std::endl;
	std::cout << name << std::endl;
	//std::cout << testString << std::endl;

	// 의미는 없습니다.
	std::cin.get();

}