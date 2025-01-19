#pragma once
#include <iostream>
// 2차원 벡터 클래스.
class Vector2
{
public :
	Vector2();
	Vector2(float x, float y =0.0f); // 헤더에서만 기본 매게변수를 지정해야 한다. 뒤에서부터 기본 매개변수 써야 하낟.

	// 더하기
	Vector2 Add(const Vector2& ohter);

	// 곱하기
	Vector2 Multiply(const Vector2& other);

	// 연산자 오버로딩
	// 특별한 함수
	Vector2 operator+(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	float operator[](int index);
	float Get(int index);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector)
	{
		os << "(" << vector.GetX() << "," << vector.GetX() << ")\n";
		return os;
	}

	float GetX() const;
	float GetY() const;

	float operator[](int index);

private:
	float x;
	float y;
};

