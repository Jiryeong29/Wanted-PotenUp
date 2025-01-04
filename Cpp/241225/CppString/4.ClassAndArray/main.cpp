#include <iostream>

class Player
{
public:
	Player()
		: x(0), y(0)
	{
		std::cout << "Player contructor call\n";
	}

	Player(int inX, int inY)
		: x(inX), y(inY)
	{
	}

	void ShowPosition()
	{
		std::cout << "x: " << x << "  " << "y: " << y << "\n";
	}

	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(const int inX) { x = inX; }
	void SetY(const int inY) { y = inY; }


private:
	int x;
	int y;
};

int main()
{
	Player* players[5];

	for (int ix = 0; ix < 5; ++ix)
	{
		players[ix] = new Player(ix * 2, ix * 3);	// new 연산자를 사용한 객체 동적 생성.
	}

	for (Player* player : players)
	{
		player->ShowPosition();
	}

}