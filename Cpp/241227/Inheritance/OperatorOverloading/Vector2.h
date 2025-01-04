#pragma once
#include <iostream>
// 2���� ���� Ŭ����.
class Vector2
{
public :
	Vector2();
	Vector2(float x, float y =0.0f); // ��������� �⺻ �ŰԺ����� �����ؾ� �Ѵ�. �ڿ������� �⺻ �Ű����� ��� �ϳ�.

	// ���ϱ�
	Vector2 Add(const Vector2& ohter);

	// ���ϱ�
	Vector2 Multiply(const Vector2& other);

	// ������ �����ε�
	// Ư���� �Լ�
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

