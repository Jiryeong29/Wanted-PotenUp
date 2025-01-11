#pragma once
#include "core.h"


class ENGINE_API Vector2
{
public:
	Vector2(int x = 0, int y = 0);
	~Vector2() = default;

	// 연산자 오버로딩
	Vector2 operator +(const Vector2& other);
	Vector2 operator -(const Vector2& other);
	bool operator ==(const Vector2& other);
	bool operator !=(const Vector2& other);
public:
	// x 좌표 y 좌표.
	int x = 0.0f;
	int y = 0.0f;
};