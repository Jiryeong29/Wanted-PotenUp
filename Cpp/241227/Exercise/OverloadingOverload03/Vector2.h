#pragma once
#include <iostream>
class Vector2
{
public:

	Vector2();
	Vector2(float x, float y);

	// 연산자 오버로딩
	Vector2 operator+(Vector2& other);
	Vector2 operator-(Vector2& other);
	Vector2& operator= (const Vector2& other);
	Vector2& operator+=(const Vector2& other);

	bool operator ==(const Vector2& other);
	bool operator !=(const Vector2& other);


	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector); // 출력을 위한 연산자 오버로딩

	void display();

private:
	float x;
	float y;
};

