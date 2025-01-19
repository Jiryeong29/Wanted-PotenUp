#include "Game/Game.h"
#include "Game/TestLevel.h"

#include <iostream>

int main()
{
	Game game;
	game.LoadLevel(new TestLevel());
	game.Run();

}