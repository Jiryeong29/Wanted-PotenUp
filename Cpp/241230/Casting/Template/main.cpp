#include <iostream>




// int 타입 값 바꾸기
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}

//void Swap(float& a, float& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}

//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}

// 템플릿.
template<typename T> // 관용적으로 typename을 T또는 Type을 쓴다.(소문자 t는 잘 안 쓴다).
//template<typename T, int size, char* name> // 이런식으로도 사용가능
//template <class T> //이건 예전방법 허용은 하지만 요즘에는 잘 쓰지 않음
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int number1 = 10;
	int number2 = 20;

	Swap<int>(number1, number1);
	std::cout << number1 << " : " << number2 << std::endl;

	float number3 = 10.00f;
	float number4 = 20.00f;
	Swap<float>(number3, number4);
	std::cout << number3 << " : " << number4 << std::endl;

	std::cin.get();

}