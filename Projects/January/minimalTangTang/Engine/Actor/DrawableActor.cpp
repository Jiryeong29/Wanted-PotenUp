#include "PreCompiledHeader.h"
#include "DrawableActor.h"
#include "Engine/Engine.h"
#include <cstring>      // strlen, strcpy_s
#include <sstream>      // std::stringstream
#include <string>       // std::string
#include <iostream>     // std::cout (����� �� ��� ����)

DrawableActor::DrawableActor(const char* image)
	: Actor()/*, image(image)*/
{
	// ���� ���� ���ڿ� ����.
	auto length = strlen(image) + 1;
	this->image = new char[length];
	strcpy_s(this->image, length, image);
	// ���� ���� �� ���� �� ������ ���̸� Ž��
	int tmpX = 0;

	for (int i = 0; i < length;++i)
	{
		if (image[i] == '\n')
		{
			if (maxX <= tmpX)
			{
				maxX = tmpX;
			}
			++maxY;
			tmpX = 0;
		}
		else
		{
			++tmpX;
		}
	}

	if (maxY == 0)
	{
		maxX = (int)strlen(image);
	}
	else
	{
		--maxY;
	}

	maxX--;
	// �ʺ� ����.
	width = (int)strlen(image);
}

DrawableActor::~DrawableActor()
{
	delete[] image;
}

void DrawableActor::Draw()
{
	Super::Draw();

	// ���� ����.
	//Engine::Get().SetColor(color);

	// �׸���.
	// 1�ܰ�: �ܼ� ��ǥ �ű��.
	//Engine::Get().SetCursorPosition(position);

	// 2�ܰ�: �׸��� (�ܼ� ���).
	//Log(image);
	Super::Draw();


	// �̹��� �� ������ ������
	std::stringstream ss(image);
	std::string line;

	int lineOffset = 0;

	// �� ���� x, y ��ǥ�� �°� ���
	while (std::getline(ss, line, '\n'))
	{
		// ���� �� ���
		
		Engine::Get().Draw(Vector2(position.x, position.y + lineOffset), line.c_str(), Color::Red);
		++lineOffset; // ���� �ٷ� �̵�
	}
	// ���� ����.
	//Engine::Get().SetColor(Color::White);
}

void DrawableActor::SetPosition(const Vector2& newPosition)
{
	//// ������ ��ġ�� ���� �����.
	//Engine::Get().SetCursorPosition(position);
	//Log(" ");

	// ��ġ�� ���� �ű��.
	Super::SetPosition(newPosition);
}

bool DrawableActor::Intersect(const DrawableActor& other)
{
	// AABB(Axis Aligned Bounding Box).

	// �� x��ǥ �ּ�/�ִ�.
	int min = position.x;
	int max = position.x + width;

	// �ٸ� ������ x��ǥ �ּ�/�ִ�.
	int otherMin = other.position.x;
	int otherMax = other.position.x + other.width;

	// �ٸ� ������ ���� �� ��ġ�� �� ������ �� ��ġ�� ����� �浹 ����.
	if (otherMin > max)
	{
		return false;
	}

	// �ٸ� ������ ������ �� ��ġ�� �� ���� �� ��ġ���� ������ �浹 ����.
	if (otherMax < min)
	{
		return false;
	}

	// ���� �� ��찡 �ƴ϶�� (x��ǥ�� ���� ��ħ), y��ġ ��.
	return position.y == other.position.y;
}

bool DrawableActor::aabb(const DrawableActor& other)
{// AABB (Axis Alighend Bounding Box).

 	int minX = position.x;
	int maxX = position.x + this->maxX;

	// �� y��ǥ �ּ�/�ִ�
	int minY = position.y;
	int maxY = position.y + this->maxY;

	// �ٸ� ������ x, y �ּ�/�ִ�
	int otherMinX = other.position.x;
	int otherMaxX = other.position.x + other.maxX;
	int otherMinY = other.position.y;
	int otherMaxY = other.position.y + other.maxY;

	// �浹 ���� Ȯ��
 	return !(maxX < otherMinX || minX > otherMaxX ||
		maxY < otherMinY || minY > otherMaxY);
}
