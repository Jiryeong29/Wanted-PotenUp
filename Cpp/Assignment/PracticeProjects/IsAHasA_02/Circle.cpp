#include "Circle.h"
#include "Point.h"

#include <iostream>

Circle::Circle()
{
}

Circle::Circle(int x, int y, float radius)
	: radius(radius)
{
	point = new Point(x, y);
}

Circle::~Circle()
{
}
void Circle::ShowData()
{
	std::cout << "���� ��ǥ : (" <<  point->getX() << ", " << point->getY() << ")" << std::endl;
	std::cout << "������ : " << radius << std::endl;
	std::cout << "���� ���� : " << radius * radius * 3.14 << std::endl;
}
