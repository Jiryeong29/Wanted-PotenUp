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
	std::cout << "�߽� ��ǥ : ( ";
	std::cout << "������ : " << radius * radius * PI << std::endl;

}