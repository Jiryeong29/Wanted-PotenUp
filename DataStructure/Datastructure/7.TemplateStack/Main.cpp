
#include <iostream>
#include "stack.h"
#include <time.h>


// 최소/ 최대 값 사이의 랜덤을 반환하는 함수.
int RandomRange(int min, int max)
{
	// 차이.
	int diff = (max - min) + 1;

	//return ((rand() / (RAND_MAX + 1))* diff) + min;
	return ((rand() % diff) / (RAND_MAX + 1)) + min;


}

int main()
{
	// 시드(seed, 종자) 설정;.
	srand(static_cast<unsigned>(time(nullptr)));
	Stack<float,3> stack;

	if (stack.Push((float)RandomRange(10, 300)))
	{

		std::cout << "첫 번째 게임 종료 \n";
	}
	if (stack.Push((float)RandomRange(10, 300)))
	{

		std::cout << "두 번째 게임 종료 \n";
	}
	if (stack.Push((float)RandomRange(10, 300)))
	{

		std::cout << "세 번째 게임 종료 \n";
	}
	if (stack.Push((float)RandomRange(10, 300)))
	{

		std::cout << "네 번째 게임 종료 \n";
	}

	int index = 0;
	while (!stack.IsEmpty())
	{

		float value;
		if (stack.Pop(value))
		{
			std::cout << "현재 경험치 : " << value << '\n';

		}
	}

	std::cin.get();
}