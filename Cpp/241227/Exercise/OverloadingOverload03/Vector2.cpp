#include "Vector2.h"
#include <iostream>
Vector2::Vector2(float x, float y)
	: x(x), y(y)
{

}

Vector2 Vector2::operator+(Vector2& other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector2 Vector2::operator-(Vector2& other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vector2& Vector2::operator=(const Vector2& other)
{
	this->x = other.x;
	this->y = other.y;
	return *this;
}

bool Vector2::operator==(const Vector2& other)
{
	return (this->x == other.x && this->y == other.y) ? 1 : 0;
}

bool Vector2::operator!=(const Vector2& other)
{

	return !(*this == other);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

void Vector2::display()
{
	std::cout << "(x : " << x << ", " << "y : " << y << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Vector2& vector)
{
	os << "(x : " << vector.x << ", " << "y : " << vector.y << ")" << std::endl;
	return os;
}