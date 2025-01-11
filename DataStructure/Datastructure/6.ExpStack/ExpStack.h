#pragma once
#include <iostream>

const int maxCount = 3;

class ExpStack
{
public:
	ExpStack()
	{
		// 배열 0.0으로 초기화
		memset(data, 0.0f, sizeof(float) * maxCount);

	}

	void Clear()
	{
		count = 0;
	}

	// 스택에 저장된 요소의 수 반환 함수.
	int Count() const
	{
		return count;
	}

	// 스택이 비었는지 확인하는 함수
	bool IsEmpty() const
	{
		return count == 0;
	}

	// 데이터 추가 함수.
	void Push(float exp)
	{
		// 스택이 가득 찼는지 확인.
		if (count == maxCount)
		{
			// 로그.
			std::cout << "스택이 가득차서 데이터 저장에 실패했습니다.\n";
			return;
		}
		data[count] = exp;

		++count;
	}

	// 데이터 삭제(값 반환) 함수 (Pop)
	float Pop(float& outValue)
	{
		// 스택이 비었으면 종료.
		if (IsEmpty())
		{
			std::cout << "스택이 가득차서 데이터 반환에 실패했습니다.\n";
			return false;
		}

		--count;
		outValue = data[count];

		return true;
	}



	// 데이터 삭제(값 반환) 함수.

private:
	float data[maxCount];

	int count =0;
};