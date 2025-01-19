#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);

	~Point();

	int getX() const { return x; }
	int getY() const { return y; }
private:
	int x;
	int y;
};

