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
	std::cout << "증심 좌표 : (" <<  point->getX() << ", " << point->getY() << ")" << std::endl;
	std::cout << "반지름 : " << radius << std::endl;
	std::cout << "원의 넓이 : " << radius * radius * 3.14 << std::endl;
}
