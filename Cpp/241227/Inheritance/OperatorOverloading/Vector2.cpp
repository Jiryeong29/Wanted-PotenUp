#include "Vector2.h"

Vector2::Vector2()
// : x(0.0f), y(0.0f)
	: Vector2(0.0f, 0.0f)
{
}

Vector2::Vector2(float x, float y)
	: x(x), y(y)
{
}

Vector2 Vector2::Add(const Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::Multiply(const Vector2& other)
{
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator+(const Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator*(const Vector2& other)
{
	//return Vector2(x * other.x, y * other.y);
	//return *this * other;
	return this->Multiply(other);
}

float Vector2::GetX() const
{
	return x;
}

float Vector2::GetY() const
{
	return y;
}

float Vector2::operator[](int index)
{
	if (index == 0) {
		return x;
	}
	if (index == 1) {
		return y;
	}

	return 0.0f;
}
