#include "Circle.h"

#include <iostream>
Circle::Circle()
{
}

Circle::Circle(int x, int y, float radius)
	: Point(x, y), radius(radius)
{
}

Circle::~Circle()
{
}
void Circle::ShowData()
{
	std::cout << "���� ��ǥ : (" << x << ", " << y << ")" << std::endl;
	std::cout << "������ : "<<radius << std::endl;
	std::cout << "���� ���� : "<<radius*radius*3.14 << std::endl;
}
