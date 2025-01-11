#include "TextScrollActor.h"
#include "Engine/Engine.h"

TextScrollActor::TextScrollActor(const char* message)
{
	length = (int)strlen(message);

	string = new char[length + 1];
	strcpy_s(string, length + 1, message);

	Engine::Get().SetCursorType(CursorType::NoCursor);
}

TextScrollActor::~TextScrollActor()
{
	delete[] string;
}

void TextScrollActor::Update(float deltatTime)
{
	if(Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}


	elapsedTime += deltatTime;
	// 시간이 모두 경과 했는지 확인.
	if (elapsedTime < deltatTime)
	{
		return;
	}
	// 시간이 경과했으면 다음 계산을 위해 초기화
	elapsedTime = 0.0f;
	// 화면에 그릴 문자열의 시작 인덱스
	index = (index + 1) % length;
}

void TextScrollActor::Draw()
{
	// 임시 문자열 버퍼.
	char* temp = new char[printWidth + 1];
	int tempIndex = index;

	for (int ix = 0;ix < printWidth; ++ix)
	{
		temp[ix] = string[tempIndex];
		tempIndex = (tempIndex + 1) % length;
	}
	temp[printWidth] = '\0';
	Log(temp);

	delete[] temp;
	Engine::Get().SetCursorPosition(0, 0);

}
