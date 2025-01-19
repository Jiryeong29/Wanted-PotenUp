#include "PreCompiledHeader.h"

#include "Engine.h"
#include <Windows.h>
#include <iostream>

#include "Level/Level.h"
#include "Actor/Actor.h"
#include "time.h"

// ����ƽ ���� �ʱ�ȭ
Engine* Engine::instance = nullptr;
//quit ������ false�� �����Ͽ� ���� ������ ������� �ʵ��� �Ѵ�
// ������ �� ������ ��Ÿ���� �����͸� nullptr�� �ʱ�ȭ�Ѵ�
Engine::Engine()
    : quit(false), mainLevel(nullptr), screenSize(80, 25)
{

    //���� �õ� ����. ���� ���� �ø��� �ٸ� ���� ���� ����
    srand((unsigned int)time(nullptr));


    // �̱��� ��ü ���� engine ��ü�� ���� ����
    instance = this;

    // �⺻ Ÿ�� ������ �ӵ� ����
    SetTargetFrameRate(60.0f);


    // ȭ�� ���� �� ����� ���� �ʱ�ȭ.
    // 1. ���� ũ�� �Ҵ�.
    emtyStringBuffer = new char[(screenSize.x + 1) * screenSize.y + 1];


    //  ���� �����.
    memset(emtyStringBuffer, ' ', (screenSize.x + 1) * screenSize.y + 1);;


    // 2. �� �Ҵ�.
    for (int y = 0; y < screenSize.y; ++y)
    {
        //for (int x = 0; x < screenSize.x; ++x)
        //{
        //    // �ε��� ��� ���ϱ�.
        //    emtyStringBuffer[(y * (screenSize.x + 1)) + x] = ' ';
        //}

        // �� �� ���� ���� ���� �߰�.
        emtyStringBuffer[(y * (screenSize.x + 1)) + screenSize.x] = '\n';
    }
    // �������� �� ���� �߰�.
    emtyStringBuffer[((screenSize.x + 1) * screenSize.y)] = '\0';


    //�����.
#if _DEBUG
    char buffer[2048];
    strcpy_s(buffer, 2048, emtyStringBuffer);
#endif
}

Engine::~Engine()
{
    // ���� ���� �޸� ����
    if (mainLevel != nullptr)
    {
        delete mainLevel;
    }

    // Ŭ���� ���� ����.
    delete[] emtyStringBuffer;
}

void Engine::Run()
{
    //// ���� Ÿ�� ������ ����
    //unsigned long currentTime = timeGetTime();
    //unsigned long previousTime = 0;

    // CPU �ð� ���
    // �ý��� �ð� -> ���ػ� ī���� (10,000,000)
    // ���κ��忡 �ð谡 ����
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency); // �𸮾� �� ����Ƽ ���. ���ػ� Ÿ�̸��� ���ļ��� ������

    // ���� �ð� �� ���� �ð��� ���� ����
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time); // �𸮾� �� ����Ƽ ���.  ���� ������ Ÿ�̸� ���� ������

    // __int64 == int64_t
    int64_t currentTime = time.QuadPart; // *time.QuadPart ���� ������ Ÿ�̸� ���� ������
    int64_t previousTime = currentTime;// currentTime�� previousTime�� �����Ͽ� ���� ������ �� �ð� ��꿡 �����

    //// ������ ����
    //float targetFrameRate = 60.0f;

    //// �� ������ �ð� ���
    //float targetOneFrameTime = 1.0f / targetFrameRate;

    // Game-Loop
    while (true)
    {
        // ���� ����
        if (quit)
        {
            break;
        }

        // ���� ������ �ð� ����
        //time = timeGetTime();
        QueryPerformanceCounter(&time);
        currentTime = time.QuadPart;
        // ������ �ð� ���
        float deltaTime = static_cast<float>(currentTime - previousTime) / static_cast<float>(frequency.QuadPart);

        //// �� ������ �ð� ���
        //float targetOneFrameTime = 1.0f / targetFrameRate;

        // ������ Ȯ��
        if (deltaTime >= targetOneFrameTime)
        {
            // �Է� ó�� (���� Ű�� ���� ���� Ȯ��)
            ProcessInput();

            // ������Ʈ ������ ���¿����� ������ ������Ʈ ó��
            if (shouldUpdate)
            {
                Update(deltaTime);
                Draw();
            }

            // Ű ���� ����
            SavePreviousKeyStates();

            // ���� ������ �ð� ����
            previousTime = currentTime;

            // ���� ���� (���� ��û�� ���͵� ����)
            if (mainLevel)
            {
                mainLevel->ProcessAddedAndDestroyedActor();
            }

            // ������ Ȱ��ȭ
            shouldUpdate = true;
        }

        //Sleep(1);
    }
}

