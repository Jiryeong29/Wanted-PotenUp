#include <iostream>
#include <functional>        // c++ 11.

// �Լ� ������.
 void (*functionPointer)();
//typedef void (*functionPointer)();
//using usingFP = void (*)();
std::function<void()> newFunctionPointer;

int main()
{
    // Lamda �Լ� (���� �Լ�).
    // �����ϸ鼭 ȣ��.
    //[]() { std::cout << "Hello Lamda.\n"; }();

    // ���� �Լ� ����.
    int count = 0;
    auto function = [&count](/*int count*/) { ++count; };

    // �Լ� �����͸� ����� ���� ����.
    functionPointer = []() { std::cout << "Hello\n"; };
    functionPointer();

    newFunctionPointer = functionPointer;
    newFunctionPointer();

    // ȣ��.
    //auto returnValue = function();

    // CPU �ڷḦ GPU���� �ѱ�� -> GPU�� �׸��� -> �����(Backbuffer).
    //   Backbuffer: �̹��� (Texture2D). -> Color[]

    function();
    function();
    function();
    function();

    std::cout << "Count: " << count << "\n";

    std::cin.get();
}