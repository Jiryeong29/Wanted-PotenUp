#include "PreCompiledHeader.h"
#include "Vector2.h"

Vector2::Vector2(int x, int y)
{
}

Vector2 Vector2::operator+(const Vector2& other)
{
    return Vector2(x+other.x , y+other.y);
}

Vector2 Vector2::operator-(const Vector2& other)
{
    return Vector2(x - other.x, y - other.y);
}

bool Vector2::operator==(const Vector2& other)
{
    return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2& other)
{
    //return x != other.x || y != other.y;
    return !(*this == other);
}
