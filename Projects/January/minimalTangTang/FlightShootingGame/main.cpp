#include "Game/Game.h"
#include "Game/TestLevel.h"
//#include "Level/MainMenuLevel.h"
#include "Engine/Engine.h"
#include <iostream>

int main()
{
	//system("mode con cols=500 lines=500 | title �����"); // 
	//printf(" @@\n@..@\n @@\n");
	//std::cout << std::endl << std::endl;
	//printf(" @@\n@^^@\n @@\n");

	//std::cout << std::endl << std::endl;
	//printf(" **\n*^^*\n **\n");

	//char name[] = " **\n*^^*\n **\n";
	//size_t length = strlen(name);

	//std::cout << length;
	////char *name1 = new char[]

	//�޸� ���� Ȯ��.
	CheckMemoryLeak();

	Game game;
	game.LoadLevel(new TestLevel());
	game.Run();

}