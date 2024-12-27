#pragma once

#include "Point.h"

class Circle :public Point
{
public:
	
	Circle(int x, int y, float cent);
	~Circle();

	void ShowData();

private:
	Point p;
};

