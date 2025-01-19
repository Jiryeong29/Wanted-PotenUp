
#include <iostream>
#include "stack.h"
#include <time.h>


// �ּ�/ �ִ� �� ������ ������ ��ȯ�ϴ� �Լ�.
int RandomRange(int min, int max)
{
	// ����.
	int diff = (max - min) + 1;

	//return ((rand() / (RAND_MAX + 1))* diff) + min;
	return ((rand() % diff) / (RAND_MAX + 1)) + min;


}

int main()
{
	// �õ�(seed, ����) ����;.
	srand(static_cast<unsigned>(time(nullptr)));
	Stack<float,3> stack;

	if (stack.Push((float)RandomRange(10, 300)))
	{

		std::cout << "ù ��° ���� ���� \n";
	}
	if (stack.Push((float)RandomRange(10, 300)))
	{

		std::cout << "�� ��° ���� ���� \n";
	}
	if (stack.Push((float)RandomRange(10, 300)))
	{

		std::cout << "�� ��° ���� ���� \n";
	}
	if (stack.Push((float)RandomRange(10, 300)))
	{

		std::cout << "�� ��° ���� ���� \n";
	}

	int index = 0;
	while (!stack.IsEmpty())
	{

		float value;
		if (stack.Pop(value))
		{
			std::cout << "���� ����ġ : " << value << '\n';

		}
	}

	std::cin.get();
}