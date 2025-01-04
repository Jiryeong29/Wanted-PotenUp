#pragma once
class Point;

class Circle
{
public:
	Circle();
	Circle(int x, int y, float radius);

	~Circle();

	void ShowData();
private:
	Point* point;
	float radius;
};

