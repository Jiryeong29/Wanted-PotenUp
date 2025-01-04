#include <iostream>




// int Ÿ�� �� �ٲٱ�
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

// ���ø�.
template<typename T> // ���������� typename�� T�Ǵ� Type�� ����.(�ҹ��� t�� �� �� ����).
//template<typename T, int size, char* name> // �̷������ε� ��밡��
//template <class T> //�̰� ������� ����� ������ ���򿡴� �� ���� ����
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