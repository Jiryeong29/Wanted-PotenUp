#include <iostream>
#include <stdlib.h>
#include <time.h>


// �ּ�/ �ִ� �� ������ ������ ��ȯ�ϴ� �Լ�.
int RandomRange(int min, int max)
{
	// ����.
	int diff = (max - min) + 1;

	//return ((rand() / (RAND_MAX + 1))* diff) + min;
	return ((rand() * diff) / (RAND_MAX + 1)) + min;
}

int main()
{
	// �õ�(seed, ����) ����;.
	srand(static_cast<unsigned>(time(nullptr)));

	

	std::cout << RandomRange(3, 10) << '\n';
	std::cout << RandomRange(3, 10) << '\n';
	std::cout << RandomRange(3, 10) << '\n';
	std::cout << RandomRange(3, 10) << '\n';
	std::cout << RandomRange(3, 10) << '\n';
	std::cout << RandomRange(3, 10) << '\n';
	std::cout << RandomRange(3, 10) << '\n';

	std::cin.get();
}