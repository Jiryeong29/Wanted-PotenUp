#include "Circle.h"
#include "Point.h"
#include <iostream>
#define PI 3.14
Circle::Circle(int x, int y, float radis) : Point(x, y) , radius(radis)
{

}

Circle::~Circle()
{
}
void Circle::ShowData()
{
	std::cout << "중심 좌표 : ( ";
	std::cout << "반지름 : " << radius * radius * PI << std::endl;

}