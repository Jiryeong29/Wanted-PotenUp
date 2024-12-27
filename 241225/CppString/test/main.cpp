#include <iostream>
#include <cstring> // iostream�ϸ� ���� �ܾ���༭ �� �ص� ��

void TestFunction(char string[]) { // �Լ��� �Ѿ�� �迭�� ũ�⸦ �����ϱ� ��ƴ�. ���� �迭�� c�迭���� �ѱ���� ���̸� ���� �Ѱܾ� �Ѵ�. 
	int count = sizeof(string) / sizeof(string[0]); // �̷��� ���ϸ� �� ��������.
	std::cout << "count : " << count << "\n";
	
}

int main() {
	char charArray[] = "heello";

	const char* rawString = "Df df";
	int length = 0;

	while(true)
	{
		// ���� ����(Ż�� ����)
		// Todo : ��������
		if (rawString[length] == '\0') {
			break;
		}
		++length;
	}


	// �Լ� ���� ���ϱ�
	//size_t len = strlen(rawString);


	// Heap - �����޸� - å��
	char* heapString = new char[length + 1];

	// ���ڿ� ����
	//strcpy(heapString, rawString); //���� ���µ�, strycpy_s�� ��� ����� ������ ����.
	strcpy_s(heapString, length+1, rawString); //�Ķ���Ͱ� �ϳ� �� ����

	memcpy(heapString, rawString, sizeof(char)* length); //c���̺귯�� 
	heapString[length] = '\0';

	// concaternate
	//strycat_s(); // ���ڿ� ���ϱ� ������ �� �ϸ� �� �Ҽ��� ����. ���ɸ鿡�� ���� ������.


	// + �����ͷ� �ٷ� ���� sizeof�� ���� �ȵ�
	std::cout << rawString << std::endl;

	delete[] heapString; // �����Ͱ� ����Ű�� ������ �迭�̱� ������ []�� �ٿ��� �Ѵ�.

}