#include "PreCompiledHeader.h"

#include "TestLevel.h"
#include "Actor/Actor.h"
#include "Engine/Engine.h"
#include <Windows.h>
#include <Iostream>

#include "Core.h"

TestLevel::TestLevel()
{
	// �׽�Ʈ�� ���� �߰�.
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
	// �Է� Ȯ��.
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
	std::cout << "DeltaTime: " << deltaTime << ", Fps: " << (1.0f / deltaTime) << "\n";
}
