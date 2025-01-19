#include "PreCompiledHeader.h"

#include "Engine.h"
#include <Windows.h>
#include <iostream>

#include "Level/Level.h"
#include "Actor/Actor.h"
#include "time.h"

// 스태틱 변수 초기화
Engine* Engine::instance = nullptr;
//quit 변수를 false로 설정하여 게임 루프가 종료되지 않도록 한다
// 게임의 주 레벨을 나타내는 포인터를 nullptr로 초기화한다
Engine::Engine()
    : quit(false), mainLevel(nullptr), screenSize(80, 25)
{

    //랜덤 시드 설정. 게임 실행 시마다 다른 랜덤 값을 생성
    srand((unsigned int)time(nullptr));


    // 싱글톤 객체 설정 engine 객체의 전역 접근
    instance = this;

    // 기본 타겟 프레임 속도 설정
    SetTargetFrameRate(60.0f);


    // 화면 지울 때 사용할 버퍼 초기화.
    // 1. 버퍼 크기 할당.
    emtyStringBuffer = new char[(screenSize.x + 1) * screenSize.y + 1];


    //  버퍼 덮어쓰기.
    memset(emtyStringBuffer, ' ', (screenSize.x + 1) * screenSize.y + 1);;


    // 2. 값 할당.
    for (int y = 0; y < screenSize.y; ++y)
    {
        //for (int x = 0; x < screenSize.x; ++x)
        //{
        //    // 인덱스 계산 잘하기.
        //    emtyStringBuffer[(y * (screenSize.x + 1)) + x] = ' ';
        //}

        // 각 줄 끝에 개행 문자 추가.
        emtyStringBuffer[(y * (screenSize.x + 1)) + screenSize.x] = '\n';
    }
    // 마지막에 널 문자 추가.
    emtyStringBuffer[((screenSize.x + 1) * screenSize.y)] = '\0';


    //디버깅.
#if _DEBUG
    char buffer[2048];
    strcpy_s(buffer, 2048, emtyStringBuffer);
#endif
}

Engine::~Engine()
{
    // 메인 레벨 메모리 해제
    if (mainLevel != nullptr)
    {
        delete mainLevel;
    }

    // 클리어 버퍼 삭제.
    delete[] emtyStringBuffer;
}

void Engine::Run()
{
    //// 시작 타임 스탬프 저장
    //unsigned long currentTime = timeGetTime();
    //unsigned long previousTime = 0;

    // CPU 시계 사용
    // 시스템 시계 -> 고해상도 카운터 (10,000,000)
    // 메인보드에 시계가 있음
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency); // 언리얼 및 유니티 사용. 고해상도 타이머의 주파수를 가져옴

    // 시작 시간 및 이전 시간을 위한 변수
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time); // 언리얼 및 유니티 사용.  현재 시점의 타이머 값을 가져옴

    // __int64 == int64_t
    int64_t currentTime = time.QuadPart; // *time.QuadPart 현재 시점의 타이머 값을 가져옴
    int64_t previousTime = currentTime;// currentTime과 previousTime에 저장하여 이후 프레임 간 시간 계산에 사용한

    //// 프레임 제한
    //float targetFrameRate = 60.0f;

    //// 한 프레임 시간 계산
    //float targetOneFrameTime = 1.0f / targetFrameRate;

    // Game-Loop
    while (true)
    {
        // 종료 조건
        if (quit)
        {
            break;
        }

        // 현재 프레임 시간 저장
        //time = timeGetTime();
        QueryPerformanceCounter(&time);
        currentTime = time.QuadPart;
        // 프레임 시간 계산
        float deltaTime = static_cast<float>(currentTime - previousTime) / static_cast<float>(frequency.QuadPart);

        //// 한 프레임 시간 계산
        //float targetOneFrameTime = 1.0f / targetFrameRate;

        // 프레임 확인
        if (deltaTime >= targetOneFrameTime)
        {
            // 입력 처리 (현재 키의 눌림 상태 확인)
            ProcessInput();

            // 업데이트 가능한 상태에서만 프레임 업데이트 처리
            if (shouldUpdate)
            {
                Update(deltaTime);
                Draw();
            }

            // 키 상태 저장
            SavePreviousKeyStates();

            // 이전 프레임 시간 저장
            previousTime = currentTime;

            // 액터 정리 (삭제 요청된 액터들 정리)
            if (mainLevel)
            {
                mainLevel->ProcessAddedAndDestroyedActor();
            }

            // 프레임 활성화
            shouldUpdate = true;
        }

        //Sleep(1);
    }
}

void Engine::LoadLevel(Level* newLevel)
{
    // 기존 레벨이 있다면 삭제 후 교체

    // 메인 레벨 설정
    mainLevel = newLevel;
}

void Engine::AddActor(Actor* newActor)
{
    // 예외 처리
    if (mainLevel == nullptr)
    {
        return;
    }

    // 레벨에 액터 추가
    shouldUpdate = false;
    mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
    // 예외 처리
    if (mainLevel == nullptr)
    {
        return;
    }

    // 레벨에 액터 제거
    shouldUpdate = false;
    targetActor->Destroy();
}

void Engine::SetCursorType(CursorType cursorType)
{
    // 1. 커서 속성 구조체 설정
    CONSOLE_CURSOR_INFO info = { };

    // 타입 별로 구조체 값 설정
    switch (cursorType)
    {
    case CursorType::NoCursor:
        info.dwSize = 1; // 0으로 해버리면 visible도 무시하고, 오히려 보여짐
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

    // 2. 설정
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Engine::SetCursorPosition(const Vector2& position)
{
    SetCursorPosition(position.x, position.y);
}

void Engine::SetCursorPosition(int x, int y)
{
    //표준 출력(콘솔)에 대한 핸들을 가져옵니다.
    //**STD_OUTPUT_HANDLE**은 표준 출력 스트림(콘솔)을 나타냅니다.
    // static으로 선언되어, 핸들을 함수 호출 시 매번 새로 생성하지 않고 한 번만 가져오게 합니다.
    static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { static_cast<short>(x), static_cast<short>(y) };
    SetConsoleCursorPosition(handle, coord);
    //첫 번째 인자는 콘솔 출력 핸들(handle).
    //두 번째 인자는 커서 위치(coord).
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
    // 싱글톤 객체 반환
    return *instance;
}

void Engine::ProcessInput()
{
    //keyState 배열의 i번째 요소에 해당 키가 눌려 있는지를 기록합니다.
    for (int i = 0; i < 255; ++i)
    {
        keyState[i].isKeyDown = (GetAsyncKeyState(i) & 0x8000) ? true : false;
    }
}

void Engine::Update(float deltaTime)
{
    // 레벨 업데이트
    if (mainLevel != nullptr)
    {
        mainLevel->Update(deltaTime);
    }
}

void Engine::Clear()
{
    // 화면의 (0, 0)으로 이동
    SetCursorPosition(0, 0);

    // 화면 지우기
    std::cout << emtyStringBuffer;

    /*int height = 25;
    for (int i = 0; i < height; ++i)
    {
        Log("                              \n");
    }*/

    // 화면의 (0, 0)으로 이동
    SetCursorPosition(0, 0);
}

void Engine::Draw()
{
    // 화면 지우기
    Clear();

    // 레벨 그리기
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
