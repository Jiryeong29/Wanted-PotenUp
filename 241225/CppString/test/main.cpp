#include <iostream>
#include <cstring> // iostream하면 같이 긁어와줘서 안 해도 됨

void TestFunction(char string[]) { // 함수로 넘어가면 배열의 크기를 추정하기 어렵다. 따라서 배열을 c계열에서 넘기려면 길이를 같이 넘겨야 한다. 
	int count = sizeof(string) / sizeof(string[0]); // 이렇게 구하면 안 구해진다.
	std::cout << "count : " << count << "\n";
	
}

int main() {
	char charArray[] = "heello";

	const char* rawString = "Df df";
	int length = 0;

	while(true)
	{
		// 종료 조건(탈출 조건)
		// Todo : 종료조건
		if (rawString[length] == '\0') {
			break;
		}
		++length;
	}


	// 함수 길이 구하기
	//size_t len = strlen(rawString);


	// Heap - 자유메모리 - 책임
	char* heapString = new char[length + 1];

	// 문자열 복사
	//strcpy(heapString, rawString); //오류 나는데, strycpy_s를 대신 쓰라고 오류를 낸다.
	strcpy_s(heapString, length+1, rawString); //파라미터가 하나 더 있음

	memcpy(heapString, rawString, sizeof(char)* length); //c라이브러리 
	heapString[length] = '\0';

	// concaternate
	//strycat_s(); // 문자열 더하기 연산은 안 하면 안 할수록 좋다. 성능면에서 좋지 ㅇ낳다.


	// + 포인터로 다룰 때는 sizeof을 쓰면 안됨
	std::cout << rawString << std::endl;

	delete[] heapString; // 포인터가 가리키는 영역이 배열이기 떄문에 []를 붙여야 한다.

}