#include "PreCompiledHeader.h"

#include "TestLevel.h"
#include "Actor/Actor.h"
#include "Engine/Engine.h"
#include <Windows.h>
#include <Iostream>

#include "Core.h"

TestLevel::TestLevel()
{
	// 테스트로 액터 추가.
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float deltaTime)
{
	// 입력 확인.
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
	std::cout << "DeltaTime: " << deltaTime << ", Fps: " << (1.0f / deltaTime) << "\n";
}
