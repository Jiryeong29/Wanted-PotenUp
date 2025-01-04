#include "NameCard.h"
#include <iostream>

NameCard::NameCard(const char* name, const char* phoneNumber, const char* email, const char* job)
{
	const char* input[4] = { name, phoneNumber, email, job };
	for (int i = 0; i < 4; ++i)
	{
		if (input[i])
		{
			size_t len = strlen(input[i]) + 1;
			data[i] = new char[len];
			strcpy_s(data[i], len, input[i]);
		}
		else
		{
			data[i] = nullptr;
		}
	}
}

NameCard::~NameCard()
{
	for (int i = 0; i < 4; ++i) {
		delete[] data[i];
	}
}

NameCard::NameCard(const NameCard& nameCard)
{
	size_t len[4];

	for (int i = 0; i < 4; ++i)
	{
		// ������ ���� ����
		len[i] = strlen(nameCard.data[i]) + 1;
		// ���� �Ҵ�
		this->data[i] = new char[len[i]];
		// ������ ����
		strcpy_s(this->data[i], len[i], nameCard.data[i]);
	}

}

void NameCard::ShowData()
{
	std::cout << std::endl;
	std::cout << "������ ��°ڽ��ϴ�...." << std::endl << std::endl;
	std::cout << "�̸� : " << data[0] << std::endl;
	std::cout << "��ȭ��ȣ : " << data[1] << std::endl;
	std::cout << "�̸��� : " << data[2] << std::endl;
	std::cout << "���� : " << data[3] << std::endl;
	std::cout << "--------------------------------" << std::endl;
}
