#include "PreCompiledHeader.h"

#include "Engine.h"
#include <Windows.h>
#include <iostream>
#include <Level/Level.h>
// ����ƽ ���� �ʱ�ȭ.
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr)
{
	// �̱��� ��ü ����.
	instance = this;

}

Engine::~Engine()
{
	// ���� ���� �޸� ����.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
	}
}

void Engine::Run()
{

	//// ���� Ÿ�� ������ ����.
	// timeGetTime �Լ��� �и�������(1/1000��) ����.
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTime = 0;
	
	// CPU �ð� ���.
	// �ý��� �ð� -> ���ػ� ī����.(10000000)
	// ���κ��忡 �ð谡 ����.
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	std::cout << "Frequency: " << frequency.QuadPart << '\n';

	// ���� �ð� �� ���� �ð��� ���� ����
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	
	//int64_t�� __int64�� ����.
	int64_t currentTime = time.QuadPart;
	int64_t previousTime = 0;


	// ������ ����.
	float targetFrameRate = 60.0f;

	// �� ������ �ð� ���.
	float targetOneFrameTime = 1.0f / targetFrameRate;


	// Game_Loop.
	while (true) {

		// ���� ����.
		if (quit)
		{
			break;
		}
		// ���� ������ �ð� ����.
		//currentTime = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		// ������ �ð� ���.
		float deltaTime = static_cast<float>(currentTime - previousTime)/
			static_cast<float>(frequency.QuadPart);


		// ������ Ȯ��.
		if (deltaTime >= targetOneFrameTime)
		{	
			// �Է� ó�� (���� Ű�� ���� ���� Ȯ��).
			ProcessInput();

			Update(deltaTime);
			Draw();
			// Ű ���� ����.
			SavePreviousKeyState();
			
			// ���� ������ �ð� ����
			previousTime = currentTime;
		}

		//ProcessInput();
		//Update(deltaTime);
		//Draw();

		//// ���� ������ �ð� ����
		//previousTime = currentTime;
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	// ���� ������ �մٸ� ���� �� ��ü


	// ���� ���� ����.
	mainLevel = newLevel;
}

bool Engine::GetKey(int key)
{
	return keyState[key].isKeyDown;
}

bool Engine::GetKeyDown(int key)
{
	return keyState[key].isKeyDown && !keyState[key].wasKeyDown;
}

bool Engine::GetKeyUP(int key)
{
	return !keyState[key].isKeyDown && keyState[key].wasKeyDown;
}

void Engine::QuitGame()
{
	Engine::Get().
	// ���� �÷��� ����
	quit = true;
}

Engine& Engine::Get()
{
	// �̱��� ��ü ��ȯ
	return *instance;
}

void Engine::ProcessInput()
{
	for (int ix = 0; ix < 255; ++ix)
	{
		keyState[ix].isKeyDown = (GetAsyncKeyState(ix) & 0x8000) ? true : false;
	}
}

void Engine::Update(float deltaTime)
{
	//// ESCŰ�� ���� ����
	if (GetKeyDown(VK_ESCAPE))
	{
		QuitGame();
	}

	// ���� ������Ʈ
	if (mainLevel != nullptr)
	{
		mainLevel->Update(deltaTime);
	}
	//std::cout << "DeltaTime: " << deltaTime << ", Fps: " << (1.0f / deltaTime) << "\n";
}

void Engine::Draw()
{
	// ���� �׸���.
	if (mainLevel != nullptr)
	{
		mainLevel->Draw();
	}
}

void Engine::SavePreviousKeyState()
{
	for (int ix = 0; ix < 255; ++ix)
	{
		keyState[ix].wasKeyDown = keyState[ix].isKeyDown;
	}
}
