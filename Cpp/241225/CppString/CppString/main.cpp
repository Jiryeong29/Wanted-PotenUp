#include <iostream>
// ������(Entry Point)
int main() 
{
	//auto testString = "Hello";
	const char* testString = "Hello";
	char charArray[] = "Hello";

	// �����Ҵ�
	// long lon g-> __int64  : 8����Ʈ ���Ӱ� �߰� �� 64��Ʈ �����ϴ� ����Ʈ�� �Ȱ����� ��ȣ���� ȣȯ�� ���� �ʴ´�. ���̹��� ��ȣ�ϱ� ������ __int64�� ����
	// __int32 : 32��Ʈ 
	size_t length = strlen("Ronnie") + 1; // size_t �޸𸮰����� ��Ī�� �� �� 4����Ʈ 8����Ʈ ��¼��?
	char* name = new char[length];
	strcpy_s(name, length, "Ronnie");

	// �׽�Ʈ ���.
	std::cout << testString << "\n";
	std::cout << charArray << std::endl;
	std::cout << name << std::endl;
	//std::cout << testString << std::endl;

	// �ǹ̴� �����ϴ�.
	std::cin.get();

}