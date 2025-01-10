#include "Game.h"
//#include"Engine/Engine.h"

Game::Game()
	: Engine()
{
	// 커서 안 보이게 설정
	SetCursorType(CursorType::NoCursor);
}

Game::~Game()
{
}
