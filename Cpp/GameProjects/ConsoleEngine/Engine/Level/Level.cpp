#include "PreCompiledHeader.h"
#include "Level.h"
#include "Actor/Actor.h"
//#include <iostream>

Level::Level()
{
}

Level::~Level()
{
    //메모리 해제
    //for (int ix = 0; ix < actors.Size(); ++ix)
    //{
    //    //액터 삭제
    //    delete actors[ix];
    //}

    // 메모리 해제.
    for (Actor* actor : actors)
    {
        delete actor;
    }

    //동적 배열 해제
    //delete[] actors;
}

void Level::AddActor(Actor* newActor)
{
    actors.PushBack(newActor);
}

void Level::Update(float deltaTime)
{
    //레벨에 포함된 액터를 순회하면서 Update 함수 호출
    /*for (int ix = 0; ix < actors.Size();++ix)
    {
        actors[ix]->Update(deltaTime);
    }*/
    for ( Actor* actor : actors)
    {
        actor->Update(deltaTime);
    }
}

void Level::Draw()
{
    //레벨에 포함된 액터를 순회하면서 Draw 함수 호출
    /*for (int ix = 0; ix < actors.Size();++ix)
    {
        actors[ix]->Draw();
    }*/
    for (Actor* actor : actors)
    {
        actor->Draw();
    }
}

