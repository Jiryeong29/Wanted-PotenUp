#include "Game/Game.h"
#include "Game/TestLevel.h"

#include <iostream>

int main()
{
	//�޸� ���� Ȯ��.
	CheckMemoryLeak();

	Game game;
	game.LoadLevel(new TestLevel());
	game.Run();

}