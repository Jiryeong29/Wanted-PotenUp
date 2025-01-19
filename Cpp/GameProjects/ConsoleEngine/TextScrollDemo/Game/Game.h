#pragma once

#include "Engine/Engine.h"

class Game : public Engine
{
public:
	Game();
	~Game();
	// �޴��� - ����� ��ȯ �Լ�.
	void ToggleMenu();

	// �̱��� ���� �Լ�.
	static Game& Get() { 
		// Lazy Singleton Pattern.
		//static Game* instance = new Game();  // �ǿ����̳� ���ӿ����� �� ���x, �Ҹ��ų���� �ָ�

		return *instance; }

private:
	// �޴��� �����ְ� �ִ� ���� ��Ÿ���� ����.
	bool showMenu = false;

	// �� ����.
	Level* menuLevel = nullptr;
	Level* backLevel = nullptr;

	// �̱��� ���� ��ü.
	static Game* instance;

};