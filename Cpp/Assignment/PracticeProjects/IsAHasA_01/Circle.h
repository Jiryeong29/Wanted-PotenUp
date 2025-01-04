#pragma once
#include "Point.h"
class Circle : public Point
{
public:
	Circle();
	Circle(int x, int y, float radius);

	~Circle();

	void ShowData();
private:
	float radius;
};