void Engine::LoadLevel(Level* newLevel)
{
    // ���� ������ �ִٸ� ���� �� ��ü

    // ���� ���� ����
    mainLevel = newLevel;
}

void Engine::AddActor(Actor* newActor)
{
    // ���� ó��
    if (mainLevel == nullptr)
    {
        return;
    }

    // ������ ���� �߰�
    shouldUpdate = false;
    mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
    // ���� ó��
    if (mainLevel == nullptr)
    {
        return;
    }

    // ������ ���� ����
    shouldUpdate = false;
    targetActor->Destroy();
}

void Engine::SetCursorType(CursorType cursorType)
{
    // 1. Ŀ�� �Ӽ� ����ü ����
    CONSOLE_CURSOR_INFO info = { };

    // Ÿ�� ���� ����ü �� ����
    switch (cursorType)
    {
    case CursorType::NoCursor:
        info.dwSize = 1; // 0���� �ع����� visible�� �����ϰ�, ������ ������
        info.bVisible = FALSE;
        break;

    case CursorType::SolidCursor:
        info.dwSize = 100;
        info.bVisible = TRUE;
        break;

    case CursorType::NormalCursor:
        info.dwSize = 20;
        info.bVisible = TRUE;
        break;
    }

    // 2. ����
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Engine::SetCursorPosition(const Vector2& position)
{
    SetCursorPosition(position.x, position.y);
}

void Engine::SetCursorPosition(int x, int y)
{
    //ǥ�� ���(�ܼ�)�� ���� �ڵ��� �����ɴϴ�.
    //**STD_OUTPUT_HANDLE**�� ǥ�� ��� ��Ʈ��(�ܼ�)�� ��Ÿ���ϴ�.
    // static���� ����Ǿ�, �ڵ��� �Լ� ȣ�� �� �Ź� ���� �������� �ʰ� �� ���� �������� �մϴ�.
    static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { static_cast<short>(x), static_cast<short>(y) };
    SetConsoleCursorPosition(handle, coord);
    //ù ��° ���ڴ� �ܼ� ��� �ڵ�(handle).
    //�� ��° ���ڴ� Ŀ�� ��ġ(coord).
}

void Engine::SetTargetFrameRate(float targetFrameRate)
{
    this->targetFrameRate = targetFrameRate;
    targetOneFrameTime = 1.0f / targetFrameRate;
}

bool Engine::GetKey(int key)
{
    return keyState[key].isKeyDown;
}

bool Engine::GetKeyDown(int key)
{
    return keyState[key].isKeyDown && !keyState[key].wasKeyDown;
}

bool Engine::GetKeyUp(int key)
{
    return !keyState[key].isKeyDown && keyState[key].wasKeyDown;
}

void Engine::QuitGame()
{
    Engine::Get().
        quit = true;
}

Engine& Engine::Get()
{
    // �̱��� ��ü ��ȯ
    return *instance;
}

void Engine::ProcessInput()
{
    //keyState �迭�� i��° ��ҿ� �ش� Ű�� ���� �ִ����� ����մϴ�.
    for (int i = 0; i < 255; ++i)
    {
        keyState[i].isKeyDown = (GetAsyncKeyState(i) & 0x8000) ? true : false;
    }
}

void Engine::Update(float deltaTime)
{
    // ���� ������Ʈ
    if (mainLevel != nullptr)
    {
        mainLevel->Update(deltaTime);
    }
}

void Engine::Clear()
{
    // ȭ���� (0, 0)���� �̵�
    SetCursorPosition(0, 0);

    // ȭ�� �����
    std::cout << emtyStringBuffer;

    /*int height = 25;
    for (int i = 0; i < height; ++i)
    {
        Log("                              \n");
    }*/

    // ȭ���� (0, 0)���� �̵�
    SetCursorPosition(0, 0);
}

void Engine::Draw()
{
    // ȭ�� �����
    Clear();

    // ���� �׸���
    if (mainLevel != nullptr)
    {
        mainLevel->Draw();
    }

}

void Engine::SavePreviousKeyStates()
{
    for (int i = 0; i < 255; ++i)
    {
        keyState[i].wasKeyDown = keyState[i].isKeyDown;
    }
}
