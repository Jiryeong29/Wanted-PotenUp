#include "Game/Game.h"
#include "Game/TestLevel.h"

#include <iostream>

int main()
{
	//메모리 누수 확인.
	CheckMemoryLeak();

	Game game;
	game.LoadLevel(new TestLevel());
	game.Run();

}