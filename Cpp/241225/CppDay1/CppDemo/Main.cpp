// ��ó��(Pre - Process).
#include <iostream>
#include "Log.h"
//void Log(const char* message); �̰��� �� ������� ��. ������ �ڵ� �ߺ����� ������ ����

//#define Square(x)((x)*(x))

inline int Square(int x) {
	return x * x;
}
// ������(Entry Point)
int main() {
	//���
	//std::cout << "Hello World\n";


	Log("Hello World");
	std::cout << Square(10) << "\n";

	// �ǹ̾���, �ٷ� ������� ����� �߰�. �ƹ� ���ڳ� �ԷµǶ�� �ϴ� ��
	std::cin.get();


}