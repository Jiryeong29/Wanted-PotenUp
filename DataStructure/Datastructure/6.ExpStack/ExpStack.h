#pragma once
#include <iostream>

const int maxCount = 3;

class ExpStack
{
public:
	ExpStack()
	{
		// �迭 0.0���� �ʱ�ȭ
		memset(data, 0.0f, sizeof(float) * maxCount);

	}

	void Clear()
	{
		count = 0;
	}

	// ���ÿ� ����� ����� �� ��ȯ �Լ�.
	int Count() const
	{
		return count;
	}

	// ������ ������� Ȯ���ϴ� �Լ�
	bool IsEmpty() const
	{
		return count == 0;
	}

	// ������ �߰� �Լ�.
	void Push(float exp)
	{
		// ������ ���� á���� Ȯ��.
		if (count == maxCount)
		{
			// �α�.
			std::cout << "������ �������� ������ ���忡 �����߽��ϴ�.\n";
			return;
		}
		data[count] = exp;

		++count;
	}

	// ������ ����(�� ��ȯ) �Լ� (Pop)
	float Pop(float& outValue)
	{
		// ������ ������� ����.
		if (IsEmpty())
		{
			std::cout << "������ �������� ������ ��ȯ�� �����߽��ϴ�.\n";
			return false;
		}

		--count;
		outValue = data[count];

		return true;
	}



	// ������ ����(�� ��ȯ) �Լ�.

private:
	float data[maxCount];

	int count =0;
};