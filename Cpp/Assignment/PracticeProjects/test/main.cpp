#include <iostream>

class Graphics
{
public:
	virtual void Draw() = 0;    // ���� ���� �Լ�.
};

class Line : public Graphics
{
public:
	virtual void Draw() override
	{
		std::cout << "Draw a line\n";
	}
};

class Circle : public Graphics
{
public:
	virtual void Draw() override
	{
		std::cout << "Draw a circle\n";
	}
};

class Rectangle : public Graphics
{
public:
	virtual void Draw() override
	{
		std::cout << "Draw a rectangle\n";
	}
};

int main()
{
	//Graphics* graphics = new Graphics();    // ����.
	Graphics* line = new Line();
	Graphics* circle = new Circle();
	Graphics* rect = new Rectangle();

	line->Draw();
	circle->Draw();
	rect->Draw();

	delete line;
	delete circle;
	delete rect;
}