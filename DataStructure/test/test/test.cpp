#include <iostream>
using namespace std;

class Vector2
{
    int x, y;
public:
    Vector2(int x, int y) : x(x), y(y) {}
    Vector2(const Vector2& other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    void Display() { cout << "(" << x << ", " << y << ")\n"; }
    /*friend Vector2 operator+(const Vector2& l, const Vector2& r)  {
        return   Vector2((l.x + r.x), (l.y+ r.y));
    }*/
    Vector2 operator+(const Vector2& r) {
        x += r.x;
        y +=  r.y;
        return *this;
    }
    /* Vector2 operator+( Vector2& l,  Vector2& r)  {
        l.x += r.x;
        l.y += r.y;
        return l;
    }*/
};

int main()
{
    Vector2 v1(1, 2), v2(3, 4);
    Vector2 v3 = v1 + v2;
    v3.Display(); // (4, 6)
}