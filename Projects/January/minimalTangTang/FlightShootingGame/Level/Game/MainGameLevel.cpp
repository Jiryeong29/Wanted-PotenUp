#include "MainGameLevel.h"
#include "Game/Game.h"
MainGameLevel::MainGameLevel()
{
}

MainGameLevel::~MainGameLevel()
{
}

void MainGameLevel::Draw()
{
}

void MainGameLevel::Update(float daltaTime)
{

	// ����Ű.
	if (Game::Get().GetKeyDown(VK_ESCAPE))
	{

		Game::Get().ChangeLevel(Game::Get().GetPauseMenuLevel());
	}

}
