#pragma once

#include "Engine/Engine.h"

class Game : public Engine
{
public:
	Game();
	~Game();
	// 메뉴씬 - 데모씬 전환 함수.
	void ToggleMenu();

	// 싱글톤 접근 함수.
	static Game& Get() { 
		// Lazy Singleton Pattern.
		//static Game* instance = new Game();  // 실용적이나 게임에서는 잘 사용x, 소멸시킬때가 애매

		return *instance; }

private:
	// 메뉴를 보여주고 있는 지를 나타내느 변수.
	bool showMenu = false;

	// 씬 변수.
	Level* menuLevel = nullptr;
	Level* backLevel = nullptr;

	// 싱글톤 구현 객체.
	static Game* instance;

};